
/*
============================================================================
Name : 28
Author : Mohammed Haris
Description :  Write a program to get maximum and minimum real time priority. 
Date: 05 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <sched.h>

int main() {
    int max, min;

    max = sched_get_priority_max(SCHED_FIFO);
    min = sched_get_priority_min(SCHED_FIFO);
    printf("SCHED_FIFO= max: %d, min: %d\n", max, min);

    max = sched_get_priority_max(SCHED_RR);
    min = sched_get_priority_min(SCHED_RR);
    printf("SCHED_RR= max: %d, min: %d\n", max, min);

    max = sched_get_priority_max(SCHED_OTHER);
    min = sched_get_priority_min(SCHED_OTHER);
    printf("SCHED_OTHER= max: %d, min: %d\n", max, min);

}


/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q28$ vim priority.c
haris@Haris:~/handson/Q28$ gcc priority.c -o priority
haris@Haris:~/handson/Q28$ ./priority
SCHED_FIFO= max: 99, min: 1
SCHED_RR= max: 99, min: 1
SCHED_OTHER= max: 0, min: 0

=================================================
*/
