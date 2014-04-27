CC = gcc
LD = ld
LDFLAGS = -m elf_i386
ASFLAGS = -m32 -gdwarf-2 -Wa,-divide
CFLAGS = 										\
	-fno-pic 									\
	-static 									\
	-fno-builtin 							\
	-fno-strict-aliasing 			\
	-Wall 										\
	-ggdb 										\
	-m32 											\
	-fno-omit-frame-pointer 	\
	-fno-stack-protector			\
	-fno-pic									\
	-nostdinc									\

DISTRIB_COREUTILS =	\
	coreutils/cat			\
	coreutils/echo		\
	coreutils/grep		\
	coreutils/init		\
	coreutils/kill		\
	coreutils/ln			\
	coreutils/ls			\
	coreutils/mkdir		\
	coreutils/rm			\
	coreutils/sh			\
	coreutils/wc			\
	coreutils/halt		\

DISTRIB_ULIBC =		\
	ulibc/ulib.o 		\
	ulibc/usys.o 		\
	ulibc/printf.o 	\
	ulibc/umalloc.o	\

all: distrib.img

distrib.img: mkfs.xv6 $(DISTRIB_COREUTILS)
	@echo "\033[36;1mCreating distribution disk image "\""$@"\""\033[0m"
	@./mkfs.xv6 distrib.img $(DISTRIB_COREUTILS)

mkfs.xv6: mkfs/mkfs.xv6.c
	@echo "\033[33;1m[CC] [MKFS     ] $@\033[0m"
	@$(CC) -Wall -o mkfs.xv6 mkfs/mkfs.xv6.c

coreutils/%: coreutils/%.o $(DISTRIB_ULIBC)
	@echo "\033[33;1m[LD] [COREUTILS] $@\033[0m"
	@$(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $@ $^

coreutils/%.o: coreutils/%.c
	@echo "\033[32;1m[CC] [COREUTILS] $@\033[0m"
	@$(CC) $(CFLAGS) -c -o $@ coreutils/$*.c

ulibc/%.o: ulibc/%.c
	@echo "\033[32;1m[CC] [ULIBC    ] $@\033[0m"
	@$(CC) $(CFLAGS) -c -o $@ ulibc/$*.c

ulibc/%.o: ulibc/%.S
	@echo "\033[32;1m[CC] [ULIBC    ] $@\033[0m"
	@$(CC) $(ASFLAGS) -c -o $@ ulibc/$*.S

clean:
	$(RM) -rf distrib.img
	$(RM) -rf mkfs.xv6
	$(RM) -rf $(DISTRIB_COREUTILS)

