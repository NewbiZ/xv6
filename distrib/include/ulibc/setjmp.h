#ifndef ULIBC_SETJMP_H
#define ULIBC_SETJMP_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef unsigned int jmp_buf[6];

int setjmp(jmp_buf env);
void longjmp(jmp_buf env, int val);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // ULIBC_SETJMP_H

