TOP_SRCDIR = ..
COMPONENT = DEVICES
include $(TOP_SRCDIR)/Makefile.common

KERNEL_DEVICES_OBJS = \
	console.o           \
	null.o              \
	zero.o              \
	devices.o           \

.PHONY: all clean

all: kernel_devices.o

kernel_devices.o: $(KERNEL_DEVICES_OBJS)
	$(LOG_LD) $(LD) $(LDFLAGS) -r -o $@ $^

%.o: %.c
	$(LOG_CC) $(CC) $(CFLAGS) -c -o $@ $*.c

clean:
	$(LOG_CMD) $(RM) -rf *.o
