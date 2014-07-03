#ifndef ULIBC_SIGNAL_H
#define ULIBC_SIGNAL_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

typedef int sig_atomic_t;

#define SIG_DFL ((void (*)(int)) 0)
#define SIG_ERR ((void (*)(int)) 1)
#define SIG_IGN ((void (*)(int)) 2)

#define SIGINT   2
#define SIGILL   4
#define SIGABRT  6
#define SIGFPE   8
#define SIGSEGV 11
#define SIGTERM 15

void (*signal(int sig, void (*func)(int)))(int);
int raise(int sig);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // ULIBC_SIGNAL_H

