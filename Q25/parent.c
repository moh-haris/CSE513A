
/*
============================================================================
Name : 25
Author : Mohammed Haris
Description :   Write a program to create three child processes. The parent should wait for a particular child (use 
waitpid system call).
Date: 05 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t c1, c2, c3;

    c1 = fork();
    if (c1 == 0){ sleep(2); return 0; }

    c2 = fork();
    if (c2 == 0){ sleep(5); return 0; }

 c3 = fork();
    if (c3 == 0){ sleep(8); return 0;}

    waitpid(c2, NULL, 0);
    printf("Parent waited for child with PID %d\n", c2);
}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q25$ vim parent.c
haris@Haris:~/handson/Q25$ gcc parent.c -o parent
haris@Haris:~/handson/Q25$ ./parent
Parent waited for child with PID 1573
haris@Haris:~/handson/Q25$

=================================================
*/
