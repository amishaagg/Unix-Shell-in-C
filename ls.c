#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <stdio.h> 
#include <dirent.h> 
#include <errno.h> 
#include <string.h>
extern int errno;
int main(int argc, char const *argv[])
{ 
	struct dirent *de; 
	DIR *dr = opendir("."); 

	if (dr == NULL) 
	{ 
		printf("Could not open current directory" ); 
		return 0; 
	} 

	//if(strcmp(argv[0],"amisha")==0)printf("%s\n", "yo success");
	
	while ((de = readdir(dr)) != NULL){
		if(memcmp(de->d_name,".",1)!=0)printf("%s\t", de->d_name);
	}

	closedir(dr);
	printf("\n");
	exit(0);	 
	return 0; 
} 

