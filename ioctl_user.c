#include <stdio.h>
#include <stdlib.h> /* EXIT_FALIURE/SUCCESS */
#include <unistd.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <fcntl.h>
#include "ioctl_user.h"

int main(int argc, char **argv)
{
    char *ioctl_path = "/dev/char_dev_ioctl";
    int request, arg0, arg1;
    int fd,ret;

    if (argc < 2)
    {
        puts("Usage: ./prog <request> [<args>...]");
        return EXIT_FAILURE;
    }
    request = strtol(argv[1], NULL, 10);
    if (argc > 2)
    {
        arg0 = strtol(argv[2], NULL, 10);
    }
    if (argc > 3)
    {
        arg0 = strtol(argv[3], NULL, 10);
    }
    fd = open(ioctl_path, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return EXIT_FAILURE;
    }
    switch (request)
    {
    case 0:
        ret = ioctl(fd, MY_IOCTL_INC, &arg0);
        if (ret != -1)
        {
            printf("increment result is %d\n", arg0);
        }
        break;
    default:
        puts("error: unknown request");
        return EXIT_FAILURE;
    }
}