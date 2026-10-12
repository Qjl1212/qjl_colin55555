 1 #include <process_copy.h>
  2 
  3 int block_cur(const char *srcfile,int pronum)
  4 {
  5     int fsize;
  6     int fd=open(srcfile,O_RDONLY);
  7     fsize=lseek(fd,0,SEEK_END);
  8 
  9     if(fsize % pronum == 0)
 10             return fsize / pronum;
 11     else
 12             return fsize / pronum + 1;
 13 }

