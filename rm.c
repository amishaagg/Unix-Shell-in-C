#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <errno.h> 
#include <string.h>
extern int errno;
int main(int argc, char const *argv[])
{

	if (unlink(argv[0]) ==-1) {
		if(strcmp(argv[1],"isf")!=0){
			printf("Error: %s\n",strerror(errno) );
			 
		}
     }
   else{
      printf("Deleted successfully"); 

   }
  
   return 0; 
}
