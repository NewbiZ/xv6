top_srcdir = ../..
include $(top_srcdir)/Makefile.common

KEYBOARD_OBJS = \
	kbd.o    \

.PHONY: all clean

all: kernel_driver_keyboard.o

kernel_driver_keyboard.o: $(KEYBOARD_OBJS)
	@echo "[LD] [DRIVERS] $@"
	@$(LD) $(LDFLAGS) -r -o $@ $^

%.o: %.c
	@echo "[CC] [DRIVERS] $@"
	@$(CC) $(CFLAGS) -c -o $@ $*.c

clean:
	$(RM) -rf *.o
