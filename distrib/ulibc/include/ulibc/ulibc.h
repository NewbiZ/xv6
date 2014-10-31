struct stat;

// system calls
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

//void         __ulibc_printf(int, char*, ...);
//void*        __ulibc_memset(void*, int, unsigned int);
void*        __ulibc_malloc(unsigned int);
//char*        __ulibc_strchr(const char*, char c);
//unsigned int __ulibc_strlen(char*);
int          __ulibc_stat(char*, struct stat*);
//char*        __ulibc_strcpy(char*, char*);
//void*        __ulibc_memmove(void*, void*, int);
//int          __ulibc_strcmp(const char*, const char*);
char*        __ulibc_gets(char*, int max);
void         __ulibc_free(void*);
int          __ulibc_atoi(const char*);
