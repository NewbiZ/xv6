TOP_SRCDIR = .
COMPONENT = DISTRIB  
include $(TOP_SRCDIR)/Makefile.common

DISTRIB_COREUTILS =    \
	coreutils/cat      \
	coreutils/chgrp    \
	coreutils/chmod    \
	coreutils/chown    \
	coreutils/cp       \
	coreutils/date     \
	coreutils/dd       \
	coreutils/df       \
	coreutils/dmesg    \
	coreutils/echo     \
	coreutils/false    \
	coreutils/halt     \
	coreutils/hostname \
	coreutils/kill     \
	coreutils/ln       \
	coreutils/login    \
	coreutils/ls       \
	coreutils/mkdir    \
	coreutils/mknod    \
	coreutils/more     \
	coreutils/mount    \
	coreutils/mv       \
	coreutils/ps       \
	coreutils/pwd      \
	coreutils/rm       \
	coreutils/rmdir    \
	coreutils/sed      \
	coreutils/sh       \
	coreutils/stty     \
	coreutils/su       \
	coreutils/sync     \
	coreutils/true     \
	coreutils/umount   \
	coreutils/uname    \
	coreutils/init     \

DISTRIB_ULIBC = ulibc/ulibc.o

DISTRIB_ULIBC_TESTS = \
	tests/stdlib      \
	tests/string      \
	tests/init        \

.PHONY: all check motd
.PRECIOUS: coreutils/%.o ulibc/%.o tests/%.o

all: distrib.img

check: distrib_check.img

motd:
	@echo "\033[32;1m"
	@echo "[>>] [DISTRIB  ]"
	@echo -n "\033[0m"

distrib.img: motd mkfs.xv6 $(DISTRIB_COREUTILS)
	$(LOG_CMD) ./mkfs.xv6 distrib.img release
	@echo "\033[32;1mCreated distribution disk image "\""$@"\""\033[0m"

distrib_check.img: motd mkfs.xv6 $(DISTRIB_COREUTILS) $(DISTRIB_ULIBC_TESTS)
	$(LOG_CMD) ./mkfs.xv6 distrib_check.img test
	@echo "\033[32;1mCreated test distribution disk image "\""$@"\""\033[0m"

mkfs.xv6: mkfs/mkfs.xv6.c
	$(LOG_CC) $(CC) -Wall -ggdb -O0 -I$(shell pwd)/../include -o mkfs.xv6 mkfs/mkfs.xv6.c

coreutils/%: coreutils/%.o $(DISTRIB_ULIBC)
	$(LOG_LD) $(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $@ $^
	$(LOG_CMD) strip -s $@

coreutils/%.o: coreutils/%.c
	$(LOG_CC) $(CC) $(CFLAGS) -c -o $@ coreutils/$*.c

$(DISTRIB_ULIBC): $(DISTRIB_ULIBC_OBJECTS)
	$(LOG_MAKE) -C ulibc

tests/%: tests/%.o $(DISTRIB_ULIBC)
	$(LOG_LD) $(LD) $(LDFLAGS) -N -e main -Ttext 0 -o $@ $^
	$(LOG_CMD) strip -s $@

tests/%.o: tests/%.c
	$(LOG_CC) $(CC) $(CFLAGS) -c -o $@ tests/$*.c

clean:
	$(LOG_MAKE) -C ulibc clean
	$(LOG_CMD) $(RM) -rf distrib.img
	$(LOG_CMD) $(RM) -rf distrib_check.img
	$(LOG_CMD) $(RM) -rf mkfs.xv6
	$(LOG_CMD) $(RM) -rf $(DISTRIB_COREUTILS)
	$(LOG_CMD) $(RM) -rf coreutils/*.o
	$(LOG_CMD) $(RM) -rf tests/*.o
	$(LOG_CMD) $(RM) -rf $(DISTRIB_ULIBC_TESTS)
