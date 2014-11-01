#ifndef ULIBC_STDDEF_H
#define ULIBC_STDDEF_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef ULIBC_SIZE_T
#define ULIBC_SIZE_T
typedef unsigned int size_t;
#endif /* ULIBC_SIZE_T */

typedef int prtdiff_t;
typedef char wchar_t;

#define NULL 0L

#define offsetof(type, member) ((size_t)&(((type*)0)->member))

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ULIBC_STDDEF_H */

