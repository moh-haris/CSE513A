/*
============================================================================
Name : 15
Author : Mohammed Haris
Description :  Write a program to display the environmental variable of the user (use environ). 
Date: 31th Aug, 2025.
============================================================================
*/

#include <stdio.h>

extern char **environ;
int main() {
char **env = environ;
while (*env) {
    printf("%s\n", *env);
    env++;
    }
    
}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q15$ gcc env.c -o env
haris@Haris:~/handson/Q15$ ./env
SHELL=/bin/bash
WSL2_GUI_APPS_ENABLED=1
WSL_DISTRO_NAME=Ubuntu
NAME=Haris
PWD=/home/haris/handson/Q15
LOGNAME=haris
HOME=/home/haris
LANG=C.UTF-8
=================================================
*/
