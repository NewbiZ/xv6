#ifndef ULIBC_SYSCALL_H
#define ULIBC_SYSCALL_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

struct stat;

int fork(void);
int sysexit(void) __attribute__((noreturn));
int wait(void);
int pipe(int*);
int write(int, const void*, int);
int read(int, void*, int);
int close(int);
int kill(int);
int exec(char*, char**);
int open(const char*, int);
int mknod(char*, short, short);
int unlink(char*);
int fstat(int fd, struct stat*);
int link(char*, char*);
int mkdir(char*);
int chdir(char*);
int dup(int);
int getpid(void);
char* sbrk(int);
int sleep(int);
int uptime(void);
int getcwd(char* buf, int size);
int halt(void);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // ULIBC_SYSCALL_H
