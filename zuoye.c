#include <regex.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(void)
{
	int fd = open("url.html",O_RDWR);
	int size = lseek(fd,0,SEEK_END);//返回文件大小
	char * mmap_ptr = NULL;
	//内存映射
	mmap_ptr = mmap(NULL,size,PROT_READ|PROT_WRITE,MAP_PRIVATE,fd,0);
	//将文件数据映射到进程内存， 通过mmap_ptr可以访问 		
	close(fd);
        //关于正则代码：
	char* regstr="<a\\([^>]\\+\\?\\)href=\"\\([^\"]\\+\\?\\)\"\\([^>]\\+\\?\\)>\\([^<]\\+\\?\\)</a>";
	regex_t reg;
	regcomp(&reg,regstr,0);
	//遍历查找
	int regnum=5;
	regmatch_t match[regnum];
	char link[1024];
	char title[1024];
	while((regexec(&reg,mmap_ptr,regnum,match,0))==0)
	{
		bzero(link,sizeof(link));
		bzero(title,sizeof(title));
		snprintf(link,match[2].rm_eo -match[2].rm_so+1,"%s",mmap_ptr+match[2].rm_so);
		snprintf(title,match[4].rm_eo -match[4].rm_so+1,"%s",mmap_ptr+match[4].rm_so);
		mmap_ptr+=match[0].rm_eo;
		printf("匹配结果：title=%s  link =%s\n",title,link);
	}
	regfree(&reg);
	return 0;
}


