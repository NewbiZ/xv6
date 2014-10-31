TOP_SRCDIR = .
COMPONENT = USER LIBC
include $(TOP_SRCDIR)/Makefile.common

DISTRIB_ULIBC = ulibc.o

DISTRIB_ULIBC_OBJECTS =     \
	src/ctype/isalnum.o     \
	src/ctype/isalpha.o     \
	src/ctype/iscntrl.o     \
	src/ctype/isdigit.o     \
	src/ctype/isgraph.o     \
	src/ctype/islower.o     \
	src/ctype/isprint.o     \
	src/ctype/ispunct.o     \
	src/ctype/isspace.o     \
	src/ctype/isupper.o     \
	src/ctype/isxdigit.o    \
	src/ctype/tolower.o     \
	src/ctype/toupper.o     \
	src/errno/errno.o       \
	src/locale/localeconv.o \
	src/locale/setlocale.o  \
	src/math/acos.o         \
	src/math/asin.o         \
	src/math/atan2.o        \
	src/math/atan.o         \
	src/math/ceil.o         \
	src/math/cos.o          \
	src/math/cosh.o         \
	src/math/exp.o          \
	src/math/fabs.o         \
	src/math/floor.o        \
	src/math/fmod.o         \
	src/math/frexp.o        \
	src/math/ldexp.o        \
	src/math/log10.o        \
	src/math/log.o          \
	src/math/modf.o         \
	src/math/pow.o          \
	src/math/sin.o          \
	src/math/sinh.o         \
	src/math/sqrt.o         \
	src/math/tan.o          \
	src/math/tanh.o         \
	src/setjmp/setjmp.o     \
	src/setjmp/longjmp.o    \
	src/assert/assert.o     \
	src/signal/signal.o     \
	src/signal/raise.o      \
	src/stdio/stdio.o       \
	src/stdio/clearerr.o    \
	src/stdio/fclose.o      \
	src/stdio/feof.o        \
	src/stdio/ferror.o      \
	src/stdio/fflush.o      \
	src/stdio/fgetc.o       \
	src/stdio/fgetpos.o     \
	src/stdio/fgets.o       \
	src/stdio/fopen.o       \
	src/stdio/fprintf.o     \
	src/stdio/fputc.o       \
	src/stdio/fputs.o       \
	src/stdio/fread.o       \
	src/stdio/freopen.o     \
	src/stdio/fscanf.o      \
	src/stdio/fseek.o       \
	src/stdio/fsetpos.o     \
	src/stdio/fwrite.o      \
	src/stdio/getc.o        \
	src/stdio/getchar.o     \
	src/stdio/gets.o        \
	src/stdio/ftell.o       \
	src/stdio/perror.o      \
	src/stdio/printf.o      \
	src/stdio/putc.o        \
	src/stdio/putchar.o     \
	src/stdio/puts.o        \
	src/stdio/remove.o      \
	src/stdio/rename.o      \
	src/stdio/rewind.o      \
	src/stdio/scanf.o       \
	src/stdio/setbuf.o      \
	src/stdio/setvbuf.o     \
	src/stdio/sprintf.o     \
	src/stdio/sscanf.o      \
	src/stdio/tmpfile.o     \
	src/stdio/tmpnam.o      \
	src/stdio/ungetc.o      \
	src/stdio/vfprintf.o    \
	src/stdio/vprintf.o     \
	src/stdio/vsprintf.o    \
	src/stdlib/abort.o      \
	src/stdlib/abs.o        \
	src/stdlib/atof.o       \
	src/stdlib/atoi.o       \
	src/stdlib/atol.o       \
	src/stdlib/bsearch.o    \
	src/stdlib/calloc.o     \
	src/stdlib/div.o        \
	src/stdlib/exit.o       \
	src/stdlib/free.o       \
	src/stdlib/getenv.o     \
	src/stdlib/labs.o       \
	src/stdlib/ldiv.o       \
	src/stdlib/malloc.o     \
	src/stdlib/mblen.o      \
	src/stdlib/mbstowcs.o   \
	src/stdlib/mbtowc.o     \
	src/stdlib/qsort.o      \
	src/stdlib/rand.o       \
	src/stdlib/realloc.o    \
	src/stdlib/strtod.o     \
	src/stdlib/strtol.o     \
	src/stdlib/strtoul.o    \
	src/stdlib/system.o     \
	src/stdlib/wcstombs.o   \
	src/stdlib/wctomb.o     \
	src/string/memchr.o     \
	src/string/memcmp.o     \
	src/string/memcpy.o     \
	src/string/memmove.o    \
	src/string/memset.o     \
	src/string/strcat.o     \
	src/string/strchr.o     \
	src/string/strcmp.o     \
	src/string/strcoll.o    \
	src/string/strcpy.o     \
	src/string/strcspn.o    \
	src/string/strerror.o   \
	src/string/strlen.o     \
	src/string/strncat.o    \
	src/string/strncmp.o    \
	src/string/strncpy.o    \
	src/string/strpbrk.o    \
	src/string/strrchr.o    \
	src/string/strspn.o     \
	src/string/strstr.o     \
	src/string/strtok.o     \
	src/string/strxfrm.o    \
	src/time/asctime.o      \
	src/time/clock.o        \
	src/time/ctime.o        \
	src/time/difftime.o     \
	src/time/gmtime.o       \
	src/time/localtime.o    \
	src/time/mktime.o       \
	src/time/strftime.o     \
	src/time/time.o         \
	src/usys.o              \
	src/printf.o            \
	src/ulib.o              \
	src/umalloc.o           \

.PHONY: all
.PRECIOUS: src/%.o

all: $(DISTRIB_ULIBC)

src/%.o: src/%.c
	$(LOG_CC) $(CC) $(CFLAGS) -c -o $@ src/$*.c

src/%.o: src/%.S
	$(LOG_CC) $(CC) $(ASFLAGS) -c -o $@ src/$*.S

$(DISTRIB_ULIBC): $(DISTRIB_ULIBC_OBJECTS)
	$(LOG_LD) $(LD) $(LDFLAGS) -retain-symbols-file symbols.def -r $(DISTRIB_ULIBC_OBJECTS) -o $(DISTRIB_ULIBC)

clean:
	$(LOG_CMD) $(RM) -rf $(DISTRIB_ULIBC)
	$(LOG_CMD) $(RM) -rf $(DISTRIB_ULIBC_OBJECTS)
