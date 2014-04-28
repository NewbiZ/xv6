top_srcdir = ../..
include $(top_srcdir)/Makefile.common

SERIAL_OBJS = \
	uart.o    \

.PHONY: all clean

all: kernel_driver_serial.o

kernel_driver_serial.o: $(SERIAL_OBJS)
	@echo "[LD] [DRIVERS] $@"
	@$(LD) $(LDFLAGS) -r -o $@ $^

%.o: %.c
	@echo "[CC] [DRIVERS] $@"
	@$(CC) $(CFLAGS) -c -o $@ $*.c

clean:
	$(RM) -rf *.o
