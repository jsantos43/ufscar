# Implementação de um RISC-V multiciclo

O [código fornecido a você](riscvmulti.sv) nesta simulação é uma implementação multiciclo do RISC-V, adaptada do código de Bruno Levy [^1]. Ele roda, por sua vez, o [programa adaptado do LightRISCV](fibo.asm) [^2] para gravar na memória de dados os primeiros números da sequência de Fibonacci até o limite de 32 bits. 

Agora usamos o esquema de *von Neumann* (dados e instruções em uma única memória). O código fornecido está praticamente completo, você só precisa pensar nas perguntas abaixo para fornecer os valores corretos nas atribuições faltantes: 

```verilog
    wire writeBackEn = // Quando se escreve no banco de registradores?
    wire [31:0] writeBackData = // O que se escreve no banco de registradores?
    wire [31:0] LoadStoreAddress = // Como se calcula o endereço de memória para loads e stores?
    assign Address = // Qual o endereço de memória a ser acessado? Alternar entre .text e .data dependendo do estado
    assign MemWrite = // Em que estado se escreve na memória?
    assign WriteData = // O que se escreve na memória?
```

Algumas delas recebem um único sinal, outras precisam de uma função lógica entre alguns ou de operadores ternários para decidir entre duas ou mais opções **dependendo do tipo de instrução**. Use o restante do código que já está pronto para obter os valores necessários e **completar esta meia dúzia de linhas**. Você não precisa alterar mais nada além delas, mas fique à vontade se quiser propor algo diferente do que lhe foi dado. 

Nesta simulação, ao invés de olhar para a saída da simulação e comparar com a saída esperada, optou-se por salvar o conteúdo final da memória após a execução. Assim, você pode descomentar e usar livremente o `$monitor` que está no [test bench](tests/testbench.sv) para depurar o seu código. Há também uma opção comentada para salvar o conteúdo do banco de registradores que pode ajudar na depuração do código. 

## References
[^1]: [From Blinker to RISC-V](https://github.com/BrunoLevy/learn-fpga/blob/master/FemtoRV/TUTORIALS/FROM_BLINKER_TO_RISCV/)
[^2]: [LightRISCV](https://github.com/menotti/LightRISCV)

