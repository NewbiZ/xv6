#ifndef CONSOLE_H
#define CONSOLE_H

enum CGACOLOR
{
  BLACK        = 0x00,
  BLUE         = 0x01,
  GREEN        = 0x02,
  CYAN         = 0x03,
  RED          = 0x04,
  MAGENTA      = 0x05,
  BROWN        = 0x06,
  LIGHTGRAY    = 0x07,
  DARKGRAY     = 0x08,
  LIGHTBLUE    = 0x09,
  LIGHTGREEN   = 0x0A,
  LIGHTCYAN    = 0x0B,
  LIGHTRED     = 0x0C,
  LIGHTMAGENTA = 0x0D,
  YELLOW       = 0x0E,
  WHITE        = 0x0F,
};

#define MAKECGACOLOR(FG,BG) ((BG<<4) | FG)

static unsigned char ANSI_COLOR_ESC0  = 0x1B;
static unsigned char ANSI_COLOR_ESC1  = '[';
static unsigned char ANSI_COLOR_DELIM = ';';
static unsigned char ANSI_COLOR_END   = 'm';

#endif // CONSOLE_H
