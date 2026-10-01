cd tests
echo "Testando a processador..." 
iverilog -g2012 -o tb ../*.sv *.sv
rm -f fibo_data.out
./tb

if diff fibo_data.out fibo_data.ok >/dev/null; then
    echo "OK"
else
    echo "ERRO: saída incorreta"
    echo "ESPERADA:"
    head fibo_data.ok
    echo "OBTIDA:"
    head fibo_data.out
    exit 1
fi
