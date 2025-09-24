/*
============================================================================
Name : 19
Author : Mohammed Haris
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter. 
Date: 03 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>


static inline unsigned long long read_tsc() {
    unsigned int lo, hi;
    __asm__ __volatile__("rdtsc" : "=a"(lo), "=d"(hi));
    return ((unsigned long long)hi << 32) | lo;
}

int main() {
    unsigned long long t1, t2;
    pid_t pid;
    t1 = read_tsc();
    pid = getpid();
    printf("Process ID: %d\n", pid);
    t2 = read_tsc();
    printf("Time taken (approx cycles): %llu\n", (t2 - t1));

}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q19$ vim getpid.c
haris@Haris:~/handson/Q19$ gcc getpid.c -o getpid
haris@Haris:~/handson/Q19$ ./getpid
Process ID: 513
Time taken (approx cycles): 168500

=================================================
*/
