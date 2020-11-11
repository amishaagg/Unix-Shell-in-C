#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main(int argc, char const *argv[]){

		if(strcmp(argv[0],"-R")==0){
			struct tm* ptr; 
    		time_t lt; 
    		 
    		time(&lt); 
    		ptr = localtime(&lt); 
    		char buf[100];
    		strftime(buf,80,"%a, %d %b %Y %T %z", ptr);
    		printf("%s\n",buf);
		}
		else if(strcmp(argv[0],"-u")==0){
			struct tm* ptr; 
    		time_t lt; 
    		lt = time(NULL); 
    		ptr = gmtime(&lt); 
    		printf("UTC %s ", asctime(ptr)); 
    		return 0; 
		}
		else{
			struct tm* ptr; 
    		time_t lt= time(NULL); 
     		ptr = localtime(&lt); 
     		printf("PDT %s ", asctime(ptr)); 
     		return 0; 

		}

	

	
	// time_t t = time(NULL);
 //  struct tm tm = *localtime(&t);
 //  printf("now: %d-%02d-%02d %02d:%02d:%02d\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec);

}
