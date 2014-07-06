#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <assert.h>

#define stat xv6_stat  // avoid clash with host struct stat
#include <xv6/types.h>
#include <xv6/fs.h>
#include <xv6/stat.h>
#include <xv6/param.h>
#include <xv6/dirent.h>
#include <xv6/stdio.h>

#define static_assert(a, b) do { switch (0) case 0: case (a): ; } while (0)

int nblocks = 4056;
//int nblocks = 2009;
int nlog = LOGSIZE;
int ninodes = 200;
//int size = 2048;
int size = 4096;

int fsfd;
struct superblock sb;
char zeroes[512];
uint freeblock;
uint usedblocks;
uint bitblocks;
uint freeinode = 1;

void balloc(int);
void wsect(uint, void*);
void winode(uint, struct dinode*);
void rinode(uint inum, struct dinode *ip);
void rsect(uint sec, void *buf);
uint ialloc(ushort type);
void iappend(uint inum, void *p, int n);

// Convert to intel byte order
ushort xshort(ushort x)
{
  ushort y;
  uchar *a = (uchar*)&y;
  a[0] = x;
  a[1] = x >> 8;

  return y;
}

// Convert to intel byte order
uint xint(uint x)
{
  uint y;
  uchar *a = (uchar*)&y;
  a[0] = x;
  a[1] = x >> 8;
  a[2] = x >> 16;
  a[3] = x >> 24;

  return y;
}

// Create a directory and attach it to the provided inode number
uint create_dir(uint inoparent, const char* path)
{
  struct dirent de;
  int inocurrent;

  // Create directory entry
  inocurrent = ialloc(T_DIR);
  bzero(&de, sizeof(de));
  de.d_ino = inocurrent;
  strcpy(de.d_name, path);
  iappend(inoparent, &de, sizeof(de));

  // Create parent directory link
  bzero(&de, sizeof(de));
  de.d_ino = inocurrent;
  strcpy(de.d_name, ".");
  iappend(inocurrent, &de, sizeof(de));

  // Create current directory link
  bzero(&de, sizeof(de));
  de.d_ino = inoparent;
  strcpy(de.d_name, "..");
  iappend(inocurrent, &de, sizeof(de));

  return inocurrent;
}

// Copy file from local filesystem to distribution image. Basename is used.
void copy_file(uint parentino, const char* file)
{
  char buf[512];
  int cc;
  struct dirent de;
  uint ino = ialloc(T_FILE);
  bzero(&de, sizeof(de));
  de.d_ino = ino;
  strcpy(de.d_name, strrchr(file, '/')+1);
  iappend(parentino, &de, sizeof(de));

  int fd = open(file, 0);

  while ((cc = read(fd, buf, sizeof(buf))) > 0)
    iappend(ino, buf, cc);

  close(fd);
}

// Copy all coreutils binaries. /bin inode number should be provided
void copy_coreutils(uint binino)
{
  copy_file(binino, "coreutils/cat");
  copy_file(binino, "coreutils/chgrp");
  copy_file(binino, "coreutils/chmod");
  copy_file(binino, "coreutils/chown");
  copy_file(binino, "coreutils/cp");
  copy_file(binino, "coreutils/date");
  copy_file(binino, "coreutils/dd");
  copy_file(binino, "coreutils/df");
  copy_file(binino, "coreutils/dmesg");
  copy_file(binino, "coreutils/echo");
  copy_file(binino, "coreutils/false");
  copy_file(binino, "coreutils/halt"); // Not FHS
  copy_file(binino, "coreutils/hostname");
  copy_file(binino, "coreutils/kill");
  copy_file(binino, "coreutils/ln");
  copy_file(binino, "coreutils/login");
  copy_file(binino, "coreutils/ls");
  copy_file(binino, "coreutils/mkdir");
  copy_file(binino, "coreutils/mknod");
  copy_file(binino, "coreutils/more");
  copy_file(binino, "coreutils/mount");
  copy_file(binino, "coreutils/mv");
  copy_file(binino, "coreutils/ps");
  copy_file(binino, "coreutils/pwd");
  copy_file(binino, "coreutils/rm");
  copy_file(binino, "coreutils/rmdir");
  copy_file(binino, "coreutils/sed");
  copy_file(binino, "coreutils/sh");
  copy_file(binino, "coreutils/stty");
  copy_file(binino, "coreutils/su");
  copy_file(binino, "coreutils/sync");
  copy_file(binino, "coreutils/true");
  copy_file(binino, "coreutils/umount");
  copy_file(binino, "coreutils/uname");
}

