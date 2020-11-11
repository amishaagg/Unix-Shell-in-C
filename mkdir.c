#include <sys/stat.h> 
#include <sys/types.h> 
#include <stdio.h>
#include <errno.h> 
#include <string.h>
#include<stdlib.h>
extern int errno;
//int main()
int main(int argc, char const *argv[])

  
{ 

    char *ptr;
   	mode_t ret;
   

    struct stat st = {0};
    if(stat(argv[0],&st)==-1){
    	if(strcmp(argv[1],"ism")==0){
    		ret=strtol(argv[2],&ptr,8);
			if (mkdir(argv[0], 0777) == -1) 
    			printf("Error : %s\n",strerror(errno));
    		else{
    			//mkdir: created directory 'as3'
    			if(strcmp(argv[1],"isv")==0)printf("mkdir: created directory '%s'\n",argv[0]);
    		}    			
    	}else{
    	if (mkdir(argv[0], 0777) == -1) 
    		printf("Error : %s\n",strerror(errno));
    	else{
    		//mkdir: created directory 'as3'
    		if(strcmp(argv[1],"isv")==0)printf("mkdir: created directory '%s'\n",argv[0]);
    	}}
    }
    else{
    	//mkdir: cannot create directory ‘as’: File exists
    	printf("mkdir: cannot create directory '%s': File exists\n",argv[0]);
    }

}

