#ifndef ULIBC_ASSERT_H
#define ULIBC_ASSERT_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

#ifdef NDEBUG
#   define assert(ignore) ((void)0)
#else // NDEBUG
#   define assert(c) if (!(c)) { __ulibc_assert(#c, __FILE__, __LINE__); }
#endif // NDEBUG

void __ulibc_assert(const char* c, const char* file, int line);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // ULIBC_ASSERT_H

