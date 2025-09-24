/*
============================================================================
Name : 20
Author : Mohammed Haris
Description :  Find out the priority of your running program. Modify the priority with nice command
Date: 04 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    int old_pr, new_pr;
    int inc = 5;

    old_pr = getpriority(PRIO_PROCESS, 0);
    printf("Initial priority: %d\n", old_pr);

    nice(inc);

    new_pr = getpriority(PRIO_PROCESS, 0);
    printf("Updated priority: %d\n", new_pr);
    sleep(50);
}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q20$ vim nice.c
haris@Haris:~/handson/Q20$ gcc nice.c -o nice
haris@Haris:~/handson/Q20$ ./nice
Initial priority: 0
Updated priority: 5

=================================================
*/
