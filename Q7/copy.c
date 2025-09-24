/*
============================================================================
Name : 7
Author : Mohammed Haris
Description :  Write a program to copy file1 into file2 ($cp file1 file2).
Date: 28th Aug, 2025.
============================================================================
*/

#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
 int src = open(argv[1], O_RDONLY);
 int dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0666);
  char buf[1024];
  int n;

  while ((n = read(src, buf, sizeof(buf))) > 0)
     write(dst, buf, n);

 close(src);
 close(dst);
}

/*
============================================================================
OUTPUT
haris@Haris:~/handson/Q7$ touch src_file.txt
haris@Haris:~/handson/Q7$ echo "Hello world" > src_file.txt
haris@Haris:~/handson/Q7$ gcc copy.c -o copy
haris@Haris:~/handson/Q7$ ./copy src_file.txt dest_file.txt
haris@Haris:~/handson/Q7$ cmp src_file.txt dest_file.txt
haris@Haris:~/handson/Q7$
============================================================================
*/
