/*
============================================================================
Name : 17(b)
Author : Mohammed Haris
Description :.  Write a separate program, to 
open the file, implement write lock, read the ticket number, increment the number and print 
the new ticket number then close the file.
Date: 06 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int fd = open("ticket.txt", O_RDWR);
    if (fd == -1) {
        perror("open");
        return 1;
    }

    struct flock lock;
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl - lock");
        close(fd);
        return 1;
    }

    char buffer[32];
    lseek(fd, 0, SEEK_SET);
    int n = read(fd, buffer, sizeof(buffer) - 1);
    if (n <= 0) {
        perror("read");
        close(fd);
        return 1;
    }
    buffer[n] = '\0';

    int ticket = atoi(buffer);  
    ticket++;

    lseek(fd, 0, SEEK_SET);
    ftruncate(fd, 0);  
    dprintf(fd, "%d\n", ticket);

    printf("New ticket number: %d\n Now press enter to unlock", ticket);
    getchar();

    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLK, &lock);

    close(fd);
}


/*
============================================================================
OUTPUT

haris@Haris:~/handson/Q17$ vim 17b.c
haris@Haris:~/handson/Q17$ gcc 17b.c -o 17
haris@Haris:~/handson/Q17$ ./17
New ticket number: 2
2

=================================================
*/

