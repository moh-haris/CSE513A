

/*
============================================================================
Name : 29
Author : Mohammed Haris
Description : . Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,  
SCHED_RR).
Date: 06 Sept, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main() {
    pid_t pid, sid;
    pid = fork();
    if (pid < 0) {
        perror("fork failed");
        exit(EXIT_FAILURE);
    }
    if (pid > 0) {
        exit(EXIT_SUCCESS);
    }

    umask(0);
    sid = setsid();
    if (sid < 0) {
        perror("setsid failed");
        exit(EXIT_FAILURE);
    }

    if(chdir("/")<0){
	    perror("chdir failed");
	    exit(EXIT_FAILURE);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    int target_hour = 11;
    int target_minute = 00;

    while (1) {
        time_t now = time(NULL);
        struct tm *t = localtime(&now);

        if (t->tm_hour == target_hour && t->tm_min == target_minute) {
            system("/home/haris/handson/Q30/myscript.sh");
            sleep(60); 
        } else {
            sleep(10);
        }
    }

    
}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q30$ vim 30.c
haris@Haris:~/handson/Q30$ gcc 30.c -o daemontest
haris@Haris:~/handson/Q30$ sudo ./daemontest
haris@Haris:~/handson/Q30$ cat log.txt
Daemon executed at Sun Sep  7 16:40:05 UTC 2025
Daemon executed at Sun Sep  7 16:42:09 UTC 2025

=================================================
*/
