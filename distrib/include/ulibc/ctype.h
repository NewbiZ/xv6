#ifndef ULIBC_CTYPE_H
#define ULIBC_CTYPE_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// Only standard C locale is considered here

int isalnum(int c);
int isalpha(int c);
int iscntrl(int c);
int isdigit(int c);
int isgraph(int c);
int islower(int c);
int isupper(int c);
int isprint(int c);
int ispunct(int c);
int isspace(int c);
int isxdigit(int c);

int tolower(int c);
int toupper(int c);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // ULIBC_CTYPE_H

