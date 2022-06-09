#include "types.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char* argv[])
{
    int pid = getpid();
    if(argc <= 1)
    {
        printf(1, "Please Insert a process Pid\n");
        exit();
    }
    set_process_parent(atoi(argv[1]));
    get_children_pid(pid);
    exit();
}