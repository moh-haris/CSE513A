/*
============================================================================
Name : 9
Author : Mohammed Haris
Description :  Write a program to print the following information about a given file. 
a. inode 
b. number of hard links 
c. uid 
d. gid 
e. size 
f. block size 
g. number of blocks 
h. time of last access 
i. time of last modification 
j. time of last change
Close the file when end of file is reached.
Date: 28th Aug, 2025.
============================================================================
*/

#include <sys/stat.h>
#include <stdio.h>
#include <time.h>

int main() {
    struct stat info;

    if (stat("metadata.txt", &info) == 0) {

    printf("Inode: %lu\n", info.st_ino);
    printf("Links: %lu\n", info.st_nlink);
    printf("UID: %u\n", info.st_uid);
    printf("GID: %u\n", info.st_gid);
    printf("Size: %ld\n", info.st_size);
    // printf("Block size: %ld\n", info.st_blksize);
    // printf("Blocks: %ld\n", info.st_blocks);
    printf("Access: %s", ctime(&info.st_atime));
    printf("Modify: %s", ctime(&info.st_mtime));
    printf("Change: %s", ctime(&info.st_ctime));
    } 
    
    else {
        perror("stat");
    }
}
/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q9$ touch metadata.txt
haris@Haris:~/handson/Q9$ echo "Hello world!" > metadata.txt
haris@Haris:~/handson/Q9$ ln metadata.txt metahard.txt
haris@Haris:~/handson/Q9$ vim metadata.c
haris@Haris:~/handson/Q9$ gcc metadata.c -o metadata
haris@Haris:~/handson/Q9$ ./metadata
Inode: 45093
Links: 2
UID: 1000
GID: 1000
Size: 13
Block size: 4096
Blocks: 8
Access: Fri Sep  5 07:26:36 2025
Modify: Fri Sep  5 07:26:49 2025
Change: Fri Sep  5 07:27:05 2025
haris@Haris:~/handson/Q9$
============================================================================
*/

