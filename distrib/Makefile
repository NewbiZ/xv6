TOP_SRCDIR = .
COMPONENT = DISTRIB  
include $(TOP_SRCDIR)/Makefile.common

DISTRIB_COREUTILS = \
	coreutils/cat     \
	coreutils/echo    \
	coreutils/grep    \
	coreutils/init    \
	coreutils/kill    \
	coreutils/ln      \
	coreutils/ls      \
	coreutils/mkdir   \
	coreutils/rm      \
	coreutils/sh      \
	coreutils/wc      \
	coreutils/halt    \

DISTRIB_ULIBC =   \
	ulibc/ctype.o   \
	ulibc/errno.o   \
	ulibc/locale.o  \
	ulibc/math.o    \
	ulibc/setjmp.o  \
	ulibc/assert.o  \
	ulibc/signal.o  \
	ulibc/stdio.o   \
	ulibc/stdlib.o  \
	ulibc/string.o  \
	ulibc/time.o    \
	ulibc/usys.o    \
	ulibc/printf.o  \
	ulibc/ulib.o    \
	ulibc/umalloc.o \

DISTRIB_ULIBC_TESTS = \
	tests/stdlib        \
	tests/string        \
	tests/init          \

.PHONY: all check motd
.PRECIOUS: coreutils/%.o ulibc/%.o tests/%.o

all: distrib.img

check: distrib_check.img

motd:
	@echo "\033[32;1m"
	@echo "[>>] [DISTRIB  ]"
	@echo -n "\033[0m"

distrib.img: motd mkfs.xv6 $(DISTRIB_COREUTILS)
	$(LOG_CMD) ./mkfs.xv6 distrib.img $(DISTRIB_COREUTILS)
	@echo "\033[32;1mCreated distribution disk image "\""$@"\""\033[0m"

distrib_check.img: motd mkfs.xv6 $(DISTRIB_COREUTILS) $(DISTRIB_ULIBC_TESTS)
	$(LOG_CMD) ./mkfs.xv6 distrib_check.img \
		$(DISTRIB_ULIBC_TESTS)
	@echo "\033[32;1mCreated test distribution disk image "\""$@"\""\033[0m"

mkfs.xv6: mkfs/mkfs.xv6.c
	$(LOG_CC) $(CC) -Wall -ggdb -O0 -I$(shell pwd)/../include -o mkfs.xv6 mkfs/mkfs.xv6.c

coreutils/%: coreutils/%.o $(DISTRIB_ULIBC)
	$(LOG_LD) $(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $@ $^

coreutils/%.o: coreutils/%.c
	$(LOG_CC) $(CC) $(CFLAGS) -c -o $@ coreutils/$*.c

ulibc/%.o: ulibc/%.c
	$(LOG_CC) $(CC) $(CFLAGS) -c -o $@ ulibc/$*.c

ulibc/%.o: ulibc/%.S
	$(LOG_CC) $(CC) $(ASFLAGS) -c -o $@ ulibc/$*.S

tests/%: tests/%.o $(DISTRIB_ULIBC)
	$(LOG_LD) $(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $@ $^

tests/%.o: tests/%.c
	$(LOG_CC) $(CC) $(CFLAGS) -c -o $@ tests/$*.c

clean:
	$(LOG_CMD) $(RM) -rf distrib.img
	$(LOG_CMD) $(RM) -rf distrib_check.img
	$(LOG_CMD) $(RM) -rf mkfs.xv6
	$(LOG_CMD) $(RM) -rf $(DISTRIB_COREUTILS)
	$(LOG_CMD) $(RM) -rf coreutils/*.o
	$(LOG_CMD) $(RM) -rf ulibc/*.o
	$(LOG_CMD) $(RM) -rf tests/*.o
	$(LOG_CMD) $(RM) -rf $(DISTRIB_ULIBC_TESTS)

