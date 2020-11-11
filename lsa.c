#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <stdio.h> 
#include <dirent.h> 

int main(void) 
{ 
	struct dirent *de; 
	DIR *dr = opendir("."); 

	if (dr == NULL) 
	{ 
		printf("Could not open current directory" ); 
		return 0; 
	} 
	while ((de = readdir(dr)) != NULL) {
		printf("%s,  ", de->d_name); 
	}
	closedir(dr);
	printf("\n");
	exit(0);	 
	return 0; 
} 
