/*
============================================================================
Name : 22
Author : Mohammed Haris
Description :  Write a program, open a file, call fork, and then write to the file by both the child as well as the 
parent processes. Check output of the file.
Date: 04 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main() {
    int fd;
    pid_t pid;
    char buf[64];


    fd = open("output.txt", O_CREAT | O_RDWR | O_TRUNC, 0666);
    if (fd < 0) perror("open");
     

    if (!fork()) {
        snprintf(buf, sizeof(buf), "Child process PID %d\n", getpid());
        write(fd, buf, strlen(buf));
    } else {
        snprintf(buf, sizeof(buf), "Parent process PID %d\n", getpid());
        write(fd, buf, strlen(buf));
    }

    close(fd);
}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q22$ vim fork.c
haris@Haris:~/handson/Q22$ touch output.txt
haris@Haris:~/handson/Q22$ gcc fork.c -o fork
haris@Haris:~/handson/Q22$ ./fork
haris@Haris:~/handson/Q22$ cat output.txt
Parent process PID 1319
Child process PID 1320

=================================================
*/
