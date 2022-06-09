#include "types.h"
#include "user.h"
#include "fcntl.h"


int main()
{
    get_parent_pid();
    sleep(1000);
    get_parent_pid();
    exit();
}