// Create the while Filesystem Hierarchy Standard (FHS)
int create_fhs(uint rootino)
{
  int binino = create_dir(rootino, "bin");
  create_dir(rootino, "boot");
  create_dir(rootino, "dev");
  create_dir(rootino, "etc");
  create_dir(rootino, "home");
  create_dir(rootino, "lib");
  create_dir(rootino, "media");
  create_dir(rootino, "mnt");
  create_dir(rootino, "opt");
  create_dir(rootino, "root");
  int sbinino = create_dir(rootino, "sbin");
  create_dir(rootino, "srv");
  create_dir(rootino, "tmp");
  create_dir(rootino, "usr");
  create_dir(rootino, "var");

  copy_coreutils(binino);

  return sbinino;
}

void create_tests(uint rootino)
{
  copy_file(rootino, "tests/stdlib");
  copy_file(rootino, "tests/string");
}

void create_init(uint sbinino, const char* file)
{
  copy_file(sbinino, file);
}

int main(int argc, char *argv[])
{
  int i;
  uint rootino, off;
  struct dirent de;
  char buf[512];
  struct dinode din;

  static_assert(sizeof(int) == 4, "Integers must be 4 bytes!");

  if(argc != 3)
  {
    fprintf(stderr, "Usage: mkfs.xv6 <image name> <test|release>\n");
    exit(1);
  }

  assert((512 % sizeof(struct dinode)) == 0);
  assert((512 % sizeof(struct dirent)) == 0);

  fsfd = open(argv[1], O_RDWR|O_CREAT|O_TRUNC, 0666);
  if(fsfd < 0){
    perror(argv[1]);
    exit(1);
  }

  sb.size = xint(size);
  sb.nblocks = xint(nblocks); // so whole disk is size sectors
  sb.ninodes = xint(ninodes);
  sb.nlog = xint(nlog);

  bitblocks = size/(512*8) + 1;
  usedblocks = ninodes / IPB + 3 + bitblocks;
  freeblock = usedblocks;

  if (1)
  {
    printf("used %d (bit %d ninode %zu) free %u log %u total %d\n", usedblocks,
           bitblocks, ninodes/IPB + 1, freeblock, nlog, nblocks+usedblocks+nlog);
  }

  assert(nblocks + usedblocks + nlog == size);

  for(i = 0; i < nblocks + usedblocks + nlog; i++)
    wsect(i, zeroes);

  memset(buf, 0, sizeof(buf));
  memmove(buf, &sb, sizeof(sb));
  wsect(1, buf);

  rootino = ialloc(T_DIR);
  assert(rootino == ROOTINO);

  bzero(&de, sizeof(de));
  de.d_ino = xshort(rootino);
  strcpy(de.d_name, ".");
  iappend(rootino, &de, sizeof(de));

  bzero(&de, sizeof(de));
  de.d_ino = xshort(rootino);
  strcpy(de.d_name, "..");
  iappend(rootino, &de, sizeof(de));

  if (!strcmp(argv[2], "release"))
  {
    int sbinino = create_fhs(rootino);
    create_init(sbinino, "coreutils/init");
  }
  else if (!strcmp(argv[2], "test"))
  {
    int sbinino = create_fhs(rootino);
    create_tests(rootino);
    create_init(sbinino, "tests/init");
  }

  // fix size of root inode dir
  rinode(rootino, &din);
  off = xint(din.size);
  off = ((off/BSIZE) + 1) * BSIZE;
  din.size = xint(off);
  winode(rootino, &din);

  balloc(usedblocks);

  exit(0);
}

