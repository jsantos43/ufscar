cd tests
echo "Testando a ULA..." 
iverilog -g2012 -o tb ../alu.v alu_tb.v
rm -f test.out
./tb | grep -v '$finish called' > test.out

if diff test.out test.ok >/dev/null; then
    echo "OK"
else
    echo "ERRO: saída incorreta"
    echo "ESPERADA:"
    cat test.ok
    echo "OBTIDA:"
    cat test.out
    exit 1
fi
