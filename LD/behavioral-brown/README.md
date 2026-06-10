# Evitando código comportamental para funções combinacionais 

O objetivo desta simulação é converter código Verilog comportamental em funcional/datapath. Para isso, você deve analizar cada um dos arquivos a seguir e remover o comando `always@` do seu código, substituindo por outros que mantenham a funcionalidade original de cada módulo:

- [addern.sv](addern.sv)  
- [comparator.sv](comparator.sv)  
- [compare.sv](compare.sv)  
- [dec2to4.sv](dec2to4.sv)  
- [mux4to1.sv](mux4to1.sv)  
- [mux8to2.sv](mux8to2.sv)  
- [priority_encoder.sv](priority_encoder.sv)  
- [shifter.sv](shifter.sv)

O script de testes mostra esta mensagem a cada módulo testado sempre que um `@` é encontrado em qualquer arquivo e não diz respeito a um módulo específico:

> Modo incorreto: você não pode usar Verilog comportamental.

## Trabalho em grupo

É fundamental que todos os membros do grupo tenham ao menos uma contribuição no repositório (commit), caso contrário **a nota geral não será considerada**. 