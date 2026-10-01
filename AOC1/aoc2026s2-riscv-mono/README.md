# Implementação de um RISC-V monociclo

O [código fornecido a você](riscvmono.sv) nesta simulação é uma implementação monociclo do RISC-V, adaptada do código multiciclo de Bruno Levy [^1]. Ele roda, por sua vez, o [programa adaptado do LightRISCV](fibo.asm) [^2] para gravar na memória de dados os primeiros números da sequência de Fibonacci até o limite de 32 bits. 

Para executar cada instrução em um único ciclo de *clock*, foi preciso modificar o esquema de *von Neumann* (dados e instruções em uma única memória) para o de *Harvard*, que possui memórias separadas para cada coisa.

O código fornecido está praticamente completo, você só precisa pensar nas perguntas abaixo para fornecer os valores corretos nas atribuições faltantes: 

```verilog
  assign memwrite =     // quando se deve escrever na memória?
  assign addr =         // de onde vem o endereço de acesso a ela?
  assign writedata =    // de onde vem o dado que será escrito?

  wire        writeBackEn =   // quando se deve escrever em registradores?
  wire [31:0] writeBackData = // de onde vem o dado que será escrito?
  wire [31:0] aluIn1 =        // qual é o primeiro operando da ula?
  wire [31:0] aluIn2 =        // qual é o segundo operando da ula?
```

Algumas delas recebem um único sinal, outras precisam de uma função lógica entre alguns ou de operadores ternários para decidir entre duas ou mais opções **dependendo do tipo de instrução**. Use o restante do código que já está pronto para obter os valores necessários e **completar estas sete linhas**. Você não precisa alterar mais nada além delas, mas fique à vontade se quiser propor algo diferente do que lhe foi dado. 

Nesta simulação, ao invés de olhar para a saída da simulação e comparar com a saída esperada, optou-se por salvar o conteúdo final da memória após a execução. Assim, você pode descomentar e usar livremente o `$monitor` que está no [test bench](tests/testbench.sv) para depurar o seu código. Há também uma opção comentada para salvar o conteúdo do banco de registradores que pode ajudar na depuração do código. 

## References
[^1]: [From Blinker to RISC-V](https://github.com/BrunoLevy/learn-fpga/blob/master/FemtoRV/TUTORIALS/FROM_BLINKER_TO_RISCV/)
[^2]: [LightRISCV](https://github.com/menotti/LightRISCV)
