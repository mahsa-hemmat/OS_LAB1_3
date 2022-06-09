#include "types.h"
#include "user.h"
#include "fcntl.h"

int main(int argc,char *argv[])
{
    int number = atoi(argv[1]);
    int backup;

    printf(1,"The number is %d\n",number);
    
    // value in register edx is copied onto that register, 
    // and the value of "backup" is updated into the memory from this register
    __asm__("movl %%edx, %0" : "=r" (backup));   // output
    __asm__("movl %0, %%edx" : :"r" (number));   // input
    __asm__("movl $22, %eax");                   // system call number 22
    __asm__("int $64");
    __asm__("movl %0, %%edx" : : "r" (backup));
    exit();
}