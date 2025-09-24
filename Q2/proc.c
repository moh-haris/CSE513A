
/*
============================================================================
Name : 1c.c
Author : Mohammed Haris
Description :  FIFO (mkfifo Library Function or mknod system call) 
Date: 27th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
        while(1){
                printf("Hello World\n");
                sleep(15);
        }
}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q2$ cd /proc/1089
haris@Haris:/proc/1089$ cat status
Name:   proc
Umask:  0022
State:  S (sleeping)
Tgid:   1089
Ngid:   0
Pid:    1089
PPid:   392
TracerPid:      0
Uid:    1000    1000    1000    1000
Gid:    1000    1000    1000    1000
FDSize: 256
Groups: 4 20 24 25 27 29 30 44 46 100 107 1000
NStgid: 1089
NSpid:  1089
NSpgid: 1089
NSsid:  392..........
............................
============================================================================
*/
