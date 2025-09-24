/*
============================================================================
Name : 1c.c
Author : Mohammed Haris
Description :  FIFO (mkfifo Library Function or mknod system call) 
Date: 27th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
        int fd;
        fd=creat("mycreat.txt",0644);
        if(fd==-1) perror("create");
        else printf("File created with file discriptor: %d\n",fd);
        close(fd);
}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q2$ vim creat.c
haris@Haris:~/handson/Q2$ gcc creat.c -o creat
haris@Haris:~/handson/Q2$ ./creat
File created with file discriptor: 3
============================================================================
*/
