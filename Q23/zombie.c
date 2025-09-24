/*
============================================================================
Name : 23
Author : Mohammed Haris
Description :   Write a program to create a Zombie state of the running program. 
Date: 04 Sept, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
        int ret;
        ret=fork();
        if(ret==0) printf("Child process: pid=%d\t, ppid=%d\n",getpid(),getppid());
        else{
                printf("Parent process: pid=%d\n",getpid());
                sleep(25);
        }
}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q23$ gcc zombie.c -o zombie
haris@Haris:~/handson/Q23$ ./zombie
Parent process: pid=1416
Child process: pid=1417 , ppid=1416

=================================================
*/
