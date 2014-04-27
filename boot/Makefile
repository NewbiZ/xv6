CC = gcc
AS = gas
LD = ld
CFLAGS =                    \
	-fno-pic                  \
	-static                   \
	-fno-builtin              \
	-fno-strict-aliasing      \
	-Wall                     \
	-ggdb                     \
	-m32                      \
	-fno-omit-frame-pointer   \
	-fno-stack-protector      \
	-I$(shell pwd)/../include \

ASFLAGS =                   \
	-m32                      \
	-gdwarf-2                 \
	-Wa,-divide               \
	-I$(shell pwd)/../include \

LDFLAGS += -m elf_i386

KERNEL_BOOT_OBJS = \
	main.o           \

all: $(KERNEL_BOOT_OBJS)

%.o: %.c
	@echo "[CC] [BOOT   ] $@"
	@$(CC) $(CFLAGS) -c -o $@ $*.c

clean:
	$(RM) -rf *.o
