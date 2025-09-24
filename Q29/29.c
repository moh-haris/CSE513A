
/*
============================================================================
Name : 29
Author : Mohammed Haris
Description : . Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,  
SCHED_RR).
Date: 06 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <sched.h>
#include <unistd.h>

int main() {
    int policy;
    struct sched_param param;

    policy = sched_getscheduler(0);

    if (policy == SCHED_OTHER)
        printf("Current policy is SCHED_OTHER\n");
    else if (policy == SCHED_FIFO)
        printf("Current policy is SCHED_FIFO\n");
    else if (policy == SCHED_RR)
        printf("Current policy is SCHED_RR\n");
    else
        printf("Current policy: Unknown (%d)\n", policy);

    param.sched_priority = 10;
    if (sched_setscheduler(0, SCHED_FIFO, &param) == -1) {
        perror("sched_setscheduler");
    } else {
        printf("Policy changed to SCHED_FIFO with priority %d\n", param.sched_priority);
    }
}



/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q29$ gcc 29.c -o 29
haris@Haris:~/handson/Q29$ sudo ./29
[sudo] password for haris:
Current policy is SCHED_OTHER
Policy changed to SCHED_FIFO with priority 10

=================================================
*/
