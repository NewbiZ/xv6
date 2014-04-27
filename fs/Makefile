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

KERNEL_FS_OBJS = \
	bio.o          \
	fs.o           \
	log.o          \

all: $(KERNEL_FS_OBJS)

%.o: %.c
	@echo "[CC] [FS     ] $@"
	@$(CC) $(CFLAGS) -c -o $@ $*.c

%.o: %.S
	@echo "[CC] [FS     ] $@"
	@$(CC) $(ASFLAGS) -c -o $@ $*.S

clean:
	$(RM) -rf *.o
