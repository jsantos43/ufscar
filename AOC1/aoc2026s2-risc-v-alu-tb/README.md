# Testando a ULA RISCV32I

Projeto de implementação e teste de uma **Unidade Lógica e Aritmética (ULA) de 32 bits** para as operações da arquitetura RISC-V RV32I, usando Verilog/SystemVerilog e componentes digitais simples.

## Objetivo

O objetivo é verificar se a ULA retorna os resultados corretos para **ADD, SUB, AND, OR, XOR, SLT, SLTU, SLL, SRL e SRA**. Cada operação possui seus próprios valores de referência e é executada em um grupo de testes separado.

A implementação também permite estudar como somadores, comparadores, deslocadores e multiplexadores trabalham juntos. O projeto contém a ULA e um módulo de decode; não implementa um processador completo com memória, banco de registradores e execução de programas.

## Organização do projeto

```text
.
├── main.sv                  # Decode da instrução e chamada da ULA
├── ula.sv                   # Conexão dos componentes e seleção do resultado
├── components/              # Componentes utilizados pelo circuito
│   ├── full_adder.sv
│   ├── addern.sv
│   ├── comparator.sv
│   ├── mux.sv
│   ├── mux4to1.sv
│   ├── shifter.sv
│   └── shifter32.sv
├── tests/
│   ├── alu_tb.v             # Testbench compartilhado pelas dez operações
│   ├── run.sh               # Compilação, simulação e comparação das saídas
│   ├── vectors/             # Entradas e resultados esperados: arquivos .tv
│   ├── expected/            # Logs de referência: arquivos .ok
│   └── output/              # Resultados gerados pela execução dos testes
├── run.sh                   # Executa os testes a partir da raiz
├── setup.sh                 # Instala o Icarus Verilog via apt
└── README.md
```

A pasta `tests/output/` é criada durante a execução e é ignorada pelo Git.

### Componentes utilizados

| Arquivo | Função no circuito |
| --- | --- |
| [full_adder.sv](components/full_adder.sv) | Soma dois bits e um carry de entrada, produzindo um bit de resultado e um carry de saída. |
| [addern.sv](components/addern.sv) | Encadeia somadores completos. Na ULA, trabalha com 32 bits, passando o carry de um bit para o seguinte. |
| [comparator.sv](components/comparator.sv) | Usa uma subtração construída com somadores completos para produzir sinais de igualdade, sinal, overflow e comparação sem sinal. |
| [shifter.sv](components/shifter.sv) | Deslocador simples com largura, distância e modo configuráveis. Pode manter o valor ou realizar o deslocamento. |
| [shifter32.sv](components/shifter32.sv) | Combina etapas de 1, 2, 4, 8 e 16 bits para realizar os deslocamentos de 32 bits. |
| [mux4to1.sv](components/mux4to1.sv) | Seleciona uma entre quatro entradas de um bit. A ULA usa esses componentes para selecionar os resultados bit a bit. |
| [mux.sv](components/mux.sv) | Seleciona entre duas entradas. É usado na escolha dos deslocamentos e do resultado final, além dos cálculos auxiliares do `main`. |

A soma e a subtração compartilham o mesmo `addern`. Para subtrair, a ULA inverte os bits do segundo operando e coloca 1 no carry de entrada, realizando `A + ~B + 1`.

As operações AND, OR e XOR são feitas bit a bit diretamente em `ula.sv`. A comparação com sinal utiliza os sinais de negativo e overflow do comparador; a comparação sem sinal utiliza o carry da subtração.

### Operações disponíveis

Na tabela, `A` e `B` representam os operandos de 32 bits, e `n` é a distância do deslocamento.

| Operação | Resultado | Versão com imediato |
| --- | --- | --- |
| **ADD** | Soma `A + B`. | ADDI |
| **SUB** | Subtração `A - B`. | Não há SUBI no RV32I. |
| **AND** | Cada bit vale 1 quando os dois bits correspondentes valem 1. | ANDI |
| **OR** | Cada bit vale 1 quando pelo menos um dos bits correspondentes vale 1. | ORI |
| **XOR** | Cada bit vale 1 quando os bits correspondentes são diferentes. | XORI |
| **SLT** | Retorna 1 se `A < B`, interpretando os valores com sinal; caso contrário, retorna 0. | SLTI |
| **SLTU** | Retorna 1 se `A < B`, interpretando os valores sem sinal; caso contrário, retorna 0. | SLTIU |
| **SLL** | Desloca `A` para a esquerda em `n` posições, preenchendo com zeros. | SLLI |
| **SRL** | Desloca `A` para a direita em `n` posições, preenchendo com zeros. | SRLI |
| **SRA** | Desloca `A` para a direita em `n` posições, repetindo o bit de sinal. | SRAI |

Somas e subtrações mantêm os 32 bits inferiores do resultado. Por exemplo, `0xffffffff + 1` retorna `0x00000000`. SLT e SLTU também retornam 32 bits, contendo apenas zero ou um.

