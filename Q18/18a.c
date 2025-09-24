
/*
============================================================================
Name : 18(a)
Author : Mohammed Haris
Description :.. Write a program to perform Record locking. 
a. Implement write lock 
b. Implement read lock 
Create three records in a file. Whenever you access a particular record, first lock it then modify/access 
to avoid race condition. 
Date: 06 Sept, 2025.
============================================================================
*/


#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("records.dat", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd < 0) { perror("open"); return 1; }

    int rec[3] = {10, 20, 30};  
    write(fd, rec, sizeof(rec));

    close(fd);
    printf("Created file with 3 records: %d, %d, %d\n", rec[0], rec[1], rec[2]);
    return 0;
}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q18$ vim 18a.c
haris@Haris:~/handson/Q18$ gcc 18a.c -o 18a
haris@Haris:~/handson/Q18$ ./18a
Created file with 3 records: 10, 20, 30

i=================================================
*/
