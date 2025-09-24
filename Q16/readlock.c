
/*
============================================================================
Name : 16(b)
Author : Mohammed Haris
Description : Write a program to perform mandatory locking. 
b. Implement read lock 
Date: 02 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDONLY);
    struct flock rlk;

    rlk.l_type = F_RDLCK;    
    rlk.l_whence = SEEK_SET;
    rlk.l_start = 0;
    rlk.l_len = 0;

    fcntl(fd, F_SETLKW, &rlk);
    printf("File locked for reading. Press Enter\n");
    getchar();
    getchar();

    rlk.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &rlk);
}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q16$ vim readlock.c
haris@Haris:~/handson/Q16$ gcc readlock.c -o readlock
haris@Haris:~/handson/Q16$ ./readlock
File locked for reading. Press Enter

=================================================
*/
