#============================================================================
#Name : 1A.sh
#Author : Mohammed Haris
#Description : 1. Create the following types of a files using (i) shell command (ii) system call
#a. soft link (symlink system call)
#b. hard link (link system call)
#c. FIFO (mkfifo Library Function or mknod system call)
#Date: 28th Aug, 2025.
#============================================================================



mkfifo myfifoshell

ls -l myfifoshell

# Output:
#haris@haris-ACERPCHLY:~/Study/Systems/handsOn/1$ chmod +x 1C.sh
#haris@haris-ACERPCHLY:~/Study/Systems/handsOn/1$ ./1C.sh
#prw-rw-r-- 1 haris haris 0 Sep  7 18:10 myfifoshell
