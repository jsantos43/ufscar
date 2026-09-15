# Toolchain RISC-V
CROSS = riscv64-linux-gnu
AS    = $(CROSS)-as
LD    = $(CROSS)-ld
QEMU  = qemu-riscv64

# Alvo padrão: nada (só mostra ajuda)
.PHONY: all
all:
	@echo "Use: make <nome> para compilar e rodar <nome>.s"

# Regra genérica: make <nome>
%: %.s
	$(AS) -o $*.o $*.s
	$(LD) -o $*.elf $*.o
	@echo "=== Executando $*.elf ==="
	@$(QEMU) ./$*.elf ; \
	EC=$$? ; \
	echo "=== Código de saída: $$EC ==="

clean:
	rm -f *.o *.elf
