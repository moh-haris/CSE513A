/*
============================================================================
Name : 1c.c
Author : Mohammed Haris
Description :  Create the following types of a files using (i) shell command (ii) system call
b. hard link (link system call) 
Date: 20th Aug, 2025.
============================================================================
*/

#include<stdio.h>
#include<unistd.h>

int main(){
        const char *original="1b_hardlink.txt";
        const char *newlink="hardlink.txt";

        if(link(original,newlink)==0){
                printf("Hard link created\n");
        }
        else printf("Error Link can't creat \n");
}


/*
output:- 
Hard link created
*/
