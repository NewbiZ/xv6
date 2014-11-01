#ifndef ULIBC_STDDEF_H
#define ULIBC_STDDEF_H

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifndef ULIBC_SIZE_T
#define ULIBC_SIZE_T
typedef unsigned int size_t;
#endif /* ULIBC_SIZE_T */

#ifdef __cplusplus
#define NULL 0L
#else /* __cplusplus */
#define NULL ((void*)0)
#endif /* __cplusplus */

typedef int prtdiff_t;
typedef char wchar_t;

#define offsetof(type, member) ((size_t)&(((type*)0)->member))

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* ULIBC_STDDEF_H */