void wsect(uint sec, void *buf)
{
  if(lseek(fsfd, sec * 512L, 0) != sec * 512L){
    perror("lseek");
    exit(1);
  }
  if(write(fsfd, buf, 512) != 512){
    perror("write");
    exit(1);
  }
}

uint i2b(uint inum)
{
  return (inum / IPB) + 2;
}

void
winode(uint inum, struct dinode *ip)
{
  char buf[512];
  uint bn;
  struct dinode *dip;

  bn = i2b(inum);
  rsect(bn, buf);
  dip = ((struct dinode*)buf) + (inum % IPB);
  *dip = *ip;
  wsect(bn, buf);
}

void rinode(uint inum, struct dinode *ip)
{
  char buf[512];
  uint bn;
  struct dinode *dip;

  bn = i2b(inum);
  rsect(bn, buf);
  dip = ((struct dinode*)buf) + (inum % IPB);
  *ip = *dip;
}

void rsect(uint sec, void *buf)
{
  if(lseek(fsfd, sec * 512L, 0) != sec * 512L){
    perror("lseek");
    exit(1);
  }
  int r = read(fsfd, buf, 512);
  if(r != 512){
    perror("read");
    exit(1);
  }
}

uint ialloc(ushort type)
{
  uint inum = freeinode++;
  struct dinode din;

  bzero(&din, sizeof(din));
  din.type = xshort(type);
  din.nlink = xshort(1);
  din.size = xint(0);
  winode(inum, &din);
  return inum;
}

void balloc(int used)
{
  uchar buf[512];
  int i;

  if (0)
    printf("balloc: first %d blocks have been allocated\n", used);
  assert(used < 512*8);
  bzero(buf, 512);
  for(i = 0; i < used; i++){
    buf[i/8] = buf[i/8] | (0x1 << (i%8));
  }
  if (0)
    printf("balloc: write bitmap block at sector %zu\n", ninodes/IPB + 3);
  wsect(ninodes / IPB + 3, buf);
}

#define min(a, b) ((a) < (b) ? (a) : (b))

void iappend(uint inum, void *xp, int n)
{
  char *p = (char*)xp;
  uint fbn, off, n1;
  struct dinode din;
  char buf[512];
  uint indirect[NINDIRECT];
  uint x;

  rinode(inum, &din);

  off = xint(din.size);
  while(n > 0){
    fbn = off / 512;
    assert(fbn < MAXFILE);
    if(fbn < NDIRECT){
      if(xint(din.addrs[fbn]) == 0){
        din.addrs[fbn] = xint(freeblock++);
        usedblocks++;
      }
      x = xint(din.addrs[fbn]);
    } else {
      if(xint(din.addrs[NDIRECT]) == 0){
        // printf("allocate indirect block\n");
        din.addrs[NDIRECT] = xint(freeblock++);
        usedblocks++;
      }
      // printf("read indirect block\n");
      rsect(xint(din.addrs[NDIRECT]), (char*)indirect);
      if(indirect[fbn - NDIRECT] == 0){
        indirect[fbn - NDIRECT] = xint(freeblock++);
        usedblocks++;
        wsect(xint(din.addrs[NDIRECT]), (char*)indirect);
      }
      x = xint(indirect[fbn-NDIRECT]);
    }
    n1 = min(n, (fbn + 1) * 512 - off);
    rsect(x, buf);
    bcopy(p, buf + off - (fbn * 512), n1);
    wsect(x, buf);
    n -= n1;
    off += n1;
    p += n1;
  }
  din.size = xint(off);
  winode(inum, &din);
}

