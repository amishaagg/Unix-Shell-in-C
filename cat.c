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
  FILE *fptr;
  FILE *fptr2;
  struct stat st = {0};

  char str[150];
  if ((fptr= fopen("abc3.txt","w")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       return 0;
   }
    for(int i=1;i<argc;i++){
       if(strcmp(argv[i],"\0")!=0){
        if(stat(argv[i],&st)==-1){
          printf("file %s doesn't exist\n",argv[i] );
          continue;
        }
        fptr2=fopen(argv[i],"r");
         
          while(!feof(fptr2)){
            fgets(str,150,fptr2);
            fprintf(fptr,"%s",str);
          }
        fclose(fptr2);
      }
   }

   fclose(fptr);
   fptr=fopen("abc3.txt","r");
   if(fptr==NULL){
      printf("Error! opening file");
      return 0;
   }
   int i=1;
   while(!feof(fptr)){
      fgets(str,150,fptr);
    
    if(str[strlen(str)-1] =='\n')str[strlen(str)-1] = '\0';
    char c='$';

    if(strcmp(argv[0],"-E")==0)strncat(str,&c,1);
    if(strcmp(argv[0],"-n")==0)printf("%d",i );
      printf("%s\n", str);
      i++;

   }

   
  fclose(fptr);
  
   return 0; 
}
