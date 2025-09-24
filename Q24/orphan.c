/*
============================================================================
Name : 24
Author : Mohammed Haris
Description :   Write a program to create an orphan process. 
Date: 04 Sept, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
        if(!fork()){
                printf("Before orphan child process pid: %d\t ppid: %d\n",getpid(),getppid());
                sleep(3);
                printf("After ophan child process: pid=%d\t ppid=%d\n",getpid(),getppid());
        }
        else{
                sleep(1);
                printf("Parent process pid=%d\n",getpid());
        }

}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q24$ gcc orphan.c -o orphan
haris@Haris:~/handson/Q24$ ./orphan
Before orphan child process pid: 1434    ppid: 1433
Parent process pid=1433
haris@Haris:~/handson/Q24$ After ophan child process: pid=1434   ppid=391

=================================================
*/
