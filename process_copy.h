  1 #include <unistd.h>
  2 #include <string.h>
  3 #include <stdio.h>
  4 #include <stdlib.h>
  5 #include <sys/types.h>
  6 #include <sys/stat.h>
  7 #include <fcntl.h>
  8 #include <sys/wait.h>
  9 
 10 int check_pram(int ,const char *,int);
 11 int block_cur(const char * ,int);
 12 int process_create(const char * ,const char * ,int , int);
 13 void process_wait(void);

