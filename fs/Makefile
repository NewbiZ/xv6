top_srcdir = ..
include $(top_srcdir)/Makefile.common

KERNEL_FS_OBJS = \
	bio.o          \
	fs.o           \
	log.o          \

.PHONY: all clean

all: kernel_fs.o

kernel_fs.o: $(KERNEL_FS_OBJS)
	@echo "[LD] [FS     ] $@"
	@$(LD) $(LDFLAGS) -r -o $@ $^

%.o: %.c
	@echo "[CC] [FS     ] $@"
	@$(CC) $(CFLAGS) -c -o $@ $*.c

%.o: %.S
	@echo "[CC] [FS     ] $@"
	@$(CC) $(ASFLAGS) -c -o $@ $*.S

clean:
	$(RM) -rf *.o
