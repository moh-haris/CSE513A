
/*
============================================================================
Name : 18(b)
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
    int fd = open("records.dat", O_RDWR);
    if (fd < 0) { perror("open"); return 1; }

    int recno = 1;  
    struct flock lock;
    lock.l_type = F_WRLCK;    
    lock.l_whence = SEEK_SET;
    lock.l_start = (recno-1) * sizeof(int);
    lock.l_len = sizeof(int);           
    fcntl(fd, F_SETLKW, &lock);        

    int val;
    lseek(fd, (recno-1) * sizeof(int), SEEK_SET);
    read(fd, &val, sizeof(int));
    printf("Old value of record %d = %d\n", recno, val);

    
    val =val + 5; 
    lseek(fd, (recno-1) * sizeof(int), SEEK_SET);
    write(fd, &val, sizeof(int));
    printf("New value of record %d = %d now press enter to unlock\n", recno, val);
    getchar();

    lock.l_type = F_UNLCK;            
    fcntl(fd, F_SETLK, &lock);

    close(fd);
    return 0;
}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q18$ vim 18b.c
haris@Haris:~/handson/Q18$ gcc 18b.c -o 18b
haris@Haris:~/handson/Q18$ ./18b
Old value of record 1 = 20
Enter val you want to increase: 30
o
New value of record 1 = 50
===========================================================================
*/

