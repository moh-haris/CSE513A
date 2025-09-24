/*
============================================================================
Name : 11(c)
Author : Mohammed Haris
Description :   Write a program to open a file, duplicate the file descriptor and append the file with both the 
descriptors and check whether the file is updated properly or not. 
c. use fcntl
Date: 28th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd, fd_fcntl;

   fd = open("filec.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);
    if (fd < 0) perror("open");
      
fd_fcntl = fcntl(fd, F_DUPFD, 0);
    if (fd_fcntl < 0) perror("fcntl");
        
 write(fd, "This is first line\n", 19);
    write(fd_fcntl, "This is second line\n", 20);

   close(fd);
    close(fd_fcntl);

fd = open("filec.txt", O_RDONLY);
    if (fd < 0) perror("open for reading");

    printf("Checking the file update or not:\n");
    char buffer[100];
    int n;
    while ((n = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(fd);
   
}

/*
============================================================================
OUTPUT 11(c)

haris@Haris:~/handson/Q11/Q11c$ vim fcntl.c
haris@Haris:~/handson/Q11/Q11c$ gcc fcntl.c -o fcntl
haris@Haris:~/handson/Q11/Q11c$ ./fcntl
Checking the file update or not:
This is first line
This is second line
============================================================================
*/


