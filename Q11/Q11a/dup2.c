/*
============================================================================
Name : 11(b)
Author : Mohammed Haris
Description :   Write a program to open a file, duplicate the file descriptor and append the file with both the 
descriptors and check whether the file is updated properly or not. 
a. use dup2
Date: 28th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include<string.h>

int main() {
    int fd, fd_dup2;

    fd = open("fileb.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);
    if (fd < 0) {
        perror("open");
    }

    fd_dup2 = dup2(fd, 10);
    if (fd_dup2 < 0) {
        perror("dup2");
    }

   const char *msg1 = "This is first line\n";
    const char *msg2 = "This is second line\n";

    write(fd, msg1, strlen(msg1));
    write(fd_dup2, msg2, strlen(msg2));

    close(fd);
    close(fd_dup2);

   fd = open("fileb.txt", O_RDONLY);

    printf("Checking the file update or not:\n");
    char buffer[100];
    int n;
    while ((n = read(fd, buffer, sizeof(buffer)-1)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(fd);
}

/*
============================================================================
OUTPUT 10(b)

haris@Haris:~/handson/Q11/Q11a$ vim dup2.c
haris@Haris:~/handson/Q11/Q11a$ touch fileb.txt
haris@Haris:~/handson/Q11/Q11a$ gcc dup2.c -o dup2
haris@Haris:~/handson/Q11/Q11a$ ./dup2
Checking the file update or not:
This is first line
This is second line
============================================================================
*/
