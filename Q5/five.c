/*
============================================================================
Name : 5
Author : Mohammed Haris
Description :   Write a program to create five new files with infinite loop. Execute the program in the background 
and check the file descriptor table at /proc/pid/fd. 
Date: 27th Aug, 2025.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int i = 0;

    while (1) {
        char filename[50];

        for (int j = 0; j < 5; j++) {
            sprintf(filename, "file_%d_%d.txt", i, j);
            int fd = open(filename, O_CREAT | O_RDWR, 0666);
            if (fd == -1) {
                perror("open");

            }
            printf("Created and opened: %s and fd=%d\n", filename, fd);

        }
        i++;
        sleep(60);
    }


}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q5$ ls -l /proc/504/fd
total 0
lrwx------ 1 haris haris 64 Sep  4 14:03 0 -> /dev/pts/0
lrwx------ 1 haris haris 64 Sep  4 14:03 1 -> /dev/pts/0
lrwx------ 1 haris haris 64 Sep  4 14:03 10 -> /home/haris/handson/Q5/file_1_2.txt
lrwx------ 1 haris haris 64 Sep  4 14:03 11 -> /home/haris/handson/Q5/file_1_3.txt
lrwx------ 1 haris haris 64 Sep  4 14:03 12 -> /home/haris/handson/Q5/file_1_4.txt
lrwx------ 1 haris haris 64 Sep  4 14:03 13 -> /home/haris/handson/Q5/file_2_0.txt
lrwx------ 1 haris haris 64 Sep  4 14:03 14 -> /home/haris/handson/Q5/file_2_1.txt
lrwx------ 1 haris haris 64 Sep  4 14:03 15 -> /home/haris/handson/Q5/file_2_2.txt
lrwx------ 1 haris haris 64 Sep  4 14:03 16 -> /home/haris/handson/Q5/file_2_3.txt..
..................
============================================================================
*/
