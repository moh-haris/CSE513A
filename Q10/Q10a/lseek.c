/*
============================================================================
Name : 10
Author : Mohammed Haris
Description :  10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 
bytes (use lseek) and write again 10 bytes.  
a. check the return value of lseek 
b. open the file with od and check the empty spaces in between the data.  
Date: 28th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buf1[] = "abcdefghij";  
    char buf2[] = "1234567890";  

   fd = open("file.txt", O_RDWR);
    if (fd < 0) {
        perror("open");
    }

   write(fd, buf1, 10);

    off_t pos = lseek(fd, 10, SEEK_CUR); 
    if (pos == -1) {
        perror("lseek");
        close(fd);
    }
    printf("lseek return value (new offset) = %ld\n", pos);

    write(fd, buf2, 10);
   close(fd);
    
}

/*
============================================================================
OUTPUT 10(a)

haris@Haris:~/handson/Q10/Q10a$ vim lseek.c
haris@Haris:~/handson/Q10/Q10a$ touch file.txt
haris@Haris:~/handson/Q10/Q10a$ gcc lseek.c -o lseek
haris@Haris:~/handson/Q10/Q10a$ ./lseek
lseek return value (new offset) = 20
haris@Haris:~/handson/Q10/Q10a$

OUTPUT 10(b)

haris@Haris:~/handson/Q10/Q10a$ od -c file.txt
0000000   a   b   c   d   e   f   g   h   i   j  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   1   2   3   4   5   6   7   8   9   0
0000036
haris@Haris:~/handson/Q10/Q10a$
============================================================================
*/
