
/*
============================================================================
Name : 1c.c
Author : Mohammed Haris
Description :  Create the following types of a files using (i) shell command (ii) system call 
a. soft link (symlink system call) 
Date: 20th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
        const char *target_file="file.txt";
        const char *link="filelink.txt";

        if(symlink(target_file,link)==-1){ /*To check softlink created or not file descriptor(int >= 0) success*/
                perror("symlink fail");

        }

        printf("soft link created\n");
}

/*
============================================================================
OUTPUT

haris@Haris:~/handson/Q1$ gcc 1a_softlink.c
haris@Haris:~/handson/Q1$ ./a.out
soft link created
============================================================================
*/
