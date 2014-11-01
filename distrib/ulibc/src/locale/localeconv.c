#include <locale.h>
#include <limits.h>

static struct lconv __c_lconv = {
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
  return &__c_lconv;
}

