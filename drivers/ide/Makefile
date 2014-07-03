TOP_SRCDIR = ../..
COMPONENT = "DRIVERS"
include $(TOP_SRCDIR)/Makefile.common

IDE_OBJS = \
	ide.o    \

.PHONY: all clean

all: kernel_driver_ide.o

kernel_driver_ide.o: $(IDE_OBJS)
	$(LOG_LD) $(LD) $(LDFLAGS) -r -o $@ $^

%.o: %.c
	$(LOG_CC) $(CC) $(CFLAGS) -c -o $@ $*.c

clean:
	$(LOG_CMD) $(RM) -rf *.o
