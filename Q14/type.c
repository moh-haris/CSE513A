/*
============================================================================
Name : 14
Author : Mohammed Haris
Description :  Write a program to find the type of a file.
              a. Input should be taken from command line.
              b. program should be able to identify any type of a file.
Date: 28th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    
    struct stat info;
    if (lstat(argv[1], &info) != 0) {
        perror("stat");
        return 1;
    }

    if (S_ISREG(info.st_mode)) printf("Regular file\n");
    else if (S_ISDIR(info.st_mode)) printf("Directory\n");
    else if (S_ISLNK(info.st_mode)) printf("Symbolic link\n");
    else if (S_ISCHR(info.st_mode)) printf("Character device\n");
    else if (S_ISBLK(info.st_mode)) printf("Block device\n");
    else if (S_ISFIFO(info.st_mode)) printf("FIFO/pipe\n");
    else if (S_ISSOCK(info.st_mode)) printf("Socket\n");
    else printf("Unknown type\n");

    return 0;
}


/*
============================================================================
OUTPUT 14

haris@Haris:~/handson/Q14$ touch file.txt
haris@Haris:~/handson/Q14$ gcc type.c -o type
haris@Haris:~/handson/Q14$ ./type file.txt
Regular file
haris@Haris:~/handson/Q14$ mkdir doc
haris@Haris:~/handson/Q14$ ./type doc
Directory
haris@Haris:~/handson/Q14$ mkfifo mypipe
haris@Haris:~/handson/Q14$ ./type mypipe
FIFO/pipe
haris@Haris:~/handson/Q14$ ln -s file.txt symfile
haris@Haris:~/handson/Q14$ ./type symfile
Symbolic link
============================================================================
*/
