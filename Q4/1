/*
============================================================================
Name : 4
Author : Mohammed Haris
Description :  Write a program to open an existing file with read write mode. Try O_EXCL flag also.  
Date: 27th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
        int fd=open("creat.txt",O_RDWR | O_CREAT | O_EXCL, 0666);
        if(fd==-1) perror("O_EXCL");
        else{
                printf("file created successfully with fd value: %d\n",fd);
                close(fd);
        }
}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q4$ vim open.c
haris@Haris:~/handson/Q4$ gcc open.c -o open
haris@Haris:~/handson/Q4$ ./open
file created successfully with fd value: 3
haris@Haris:~/handson/Q4$ gcc open.c -o open
haris@Haris:~/handson/Q4$ ./open
O_EXCL: File exists
============================================================================
*/
