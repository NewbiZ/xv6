#ifndef ULIBC_STDARG_H
#define ULIBC_STDARG_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// Requires gcc >= 3

typedef __builtin_va_list va_list;

#define va_start(l, p)  __builtin_va_start(l, p)
#define va_arg(l, t)    __builtin_va_arg(l, t)
#define va_end(l)       __builtin_va_end(l)

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // ULIBC_STDARG_H

