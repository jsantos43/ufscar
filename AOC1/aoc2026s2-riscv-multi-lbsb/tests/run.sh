cd tests
echo "Testando LB/SB..." 
rm -f a.out riscv.out riscv_data.out            # Limpa arquivos antigos      
make                                            # Simula o processador
./a.out                                         # Executa o teste       
grep 0x00000040 -A5 riscv.out > riscv_data.out  # Extrai a saída relevante (.data)

if diff riscv_data.out riscv_data.ok >/dev/null; then   # Compara com a saída esperada
    echo "OK"
else
    echo "ERRO: saída incorreta"
    echo "ESPERADA:"
    head riscv_data.ok
    echo "OBTIDA:"
    cat riscv_data.out
    exit 1
fi