Os deslocamentos usam somente os cinco bits inferiores de `B`, permitindo distâncias de 0 a 31. Por isso, uma distância fornecida como 32 equivale a 0, e 33 equivale a 1.

Um exemplo da diferença entre comparações: `0xffffffff` representa −1 com sinal, mas 4.294.967.295 sem sinal. Ao compará-lo com 1, SLT retorna 1 e SLTU retorna 0.

### Entradas e controles da ULA

| Sinal | Função |
| --- | --- |
| `SrcA`, `SrcB` | Operandos de 32 bits. |
| `aluOp` | Código de três bits que seleciona o grupo de operação. |
| `subtract` | Seleciona subtração quando a operação é ADD/SUB. |
| `arithmeticShift` | Seleciona o preenchimento com o bit de sinal no deslocamento à direita. |
| `res` | Resultado de 32 bits. |
| `EQ`, `LT`, `LTU` | Indicam igualdade, menor que com sinal e menor que sem sinal entre os operandos. |

| `aluOp` | Operação selecionada |
| --- | --- |
| `000` | ADD com `subtract = 0`; SUB com `subtract = 1`. |
| `001` | SLL. |
| `010` | SLT. |
| `011` | SLTU. |
| `100` | XOR. |
| `101` | SRL com `arithmeticShift = 0`; SRA com `arithmeticShift = 1`. |
| `110` | OR. |
| `111` | AND. |

### Papel do main

O `main.sv` faz o decode a partir dos campos `opcode`, `funct3` e `funct7` da instrução. Nas operações entre registradores, usa `op1` e `op2`; nas versões imediatas, obtém o segundo operando da própria instrução. Os imediatos aritméticos e lógicos de 12 bits são estendidos com sinal para 32 bits, inclusive em SLTIU.

| Sinal do main | Direção | Significado |
| --- | --- | --- |
| `Instr` | Entrada | Instrução já codificada em 32 bits. |
| `op1`, `op2` | Entrada | Valores dos registradores rs1 e rs2, fornecidos externamente. |
| `pc` | Entrada | Endereço da instrução atual; nos testes das operações, recebe zero. |
| `res` | Saída | Resultado da operação ou cálculo solicitado. |
| `valid` | Saída | Indica que a instrução é atendida por este bloco. |
| `branchTaken` | Saída | Indica que a condição de um desvio foi satisfeita. |
| `target` | Saída | Endereço de destino de um desvio ou salto. |

O `main` também contém cálculos auxiliares para LUI, AUIPC, endereços de loads/stores, desvios e saltos. A suíte atual se concentra nas dez operações da ULA: não inclui testes separados desses cálculos nem dos componentes isolados. Memória, banco de registradores e tratamento de instruções de sistema ficam fora deste projeto.

## Como os testes estão divididos

Há **dez grupos independentes**, um para cada operação, totalizando **922 casos de teste**. Cada grupo possui um arquivo em `tests/vectors/` e outro em `tests/expected/`.

| Grupo | Referências | Casos | O que avalia |
| --- | --- | ---: | --- |
| ADD | `add.tv` / `add.ok` | 41 | ADD e ADDI, zero, valores negativos, limites de 32 bits e resultados que excedem essa largura. |
| SUB | `sub.tv` / `sub.ok` | 16 | Subtração, operandos iguais, resultados negativos e limites de 32 bits. |
| AND | `and.tv` / `and.ok` | 41 | AND e ANDI, máscaras de bits, zeros, uns e padrões alternados. |
| OR | `or.tv` / `or.ok` | 41 | OR e ORI com diferentes combinações de bits e imediatos. |
| XOR | `xor.tv` / `xor.ok` | 41 | XOR e XORI, operandos iguais e padrões de bits diferentes. |
| SLT | `slt.tv` / `slt.ok` | 41 | SLT e SLTI, igualdade e comparação de valores positivos e negativos. |
| SLTU | `sltu.tv` / `sltu.ok` | 41 | SLTU e SLTIU, igualdade e comparação sem sinal, inclusive com o bit mais alto em 1. |
| SLL | `sll.tv` / `sll.ok` | 220 | SLL e SLLI, distâncias de 0 a 31, descarte dos bits superiores e uso dos cinco bits da distância. |
| SRL | `srl.tv` / `srl.ok` | 220 | SRL e SRLI, distâncias de 0 a 31 e preenchimento com zeros. |
| SRA | `sra.tv` / `sra.ok` | 220 | SRA e SRAI, distâncias de 0 a 31 e preservação do sinal em valores positivos e negativos. |

Os dez grupos usam o mesmo [alu_tb.v](tests/alu_tb.v), que é o **testbench**: o código responsável por aplicar entradas e conferir saídas. Cada grupo tem uma compilação e simulação separadas, usando seus próprios arquivos de referência.

### vectors/: entradas e resultados esperados

Cada linha de um arquivo `.tv` contém quatro campos hexadecimais de 32 bits:

```text
instrução_operando1_operando2_resultado_esperado
```

Exemplo real de [add.tv](tests/vectors/add.tv):

```text
003100b3_cafe0000_0000babe_cafebabe
```

