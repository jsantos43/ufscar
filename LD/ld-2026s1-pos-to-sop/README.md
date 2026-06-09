[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=23824919)
# Convertendo uma função lógica de POS para SOP

Considere a função lógica a seguir, implementada na forma canônica de POS

```verilog
module top (
    input x, y, z,
    output f);
    assign f = (~x | ~y | ~z) & (~x | ~y | z) & (x | ~y | z) & (~x | y | ~z);
endmodule
```

Obtenha uma [implementação](top.v) equivalente na forma SOP, sem o uso de parênteses, seja na forma canônica ou simplificada. 