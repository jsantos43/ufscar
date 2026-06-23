[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=24150158)
# Maquina de Estados Finitos (Moore vs Mealy)

O objetivo desta prática é construir máquinas de estados finitos para reconhecer a sequência `1-0-0-1`. Você deve criar uma implementação para o modelo de [Moore](moore.sv) e outra para o de [Mealy](mealy.sv). Ambas devem considerar que a sequência pode ser sobreposta, ou seja, `1-0-0-1-0-0-1` deve ser reconhecida duas vezes, conforme a figura a seguir:

![Simulação desejada](moore-mealy.png)

Note que a máquina de Mealy é capaz de reconhecer a sequência **antes** da subida do *clock* da última entrada procurada. 
