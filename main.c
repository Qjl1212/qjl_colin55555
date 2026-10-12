  1 #include <process_copy.h>
  2 
  3 int main(int argc,char ** argv)
  4 {
  5     int pronum;
  6     int blocksize;
  7 
  8     if(argv[3]==0)
  9         pronum=3;
 10     else
 11         pronum=atoi(argv[3]);
 12 
 13     check_pram(argc,argv[1],pronum);
 14     blocksize=block_cur(argv[1],pronum);
 15     process_create(argv[1],argv[2],pronum,blocksize);
 16     return 0;
 17 }
~      
