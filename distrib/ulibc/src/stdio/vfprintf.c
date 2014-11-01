#include <stdio.h>
#include <stdarg.h>
#include <assert.h>

static void __fputi(FILE* f, int value, int base, int signd, int upper)
{
  static const char digits_upper[] = "0123456789ABCDEF";
  static const char digits_lower[] = "0123456789abcdef";
  const char* digits = upper ? digits_upper : digits_lower;
  char buf[16];
  int i;
  int negative;
  unsigned int x;

  negative = 0;
  if (signd && (value < 0))
  {
    negative = 1;
    x = -value;
  }
  else
  {
    x = value;
  }

  i = 0;
  do
  {
    buf[i++] = digits[x % base];
  }
  while((x /= base) != 0);

  if (negative)
    buf[i++] = '-';

  while (--i >= 0)
    fputc(buf[i], f);
}

int vfprintf(FILE* f, const char* format, va_list ap)
{
  /* specifier: c, d, i */
  int a_cdi;
  /* specifier: o, u, x, X */
  unsigned int a_ouxX;
  /* TODO: Handle doubles in fprintf */
  /* specifier: e, E, f, F, g, G */
  /* double a_eEfFgG; */
  /* specifier: s */
  const char* a_s;
  char c;
  /* specifier: p */
  const void* a_p;

  while(*format)
  {
    if (*format!='%')
      fputc(*format, f);
    else
    {
      switch (*++format)
      {
        case 'c':
          a_cdi = va_arg(ap, int);
          fputc(a_cdi, f);
          break;
        case 'd':
        case 'i':
          a_cdi = va_arg(ap, int);
          __fputi(f, a_cdi, 10, 1, 0);
          break;
        case 'o':
          a_ouxX = va_arg(ap, unsigned int);
          __fputi(f, a_ouxX, 8, 0, 0);
          break;
        case 'u':
          a_ouxX = va_arg(ap, unsigned int);
          __fputi(f, a_ouxX, 10, 0, 0);
          break;
        case 'x':
          a_ouxX = va_arg(ap, unsigned int);
          __fputi(f, a_ouxX, 16, 0, 0);
          break;
        case 'X':
          a_ouxX = va_arg(ap, unsigned int);
          __fputi(f, a_ouxX, 16, 0, 1);
          break;
        case 'e':
        case 'E':
        case 'f':
        case 'F':
        case 'g':
        case 'G':
          assert(0 && "error: format specifiers eEfFgG not implemented yet.");
          break;
        case 's':
          a_s = va_arg(ap, const char*);
          while ((c = *a_s++))
            fputc(c, f);
          break;
        case 'p':
          a_p = va_arg(ap, const void*);
          __fputi(f, (unsigned int)a_p, 16, 0, 0);
          break;
        case '%':
          fputc('%', f);
          break;
      }
    }
    ++format;
  }

  return 0;
}

