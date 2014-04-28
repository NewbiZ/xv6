top_srcdir = ..
include $(top_srcdir)/Makefile.common

KERNEL_VMM_OBJS = \
	vm.o            \

.PHONY: all clean

all: kernel_vmm.o

kernel_vmm.o: $(KERNEL_VMM_OBJS)
	@echo "[LD] [VMM    ] $@"
	@$(LD) $(LDFLAGS) -r -o $@ $^

%.o: %.c
	@echo "[CC] [VMM    ] $@"
	@$(CC) $(CFLAGS) -c -o $@ $*.c

clean:
	$(RM) -rf *.o
