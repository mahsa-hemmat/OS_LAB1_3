#include "types.h"
#include "user.h"
#include "fcntl.h"

void 
save_num(int num, char *name)
{
    int fd;
    uint *addrs = {0};
    fd = open(name, O_CREATE |  O_RDWR);
    
    for(int i=1; i < num; i++)
       printf(fd, "%d ,", i);
    printf(fd, "%d\n", num);
    int n = get_file_sectors(fd, addrs);
    for(int i=0;i<n;i++) 
        printf(1, "sector%d addr : %d\n", i+1, addrs[i]);
}

int 
main()
{
    save_num(400, "f0");
    write(1, "\n", 1);
    save_num(700, "f1");
    write(1, "\n", 1);
    save_num(1000, "f2");
    exit();

}