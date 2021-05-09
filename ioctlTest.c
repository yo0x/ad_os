#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <fcntl.h>

struct winsize window_size;
int main(){
    int fd = open("/dev/stdout", 0_RDWR);
    if(ioctl (fd, TIOCGWINSZ, &window_size)==0)
    {
        print("screenwidth %d\n", window_size.ws_col);
        print("screenwidth %d\n", window_size.ws_row);
    }
    return 0;
}
