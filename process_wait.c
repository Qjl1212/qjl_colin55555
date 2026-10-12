1 #include <process_copy.h>
  2 
  3 void process_wait(void)
  4 {
  5     pid_t zpid;
  6     while((zpid=wait(NULL))>0){
  7         printf("Parent wait child success,zpid %d\n",zpid);
  8     }
  9 }

