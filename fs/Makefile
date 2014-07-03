TOP_SRCDIR = ..
COMPONENT = FS     
include $(TOP_SRCDIR)/Makefile.common

KERNEL_FS_OBJS = \
	bio.o          \
	fs.o           \
	log.o          \

.PHONY: all clean

all: kernel_fs.o

kernel_fs.o: $(KERNEL_FS_OBJS)
	$(LOG_LD) $(LD) $(LDFLAGS) -r -o $@ $^

%.o: %.c
	$(LOG_CC) $(CC) $(CFLAGS) -c -o $@ $*.c

%.o: %.S
	$(LOG_CC) $(CC) $(ASFLAGS) -c -o $@ $*.S

clean:
	$(LOG_CMD) $(RM) -rf *.o
