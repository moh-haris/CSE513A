/*
============================================================================
Name : 27
Author : Mohammed Haris
Description :    Write a program to execute ls -Rl by the following system calls 
a. execl 
b. execlp 
c. execle 
d. execv 
e. execvp 
Date: 05 Sept, 2025.
============================================================================
*/

#include <unistd.h>

int main(int argc, char *envp[]) {
    if (fork() == 0) execl("/bin/ls", "ls", "-Rl", NULL);
    if (fork() == 0) execlp("ls", "ls", "-Rl", NULL);
    if (fork() == 0) execle("/bin/ls", "ls", "-Rl", NULL, envp);
    if (fork() == 0) {
        char *argv1[] = {"ls", "-Rl", NULL};
        execv("/bin/ls", argv1);
    }
    if (fork() == 0) {
        char *argv2[] = {"ls", "-Rl", NULL};
        execvp("ls", argv2);
    }

}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q27$ vim exe.c
haris@Haris:~/handson/Q27$ gcc exe.c -o exe
haris@Haris:~/handson/Q27$ ./exe
.:
.:
total 20
total 20
haris@Haris:~/handson/Q27$ -rwxr-xr-x 1 haris haris 16224 Sep  7 10:27 exe
-rw-r--r-- 1 haris haris   448 Sep  7 10:26 exe.c
-rwxr-xr-x 1 haris haris 16224 Sep  7 10:27 exe
-rw-r--r-- 1 haris haris   448 Sep  7 10:26 exe.c
.:
total 20
-rwxr-xr-x 1 haris haris 16224 Sep  7 10:27 exe
-rw-r--r-- 1 haris haris   448 Sep  7 10:26 exe.c
.:
total 20
-rwxr-xr-x 1 haris haris 16224 Sep  7 10:27 exe
-rw-r--r-- 1 haris haris   448 Sep  7 10:26 exe.c
.:
total 20
-rwxr-xr-x 1 haris haris 16224 Sep  7 10:27 exe
-rw-r--r-- 1 haris haris   448 Sep  7 10:26 exe.c

=================================================
*/
