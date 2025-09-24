/*
============================================================================
Name : 8
Author : Mohammed Haris
Description :  Write a program to open a file in read only mode, read line by line and display each line as it is read. 
Close the file when end of file is reached. 
Date: 28th Aug, 2025.
============================================================================
*/

#include<stdio.h>

int main(){
        FILE *fp=fopen("myfile.txt","r");
        char line[256];
        while(fgets(line,sizeof(line),fp))
                printf("%s",line);
        fclose(fp);
}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q8$ vim line.c
haris@Haris:~/handson/Q8$ touch myfile.txt
haris@Haris:~/handson/Q8$ echo "Hellow world" > myfile.txt
haris@Haris:~/handson/Q8$ gcc line.c -o line
haris@Haris:~/handson/Q8$ ./line
Hellow world
============================================================================
*/
