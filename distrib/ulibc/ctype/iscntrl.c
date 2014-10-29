#include <ulibc/ctype.h>

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

