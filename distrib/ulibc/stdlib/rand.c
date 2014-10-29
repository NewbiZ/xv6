#include <ulibc/stdlib.h>

#include <ulibc/ulibc.h>
#include <ulibc/ctype.h>
#include <ulibc/assert.h>

// XOR shift 128, from Marsaglia, George: http://www.jstatsoft.org/v08/i14/paper
// Maximal entropy: 2^128-1
static unsigned int __ulibc_srand_seed_x;
static unsigned int __ulibc_srand_seed_y;
static unsigned int __ulibc_srand_seed_z;
static unsigned int __ulibc_srand_seed_w;

void srand(unsigned int seed)
{
  __ulibc_srand_seed_x = seed;
}

int rand(void)
{
  unsigned int t = (__ulibc_srand_seed_x^(__ulibc_srand_seed_x<<11));
  __ulibc_srand_seed_x = __ulibc_srand_seed_y;
  __ulibc_srand_seed_y = __ulibc_srand_seed_z;
  __ulibc_srand_seed_z = __ulibc_srand_seed_w;
  __ulibc_srand_seed_w = (__ulibc_srand_seed_w^(__ulibc_srand_seed_w>>19))^(t^(t>>8));
  return __ulibc_srand_seed_w % RAND_MAX;
}

