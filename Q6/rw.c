/*
============================================================================
Name : 6
Author : Mohammed Haris
Description :  Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 28th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include <unistd.h>

int main() {
    char buffer[100];
    int n = read(0, buffer, sizeof(buffer));
    if (n > 0)  write(1, buffer, n);
}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q6$ vim rw.c
haris@Haris:~/handson/Q6$ gcc rw.c -o rw
haris@Haris:~/handson/Q6$ ./rw
Hello world this is code
Hello world this is code
============================================================================
*/
