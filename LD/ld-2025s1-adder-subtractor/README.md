[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=23950300)
# Somador/Subtrator de 32 bits

Considere o *template* a seguir para [implementar](top.v) um somador/subtrator de 32 bits:

```verilog
module top (
    input  [31:0] a,
    input  [31:0] b,
    input         sub, // 0 = soma, 1 = subtração
    output [31:0] result,
    output        carry_out, // ~empresta se sub
    output        overflow);



endmodule
```

Isso deve ser feito usando `generate` para instanciar os 32 [somadores completos](full_adder.v). 