
/*
============================================================================
Name : 13
Author : Mohammed Haris
Description :  Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to 
verify whether the data is available within 10 seconds or not (check in $man 2 select). 
Date: 28th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/select.h>

int main() {
    fd_set fds;
    struct timeval tv = {10, 0};

    FD_ZERO(&fds);
    FD_SET(0, &fds);

    int r = select(1, &fds, NULL, NULL, &tv);

    if (r == 0) printf("Timeout\n");
    else if (r > 0) printf("Data entered\n");
    else perror("select");
}

/*
============================================================================
OUTPUT 13

haris@Haris:~/handson/Q13$ vim stdin.c
haris@Haris:~/handson/Q13$ gcc stdin.c -o stdin
haris@Haris:~/handson/Q13$ ./stdin
Timeout
or 
haris@Haris:~/handson/Q13$ vim stdin.c
haris@Haris:~/handson/Q13$ gcc stdin.c -o stdin
haris@Haris:~/handson/Q13$ ./stdin
k
Data entered
============================================================================
*/
