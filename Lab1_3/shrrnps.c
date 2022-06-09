#include "types.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf(1 , "Not enough arguments\n");
        exit();
    }
    set_HRRN_priority_sys(atoi(argv[1]));
    exit();
}