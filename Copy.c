  1 #include <stdio.h>
  2 #include <unistd.h>
  3 #include <stdlib.h>
  4 #include <string.h>
  5 #include <sys/types.h>
  6 #include <sys/stat.h>
  7 #include <sys/fcntl.h>
  8 
  9 int main(int argc,char ** argv)
 10 {
 11     int sfd;
 12     int dfd;
 13     int offset=atoi(argv[3]);
 14     int blocksize=atoi(argv[4]);
 15     if((sfd=open(argv[1],O_RDONLY))==-1)
 16             perror("open srcfile,failed");
 17     if((dfd=open(argv[2],O_WRONLY|O_CREAT,0664))==-1)
 18             perror("open srcfile,failed");
 19     lseek(sfd,offset,SEEK_SET);
 20     lseek(dfd,offset,SEEK_SET);
 21 
 22     char buffer[blocksize];
 23     int len;
 24     printf("child p %d execl Copy,offset %d ,blocksize %d\n",getpid(),offset,blocksize);
 25     len=read(sfd,buffer,sizeof(buffer));
 26     write(dfd,buffer,len);
 27     close(sfd); close(dfd);
 28     return 0;
 29 }

