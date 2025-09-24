/*
============================================================================
Name : 26
Author : Mohammed Haris
Description :   Write a program to execute an executable program. 
a. use some executable program 
b. pass some input to an executable program. (for example execute an executable of $./a.out name)
Date: 05 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>

int main() {
    char *args[] = {"cat", "file.txt", NULL};

    printf("Now running external program...\n");

    execvp("cat", args);

    // if execvp fails
    perror("execvp failed");
    return 1;
}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q26$ vim program.c
haris@Haris:~/handson/Q26$ touch file.txt
haris@Haris:~/handson/Q26$ echo "Hello world" > file.txt
haris@Haris:~/handson/Q26$ gcc program.c -o program
haris@Haris:~/handson/Q26$ ./program
Now running external prog.
Hello world

=================================================
*/
