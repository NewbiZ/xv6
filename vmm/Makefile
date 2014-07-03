TOP_SRCDIR = ..
COMPONENT = VMM    
include $(TOP_SRCDIR)/Makefile.common

KERNEL_VMM_OBJS = \
	vm.o            \

.PHONY: all clean

all: kernel_vmm.o

kernel_vmm.o: $(KERNEL_VMM_OBJS)
	$(LOG_LD) $(LD) $(LDFLAGS) -r -o $@ $^

%.o: %.c
	$(LOG_CC) $(CC) $(CFLAGS) -c -o $@ $*.c

clean:
	$(LOG_CMD) $(RM) -rf *.o
