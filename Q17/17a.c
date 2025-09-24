
/*
============================================================================
Name : 17(a)
Author : Mohammed Haris
Description :. Write a program to simulate online ticket reservation.  Implement write lock  
Write a program to open a file, store a ticket number and exit.
Date: 02 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("ticket.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    
    int ticket = 1; 
    dprintf(fd, "%d\n", ticket); 

    close(fd);
    printf("Ticket initialized with number %d\n", ticket);
  
}

/*
============================================================================
OUTPUT

haris@Haris:~/handson/Q17$ vim 17a.c
haris@Haris:~/handson/Q17$ vim 17b.c
haris@Haris:~/handson/Q17$ gcc 17a.c -o 17a
haris@Haris:~/handson/Q17$ gcc 17b.c -o 17b
haris@Haris:~/handson/Q17$ ./17a
Ticket initialized with number 1
haris@Haris:~/handson/Q17$ ./17b
New ticket number: 2
haris@Haris:~/handson/Q17$ cat ticket.txt
2

=================================================
*/
