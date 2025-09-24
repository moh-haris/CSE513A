/*
============================================================================
Name : 1c.c
Author : Mohammed Haris
Description :  Create the following types of a files using (i) shell command (ii) system call 
c. FIFO (mkfifo Library Function or mknod system call) 
Date: 20th Aug, 2025.
============================================================================
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

int main() {
    if (mkfifo("myfifo", 0666) == 0)
        printf("FIFO created successfully.\n");
    else
        perror("mkfifo");
    return 0;
}


/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q1$ vim 1c_fifo.c
haris@Haris:~/handson/Q1$ gcc 1c_fifo.c -o fifo
haris@Haris:~/handson/Q1$ ./fifo
FIFO created successfully.
haris@Haris:~/handson/Q1$ cat < myfifo   haris@Haris:~/handson/Q1$ echo "Hello world!" > myfifo
Hello world!
============================================================================
*/
