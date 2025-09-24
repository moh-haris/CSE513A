/*
============================================================================
Name : 12
Author : Mohammed Haris
Description :   Write a program to find out the opening mode of a file. Use fcntl.
Date: 29th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("mode.txt", O_RDWR);  
    if (fd == -1) {
        perror("open");
      
    }

   int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("fcntl");
        close(fd);
       

    }

int mode = flags & O_ACCMODE;

    if (mode == O_RDONLY)
        printf("File is opened in read-only mode\n");
    else if (mode == O_WRONLY)
        printf("File is opened in write-only mode\n");
    else if (mode == O_RDWR)
        printf("File is opened in read-write mode\n");

    close(fd);
    
}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q10$ touch mode.txt
haris@Haris:~/handson/Q10$ echo "Hello world" > mode.txt
haris@Haris:~/handson/Q10$ vim mode.c
haris@Haris:~/handson/Q10$ gcc mode.c -o mode
haris@Haris:~/handson/Q10$ ./mode
File is opened in read-write mode
haris@Haris:~/handson/Q10$=================================================
*/
