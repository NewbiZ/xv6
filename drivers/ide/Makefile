top_srcdir = ../..
include $(top_srcdir)/Makefile.common

IDE_OBJS = \
	ide.o    \

.PHONY: all clean

all: kernel_driver_ide.o

kernel_driver_ide.o: $(IDE_OBJS)
	@echo "[LD] [DRIVERS] $@"
	@$(LD) $(LDFLAGS) -r -o $@ $^

%.o: %.c
	@echo "[CC] [DRIVERS] $@"
	@$(CC) $(CFLAGS) -c -o $@ $*.c

clean:
	$(RM) -rf *.o
