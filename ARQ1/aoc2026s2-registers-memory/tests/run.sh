cd tests
echo "Testando a função..." 
iverilog -g2012 -o tb ../*.sv test.sv
rm -f $1.out
./tb | grep -v '$finish called' > test.out

if awk '
    /\/\*/ { in_comment=1 }
    /\*\// { in_comment=0; next }
    in_comment { next }
    /\/\// { sub(/\/\/.*/, "") }
    { code = code $0 "\n" }
    END { if (code ~ /@/) exit 0; else exit 1 }
' ../top.sv; then
    echo "Modo incorreto: você não pode usar Verilog comportamental."
    exit 1
else
    if diff $1.out $1.ok >/dev/null; then
        echo "OK"
    else
        echo "ERRO: saída incorreta"
        echo "ESPERADA:"
        cat $1.ok
        echo "OBTIDA:"
        cat $1.out
        exit 1
    fi
fi
