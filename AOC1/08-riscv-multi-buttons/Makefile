# Gera o .hex da memoria a partir do assembly
# Uso: make            (deslocador_fpga.hex)
#      make clean

PROG = deslocador_fpga

# Ubuntu: riscv64-unknown-elf-*, Arch: riscv64-elf-*
CROSS ?= $(shell command -v riscv64-unknown-elf-as >/dev/null && echo riscv64-unknown-elf || echo riscv64-elf)

$(PROG).hex: $(PROG).asm
	$(CROSS)-as -march=rv32i -o $(PROG).o $<
	$(CROSS)-ld -m elf32lriscv -Ttext=0 -e _start -o $(PROG).elf $(PROG).o
	$(CROSS)-objcopy -O verilog --verilog-data-width=4 $(PROG).elf $@
	rm -f $(PROG).o $(PROG).elf

clean:
	rm -f $(PROG).hex

.PHONY: clean
