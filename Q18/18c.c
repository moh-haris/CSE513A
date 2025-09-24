
/*
============================================================================
Name : 18(c)
Author : Mohammed Haris
Description :. . Write a program to perform Record locking. 
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
    int fd = open("records.dat", O_RDONLY);
    if (fd < 0) { perror("open"); return 1; }

    int recno = 2;  
    struct flock lock;
    lock.l_type = F_RDLCK;    
    lock.l_whence = SEEK_SET;
    lock.l_start = (recno-1) * sizeof(int);
    lock.l_len = sizeof(int);
    fcntl(fd, F_SETLKW, &lock);

    int val;
    lseek(fd, (recno-1) * sizeof(int), SEEK_SET);
    read(fd, &val, sizeof(int));
    printf("Read record %d = %d\n", recno, val);

    printf("Enter any key to unlock: ");
    getchar();

    lock.l_type = F_UNLCK;   
    fcntl(fd, F_SETLK, &lock);

    close(fd);
    
}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q18$ vim 18c.c
haris@Haris:~/handson/Q18$ gcc 18c.c -o 18c
haris@Haris:~/handson/Q18$ ./18c
Read record 2 = 30

=i================================================
*/
