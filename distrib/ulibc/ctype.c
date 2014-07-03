#include <ulibc/ctype.h>

int isalnum(int c)
{
  return isalpha(c) || isdigit(c);
}

int isalpha(int c)
{
  return islower(c) || isupper(c);
}

int iscntrl(int c)
{
  // Control characters:
  // NUL, DLE, SOH, DC1, STX, DC2, ETX, DC3
  // EOT, DC4, ENQ, NAK, ACK, SYN, BEL, ETB
  // BS,  CAN, TAB, EM,  LF,  SUB, VT,  ESC
  // FF,  FS,  CR,  GS,  SO,  RS,  SI,  US
  // DEL
  return (c>=0x00 && c<=0x1F) || c==0x7F;
}

int isdigit(int c)
{
  return c>='0' && c<='9';
}

int isgraph(int c)
{
  return c>='!' && c<='~';
}

int islower(int c)
{
  return c>='a' && c<='z';
}

int isupper(int c)
{
  return c>='A' && c<='Z';
}

int isprint(int c)
{
  return c>=' ' && c<='~';
}

int ispunct(int c)
{
  return isgraph(c) && !isalnum(c);
}

int isspace(int c)
{
  return c==' ' || c=='\f' || c=='\n' || c=='\r' || c=='\t' || c=='\v';
}

int isxdigit(int c)
{
  return isdigit(c) || (c>='a' && c<='f') || (c>='A' && c<='F');
}

int tolower(int c)
{
  return isupper(c) ? c-'A'+'a' : c;
}

int toupper(int c)
{
  return islower(c) ? c-'a'+'A' : c;
}

