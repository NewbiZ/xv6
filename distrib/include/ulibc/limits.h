#ifndef ULIBC_LIMITS_H
#define ULIBC_LIMITS_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// char
#define CHAR_MIN (-128)
#define CHAR_MAX 127

#define SCHAR_MIN (-128)
#define SCHAR_MAX 127

#define UCHAR_MAX 255

#define CHAR_BIT 8

// short
#define SHRT_MIN  (-1-0x7fff)
#define SHRT_MAX  0x7fff
#define USHRT_MAX 0xffff

// int
#define INT_MIN  (-1-0x7fffffff)
#define INT_MAX  0x7fffffff
#define UINT_MAX 0xffffffffU

// long
#define LONG_MAX 0x7fffffffL
#define LONG_MIN (-LONG_MAX-1)
#define ULONG_MAX (2UL*LONG_MAX+1)

// long long
#define LLONG_MAX 0x7fffffffffffffffLL
#define LLONG_MIN (-LLONG_MAX-1)
#define ULLONG_MAX (2ULL*LLONG_MAX+1)

// wchar
#define MB_LEN_MAX 4

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // ULIBC_LIMITS_H

