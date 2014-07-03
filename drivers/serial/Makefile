TOP_SRCDIR = ../..
COMPONENT = "DRIVERS"
include $(TOP_SRCDIR)/Makefile.common

SERIAL_OBJS = \
	uart.o    \

.PHONY: all clean

all: kernel_driver_serial.o

kernel_driver_serial.o: $(SERIAL_OBJS)
	$(LOG_LD) $(LD) $(LDFLAGS) -r -o $@ $^

%.o: %.c
	$(LOG_CC) $(CC) $(CFLAGS) -c -o $@ $*.c

clean:
	$(LOG_CMD) $(RM) -rf *.o
