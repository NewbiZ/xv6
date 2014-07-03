TOP_SRCDIR = ../..
COMPONENT = "DRIVERS"
include $(TOP_SRCDIR)/Makefile.common

KEYBOARD_OBJS = \
	kbd.o    \

.PHONY: all clean

all: kernel_driver_keyboard.o

kernel_driver_keyboard.o: $(KEYBOARD_OBJS)
	$(LOG_LD) $(LD) $(LDFLAGS) -r -o $@ $^

%.o: %.c
	$(LOG_CC) $(CC) $(CFLAGS) -c -o $@ $*.c

clean:
	$(LOG_CMD) $(RM) -rf *.o
