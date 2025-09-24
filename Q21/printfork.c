/*
============================================================================
Name : 21
Author : Mohammed Haris
Description :  Write a program, call fork and print the parent and child process id. 
Date: 04 Sept, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(void){
        int ret;
        ret=fork();
        if(ret==0) printf("Child process: pid= %d\t ppid=%d\n", getpid(), getppid());
        else printf("Parent process: pid=%d\n", getpid());

}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q21$ vim printfork.c
haris@Haris:~/handson/Q21$ gcc printfork.c -o printfork
haris@Haris:~/handson/Q21$ ./printfork
Parent process: pid=726
Child process: pid= 727  ppid=726

=================================================
*/
