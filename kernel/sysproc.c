#include <types.h>
#include <x86.h>
#include <defs.h>
#include <param.h>
#include <memlayout.h>
#include <mmu.h>
#include <proc.h>
#include <fs.h>
#include <file.h>

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return proc->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = proc->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;
  
  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(proc->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;
  
  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

// copy the current working directory in the provided buffer
int
sys_getcwd(void)
{
    // Retrieve syscall arguments
    char *buf;
    int size;
    struct inode *ip;
    struct inode *pip;
    struct dirent pde;
    uint offset = 2;
    if (argint(1, &size) < 0 || argptr(0, &buf, size) < 0)
        return -1;
    // Climb up the nodes until we hit the root, keeping track
    // of all dirents on the way.
    ip = idup(proc->cwd);
    ilock(ip);
    if (ip->inum == ROOTINO){
      // This is the root / inode
      strncpy(buf, "/", sizeof(buf));
    }
    else{
      // Retrieve the parent inode
      if (readi(ip, (char*)&pde, sizeof(pde), sizeof(pde)) != sizeof(pde))
        return -1;
      pip = iget(ROOTDEV, pde.inum);
      ilock(pip);
      while(readi(pip, (char*)&pde, sizeof(pde)*offset, sizeof(pde)) == sizeof(pde)){
        ++offset;
        if (ip->inum == de.inum){
          strncpy(buf, pde.name, sizeof(buf));
          break;
        }
      }
      iunlockput(pip);
    }
    iunlockput(ip);
    return 0;
}
    
