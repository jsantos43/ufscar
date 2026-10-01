# Simulado P1 AED1
Esse arquivo .md trata-se da resolução do simulado da primeira prova de AED1

## Questão 1
Considere o Tipo Abstrato de Dado FILA, implementado através de uma lista duplamente encadeada, circular, segundo os diagramas abaixo. Implemente, da forma mais apropriada para proporcionar portabilidade e reusabilidade, as operações Retira, Vazia e Destrói:

``` 
Boolean Vazia(variável por referência F do tipo Fila)
Inicio
  Se F.Primeiro == NULL Então
    retorne Verdadeiro
  Senão
    retorne Falso
  FimSe
FimFunção

Void Retira(variável por referência F do tipo Fila, variável por referência X do tipo Elemento, variável por referência Erro tipo boolean)
Inicio
  // Caso 1: Fila vazia
  Se Vazia(F) == Verdadeiro Então
    Erro = Verdadeiro
    Retorna
  FimSe

  // Caso 2: For unico elemento
  Se F.Primeiro == F.Ultimo Então
    Elemento = F.Primeiro->info
    DeleteNode(F.Primeiro)
    F.Primeiro = NULL
    F.Ultimo = NULL
    Erro = Falso
    Retorna
  FimSe

  // Caso 3: Fila tem mais de um elemento
  NodePtr PAux = F.Primeiro
  Elemento = PAux->info
  
  F.Primeiro = PAux->Dir
  F.Primeiro->Esq = F.Ultimo
  F.Ultimo->Dir = F.Primeiro

  DeleteNode(PAux)
  Erro = Falso
  Retorna
FimFunção

Void Destroi(variável por referência F do tipo Fila)
Inicio
  // Caso 1: Fila Vazia
  Se Vazia(F) == Verdadeiro Então
    Retorna
  FimSe

  // Caso 2: Unico Elemento
  Se F.Primeire == F.Ultimo Então
    DeleteNode(F.Primeiro)
  FimSe

  // Caso 3: Fila com mais de um elemento
  PAux = F.Primeiro->Dir // Começa no segundo elemento

  // Remove os valores do meio da fila
  Enquanto PAux->Dir != F.Primeiro Faça
    PAux = PAux->Dir
    DeleteNode(PAux->Esq)
  FimEnquanto

  //Remove as extremidades
  DeleteNode(F.Primeiro)
  DeleteNode(F.Ultimo)
FimFunção

``` 

## Questão 2
Um município está implementando uma Fila de Vacinação. O primeiro critério para entrar na Fila
de Vacinação é a idade, ou seja: pessoas mais velhas entrarão na fila à frente de pessoas mais jovens que já estiverem na fila. O segundo critério da Fila de Vacinação é a ordem de chegada, ou seja: se já existem pessoas na fila com determinada idade, em anos, novas pessoas com essa mesma idade em anos devem ser inseridas na fila após as pessoas de mesma idade que entraram na fila primeiro. Ou seja, a Fila de Vacinação será uma “Fila de Prioridades”, na qual deve ser priorizado o atendimento às pessoas de maior idade em anos. Uma possível solução a essa situação é implementar a Fila de Vacinação através de uma lista encadeada, circular, ordenada em ordem decrescente pela idade em anos, com elementos repetidos, conforme os diagramas abaixo.

``` 
Void Insere (variável por referência FV do tipo FilaDeVacinacao; variável Idade do tipo inteiro);
Inicio
  // Caso 1: A Fila está vazia
  Se Vazia(FV) == Verdadeiro Então
    F.Primeiro = NewNode()
    F.Primeiro->Info = Idade
    F.Primeiro->Next = F.Primeiro
    F.Ultimo = F.Primeiro
  FimSe
FimFunção
```