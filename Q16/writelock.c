
/*
============================================================================
Name : 16(a)
Author : Mohammed Haris
Description : Write a program to perform mandatory locking. 
a. Implement write lock 
Date: 02 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_WRONLY);
    struct flock wlk;

    wlk.l_type = F_WRLCK;
    wlk.l_whence = SEEK_SET;
    wlk.l_start = 0;
    wlk.l_len = 0;

    fcntl(fd, F_SETLKW, &wlk);
    printf("File locked. Press Enter to unlock...\n");
    getchar();

    wlk.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &wlk);

}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q16$ vim lock.c
haris@Haris:~/handson/Q16$ gcc lock.c -o lock
haris@Haris:~/handson/Q16$ ./lock
File locked. Press Enter to unlock...

=================================================
*/
