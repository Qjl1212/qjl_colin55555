 1 #include <process_copy.h>
  2 
  3 int process_create(const char * srcfile,const char * dest,int pronum,int blocksize)
  4 {
  5     char offset_str[50];
  6     char blocksize_str[50];
  7 
  8     pid_t pid;
  9     int i;
 10     for(i=0;i<pronum;i++)
 11     {
 12         pid=fork();
 13         if(pid==0)
 14             break;
 15     }
 16 
 17     if(pid>0)
 18     {
 19         process_wait();
 20     }else if(pid==0)
 21     {
 22         int offset;
 23         offset=i*blocksize;
 24         sprintf(offset_str,"%d",offset);
 25         sprintf(blocksize_str,"%d",blocksize);
 26         execl("/home/colin/20250915/Process/process_copy/MOD/Copy","Copy",srcfile,dest,offset_str,blocksi    ze_str,NULL);
 27     }
 28     else
 29     {
 30     }
 31 }

