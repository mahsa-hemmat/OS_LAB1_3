#include "types.h"
#include "user.h"
#include "fcntl.h"

void 
save_factor(int num)
{
    int fd;
    char *name = "factor_result.txt";
    fd = open(name, O_RDWR);

    if (fd<0)     // if file does not exist, make one
        fd = open(name, O_CREATE |  O_RDWR);
    else{
        unlink(name);     // if file already exist, unlink 
        fd = open(name, O_CREATE |  O_RDWR);
    }
    
    if (fd < 0) 
    {
        printf(1, "cat: cannot open %s\n", name);
        exit();
    }

    for(int i=1; i <= num/2; i++)
    {
        if(num % i == 0)
        {

            printf(fd, "%d ", i);
        }
    }
    printf(fd, "%d\n", num);
}

int 
main(int argc, char* argv[])
{
    if(argc <= 1)
    {
        printf(1, "Please Insert a Number after factor\n");
        exit();
    }
    else
    {
        int num = atoi(argv[1]);
        save_factor(num);
        exit();
    }
}
