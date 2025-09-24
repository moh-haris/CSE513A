/*
============================================================================
Name : 11(a)
Author : Mohammed Haris
Description :   Write a program to open a file, duplicate the file descriptor and append the file with both the 
descriptors and check whether the file is updated properly or not. 
a. use dup 
Date: 28th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd, fd_dup;

    fd = open("filea.txt", O_WRONLY | O_CREAT | O_APPEND, 0666);
    if (fd < 0) 
        perror("open");
        
   fd_dup = dup(fd);
    if (fd_dup < 0) 
        perror("dup");
    
    write(fd, "This is first line\n", 19);
    write(fd_dup, "This is second line\n", 20);

     fd = open("filea.txt", O_RDONLY);

    printf("Checking the file update or not:\n");
    char buffer[100];
    int n;
    while ((n = read(fd, buffer, sizeof(buffer)-1)) > 0) {
        buffer[n] = '\0'; 
        printf("%s", buffer);
    }

    close(fd);
    close(fd_dup);
}

/*
============================================================================
OUTPUT 10(a)

haris@Haris:~/handson/Q11/Q11a$ vim dup.c
haris@Haris:~/handson/Q11/Q11a$ touch filea.txt
haris@Haris:~/handson/Q11/Q11a$ gcc dup.c -o dup
haris@Haris:~/handson/Q11/Q11a$ ./dup
Contents of filea.txt:
This is first line
This is second line
============================================================================
*/