| Campo | Interpretação |
| --- | --- |
| `003100b3` | Codificação de `add x1, x2, x3`. |
| `cafe0000` | Primeiro operando. |
| `0000babe` | Segundo operando. |
| `cafebabe` | Resultado esperado da soma. |

O testbench carrega esses valores com `$readmemh`. Nas instruções imediatas, o valor usado na operação vem da instrução; os casos fornecem um `op2` diferente para verificar essa seleção.

### expected/: saída de referência

Cada arquivo `.ok` contém o texto esperado da simulação de uma operação. Além do resultado numérico registrado no `.tv`, existe, portanto, uma referência para o log completo.

Por exemplo, `tests/expected/add.ok` contém os registros esperados para os casos de `tests/vectors/add.tv`. Os arquivos de referência são fixos e não são sobrescritos ao executar os testes.

### Como um caso é avaliado

1. O script conta os vetores do grupo e compila o circuito junto com `alu_tb.v`.
2. O testbench lê a instrução, os dois operandos e o resultado esperado do arquivo `.tv`.
3. As entradas são aplicadas ao `main`, que faz o decode e chama a ULA.
4. O testbench aguarda 10 ns de simulação para que as saídas estabilizem.
5. Compara `res` com o resultado esperado e registra a saída. Também exige `valid = 1`, `branchTaken = 0` e `target = 0`, pois as instruções testadas são operações da ULA.
6. Depois de todos os casos, o script compara o log produzido com o arquivo `.ok`, usando `diff`.

A comparação no testbench usa `!==`, permitindo detectar também resultados desconhecidos (`X`) ou em alta impedância (`Z`) onde se esperam valores definidos. Os 10 ns são uma espera da simulação, não uma medição do tempo de execução em hardware.

Um grupo recebe **OK** somente quando a simulação termina sem falhas e sua saída coincide com a referência. Se um resultado divergir, o testbench informa o índice do caso, contado a partir de zero, e os valores esperado e obtido.

Essa avaliação verifica o comportamento nos casos fornecidos. Não representa um teste de todas as combinações possíveis de operandos de 32 bits.

### output/: arquivos gerados

Cada operação possui sua própria pasta de resultados. Por exemplo:

```text
tests/output/add/
├── tb
├── compile.log
├── simulation.log
├── test.out
└── wave.vcd
```

| Arquivo | Conteúdo |
| --- | --- |
| `tb` | Simulação compilada pelo Icarus Verilog, executada com `vvp`. |
| `compile.log` | Mensagens produzidas durante a compilação. |
| `simulation.log` | Saída completa do simulador. |
| `test.out` | Saída usada na comparação com o `.ok`, removendo somente a mensagem informativa de `$finish`. |
| `wave.vcd` | Histórico dos sinais, que pode ser aberto em um visualizador de formas de onda. |

Esses arquivos são atualizados a cada execução do grupo correspondente. As entradas e referências permanecem em `vectors/` e `expected/`.

## Como executar

É necessário ter **Icarus Verilog**, que fornece os comandos `iverilog` e `vvp`, além de um ambiente com shell e os utilitários usados pelo script (`awk`, `sed` e `diff`).

Em sistemas com `apt`, o script de instalação disponível no projeto pode ser executado com:

```sh
sh setup.sh
```

Na raiz do projeto, execute todos os testes com:

```sh
./run.sh
```

Para executar apenas uma operação ou selecionar algumas:

```sh
./run.sh add
./run.sh add sub sra
```

Também é possível chamar diretamente o script de testes:

```sh
./tests/run.sh
```

### Como interpretar o resultado

Quando os testes passam, cada grupo imprime:

```text
Testando add...
OK
Testando sub...
OK
```

Se houver divergência, o script apresenta:

```text
Testando add...
ERRO: saída incorreta
ESPERADA:
... conteúdo da referência ...
OBTIDA:
... saída da simulação e detalhes do erro ...
```

Falhas de compilação e referências ausentes ou vazias também produzem mensagens de erro. Uma falha em um grupo não impede a execução dos demais grupos selecionados. O script retorna **código 0** quando todos passam e **código 1** quando há falha.

Para investigar um erro, consulte o caso indicado em `vectors/<operação>.tv` e os arquivos em `output/<operação>/`. O resultado esperado está no último campo do vetor; os valores obtidos aparecem em `test.out` e `simulation.log`.

## Como adicionar um caso de teste

1. Escolha o arquivo da operação em `tests/vectors/`.
2. Acrescente uma linha com a instrução, os operandos e o resultado correto, calculado independentemente da ULA.
3. Acrescente o registro correspondente em `tests/expected/<operação>.ok`. Os tempos avançam de 10 em 10 ns: 10, 20, 30 e assim por diante.
4. Execute o grupo, por exemplo, `./run.sh add`.

O script conta as linhas de vetores automaticamente; não é necessário alterar o testbench. Se inserir um caso no meio do arquivo, ajuste também os tempos dos registros seguintes no `.ok`. A referência deve representar o comportamento correto, e não ser substituída pela saída de uma execução que falhou.
