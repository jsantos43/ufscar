#!/bin/sh
set -eu

cd "$(dirname "$0")"
tests_dir=$(pwd)

if [ "$#" -eq 0 ]; then
    set -- add sub and or xor slt sltu sll srl sra
fi

status=0
for name in "$@"; do
    case "$name" in
        add|sub|and|or|xor|slt|sltu|sll|srl|sra)
            top=alu_tb
            bench="$tests_dir/alu_tb.v"
            ;;
        *)
            echo "ERRO: teste desconhecido: $name"
            exit 1
            ;;
    esac

    vectors="$tests_dir/vectors/$name.tv"
    expected="$tests_dir/expected/$name.ok"
    output="$tests_dir/output/$name"
    echo "Testando $name..."
    if [ ! -s "$vectors" ] || [ ! -s "$expected" ]; then
        echo "ERRO: arquivo de referência ausente ou vazio para $name"
        status=1
        continue
    fi
    # Cada linha nao vazia e sem comentario representa um vetor.
    count=$(awk 'NF && $1 !~ /^\/\// {n++} END {print n+0}' "$vectors")
    if [ "$count" -eq 0 ]; then
        echo "ERRO: nenhum vetor para $name"
        status=1
        continue
    fi
    mkdir -p "$output"
    if ! iverilog -g2012 -s "$top" -P "$top.COUNT=$count" -o "$output/tb" \
        ../main.sv ../ula.sv \
        ../components/full_adder.sv ../components/addern.sv ../components/comparator.sv \
        ../components/mux.sv ../components/mux4to1.sv \
        ../components/shifter.sv ../components/shifter32.sv "$bench" \
        > "$output/compile.log" 2>&1; then
        echo "ERRO: compilação falhou"
        cat "$output/compile.log"
        status=1
        continue
    fi

    simulation_status=0
    (cd "$output" && vvp ./tb "+VECTORS=$vectors") \
        > "$output/simulation.log" 2>&1 || simulation_status=$?
    # Ignora somente a mensagem informativa de encerramento do Icarus.
    sed '/\$finish called/d' "$output/simulation.log" > "$output/test.out"

    if [ "$simulation_status" -eq 0 ] && diff "$output/test.out" "$expected" >/dev/null; then
        echo "OK"
    else
        echo "ERRO: saída incorreta"
        echo "ESPERADA:"
        cat "$expected"
        echo "OBTIDA:"
        cat "$output/test.out"
        status=1
    fi
done
exit "$status"
