#include "types.h"
#include "user.h"
#include "fcntl.h"

#define MAX 99999999999

int main(int argc, char *argv[])
{
    int num_of_child_processes = 10;
    if (argc == 2)
        num_of_child_processes = atoi(argv[1]);

    for (int i = 0; i < num_of_child_processes; i++)
    {
        int pid = fork();
        if (pid < 0)
        {
            printf(1, "Fork failed\n");
            exit();
        }
        if (pid == 0)
        {
            for(int i = 0 ; i < MAX ; i++)
                for(int j = 0; j < MAX ; j++)
                    for(int k = 0; k < MAX; k++)
                        ;
            exit();
        }
    }

    for(int i = 0; i < num_of_child_processes; i++)
        wait();

    exit();
}