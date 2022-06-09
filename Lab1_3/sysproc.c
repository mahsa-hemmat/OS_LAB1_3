#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

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
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
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
    if(myproc()->killed){
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

int
sys_calculate_sum_of_digits(void)
{
  struct proc *curproc = myproc();
  int num = curproc->tf->edx;
  int sum_of_digits = 0;
  int remainder;

  while(num != 0)
  {
    remainder = num % 10;
    sum_of_digits = sum_of_digits + remainder;
    num = num / 10;
  }
  cprintf("Sum of digits : %d\n", sum_of_digits);
  return 0;
}

int
sys_get_parent_pid(void)
{
  get_parent_pid();
  return 0;
}

int
sys_set_process_parent(void)
{
  int pid;
  if(argint(0, &pid) < 0)
    return -1;
  set_process_parent(pid);
  return 0;
}

int
sys_get_children_pid(void)     //implemented just to check debugger parent
{
  int parent_pid;
  if(argint(0, &parent_pid) < 0)
    return -1;
  get_children_pid(parent_pid);
  return 0;
}

// added for lab3
int
sys_set_schedule_queue(void)
{
  int pid;
  int scheduler_queue;
  if(argint(0, &pid) < 0)
    return -1;
  if(argint(1, &scheduler_queue) < 0)
    return -1;
  set_schedule_queue(pid, scheduler_queue);
  return 1;
}

int
sys_set_HRRN_priority_proc(void)
{
  int pid;
  int priority;
  if(argint(0, &pid) < 0)
    return -1;
  if(argint(1, &priority) < 0)
    return -1;
  set_HRRN_priority_proc(pid, priority);
  return 1;
}

int
sys_set_HRRN_priority_sys(void)
{
  int priority;
  if(argint(0, &priority) < 0)
    return -1;
  set_HRRN_priority_sys(priority);
  return 1;
}

int
sys_print_info(void)
{
  print_info();
  return 1;
}