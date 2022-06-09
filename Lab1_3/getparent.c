#include "types.h"
#include "user.h"
#include "fcntl.h"

int main()
{

    int proc = fork();
    if(proc<0)
        exit();
    else if(proc == 0)
    {
        get_parent_pid();
    }
    else
        wait();

    exit();
}