#include <locale.h>
#include <limits.h>

static struct lconv c_lconv = {
  ".",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  "",
  CHAR_MAX,
  CHAR_MAX,
  CHAR_MAX,
  CHAR_MAX,
  CHAR_MAX,
  CHAR_MAX,
  CHAR_MAX,
  CHAR_MAX,
};

struct lconv* localeconv(void)
{
  return &c_lconv;
}

