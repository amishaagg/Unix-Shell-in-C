#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <readline/readline.h>
#include <readline/history.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <errno.h> 
#include <string.h>
extern int errno;

char history[100][100];
	char s[100]; 
	int hisi=0;
	char *line;
	char *token;
	int status;
	char *token2;
int main(){
	printf("\n\n\n\n\n" );
	while(1){
		printf("\033[1;33m");
		bool isclear=false; 
		bool isn=false;
		printf("%s %s","Amishas@ubuntu:-",getcwd(s,100));
		printf("\033[0m");

		line=readline("$ ");
		//fprintf(out_file, "%s\n",line); 
		   for(int i=0;i<100;i++){
				history[hisi][i]=line[i];
			}
   		token = strtok(line, " ");				
		if(strcmp(line,"exit")==0){exit(0);}
		else if(strcmp(token,"cd")==0){
			int tok_num=0;
			char *argv[5];
			bool isH =false;
			bool isP=false;
			bool invalid=false;
			while( token != NULL ) {
				if(tok_num==1 && strcmp(token,"--help")==0){
					isH=true;
					token = strtok(NULL, " ");
					tok_num++;
					continue;
				}
				else if(tok_num==1 && strcmp(token,"-P")==0){
					isP=true;
					token = strtok(NULL, " ");
					tok_num++;
					continue;
				}
				else if(tok_num==1 && isH==false && isP==false){
					argv[1]=token;
				}
				else if(tok_num==2 && isP==true){
					argv[1]=token;
				}else if((tok_num>=2 && isP==false)||(tok_num>1 && isH==true)){
					invalid=true;
				}
				
				token = strtok(NULL, " ");
				tok_num++;
		   }
		   if(invalid==true){
		   	printf("Too many arguments" );
		   }
		   else if(isH==false){
		   	if (chdir(argv[1]) != 0)  
    		printf("Error : No such directory found");
			else chdir(argv[1]);
		   }else if(isH==true){
		   		FILE *fptr;
		   		char str[150];
		   		fptr=fopen("cdhelp.txt","r");
   			if(fptr==NULL){
   				printf("error opening file" );
   			}
   			while(!feof(fptr)){
      			fgets(str,150,fptr);
    
    			if(str[strlen(str)-1] =='\n')str[strlen(str)-1] = '\0';

      			printf("%s\n", str);

   			}
		   }

			
		}
		else if(strcmp(token,"history")==0){
			int tok_num=0;
			
			while( token != NULL ) {
				if(tok_num==1 && strcmp(token,"-c")==0){
					for(int i=0;i<100;i++){
						memset(history[i], 0, 100);

					}
					isclear=true;
					hisi=-1;
					token = strtok(NULL, " ");
					tok_num++;
					break;
				}
				if(tok_num==1 && strcmp(token,"-d")==0){
					token = strtok(NULL, " ");
					tok_num++;
					int d=atoi(token)-1;
					memset(history[d], 0, 100);
					isclear=true;
					for(int i=d+1;i<100;i++){
						for(int j=0;j<100;j++){
							char ch=history[i][j];
							history[i-1][j]=ch;
						}
					}
					hisi--;
					break;
				}
				if(tok_num>=3)break;
			
				token = strtok(NULL, " ");
				tok_num++;
			}
				
				if(isclear==false){
				for(int i=0;i<=hisi;i++){
					printf("%d %s\n",i+1,history[i]);
				}
			
		   }
		  	
			
		}

		else if(strcmp(line,"pwd")==0){
			int tok_num=0;
			bool isH =false;
			bool isP=false;
			bool invalid=false;
			while( token != NULL ) {
				if(tok_num==1 && strcmp(token,"--help")==0){
					isH=true;
					token = strtok(NULL, " ");
					tok_num++;
					continue;
				}
				else if(tok_num==1 && strcmp(token,"-P")==0){
					isP=true;
					token = strtok(NULL, " ");
					tok_num++;
					continue;
				}
				else if((tok_num>=2)||(tok_num>=1 && isH==false && isP==false)){
					invalid=true;
				}
				
				token = strtok(NULL, " ");
				tok_num++;
		   }
		   	if(invalid==true){
		   	printf("Too many arguments" );
		   }
		   else if(isH==false){
		   		if(getcwd(s,100)==NULL){printf("Error: %s\n",strerror(errno) );}
				else printf("\n%s ", getcwd(s, 100));
		   }else if(isH==true){
		   	FILE *fptr;
		   		char str[150];
		   		fptr=fopen("pwdhelp.txt","r");
   			if(fptr==NULL){
   				printf("error opening file" );
   			}
   			while(!feof(fptr)){
      			fgets(str,150,fptr);
    
    			if(str[strlen(str)-1] =='\n')str[strlen(str)-1] = '\0';

      			printf("%s\n", str);
      		}
		   }
			
		}
		else if(strcmp(token,"echo")==0){
			int tok_num=0;
			bool isE=false;
			while( token != NULL ) {
				if(tok_num==1 && strcmp(token,"-n")==0){
					isn=true;
					token = strtok(NULL, " ");
					tok_num++;
					continue;
				}
				if(tok_num==1 && strcmp(token,"-E")==0){
					isE=true;
					token = strtok(NULL, " ");
					tok_num++;
					continue;
				}

				if(tok_num!=0 ){
				printf("%s ",token );}
				
				token = strtok(NULL, " ");
				tok_num++;
				
		   }
		}else if(strcmp(token,"ls")==0){
			int tok_num=0;
			bool invalid=false;
			bool done =false;
			while( token != NULL ) {
				if(tok_num==1 && strcmp(token,"-1")==0){
					pid_t pid=fork();
					if(pid<0){
						printf("%s\n","error in fork" );
					}
					if(pid==0){
						char *bin_path="./ls1";				
			 			char *args[]={bin_path,NULL};
			 			execv(bin_path,args);				
								
					}else if(pid>0){
						pid= waitpid(pid, &status, 0);
						if ((pid ) == -1){
      						perror("wait() error");
      					}	
					}
					token = strtok(NULL, " ");
					tok_num++;
					done=true;
					continue;
				}

				else if(tok_num==1 && strcmp(token,"-a")==0){
					pid_t pid=fork();
					if(pid<0){
						printf("%s\n","error in fork" );
					}
					if(pid==0){
						char *bin_path="./lsa";				
			 			char *args[]={bin_path,NULL};
			 			execv(bin_path,args);				
								
					}else if(pid>0){
						pid= waitpid(pid, &status, 0);
						if ((pid ) == -1){
      						perror("wait() error");
      					}	
					}
					token = strtok(NULL, " ");
					tok_num++;
					done=true;
					continue;
				}
				else if(tok_num>=1){
					invalid=true;
				}
				token = strtok(NULL, " ");
				tok_num++;
		   }
		   if(invalid)printf("%s\n","No such command found" );
		   if(!done && !invalid){
		   		lscommand();
		   }
			
		}
		else if(strcmp(token,"mkdir")==0){
			int tok_num=0;
			char *argv[5];
			 argv[3]=NULL;
			bool isv =false;
			bool ism=false;
			while( token != NULL ) {
				if(tok_num==1 && strcmp(token,"-v")==0){
					isv=true;
					token = strtok(NULL, " ");
					tok_num++;
					continue;
				}
				if(tok_num==1 && strcmp(token,"-m")==0){
					ism=true;
					token = strtok(NULL, " ");
					tok_num++;
					continue;
				}
				if(tok_num==1 && isv==false && ism==false){
					argv[1]=token;
				}
				if(tok_num==2 && isv==true){
					argv[1]=token;
				}
				if(tok_num==2 && ism==true){
					argv[3]=token;
				}
				if(tok_num==3 && ism==true){
					argv[1]=token;
				}
				token = strtok(NULL, " ");
				tok_num++;
		   }

		   
		   pid_t pid=fork();
			if(pid<0){
				printf("%s\n","error in fork" );
			}
			if(pid==0){
				char *bin_path="./mkdir";				
				if(isv==true){execl(bin_path,argv[1],"isv",argv[3],NULL);}
				else if(ism==true)execl(bin_path,argv[1],"ism",argv[3],NULL);				
				else 				execl(bin_path,argv[1],"isnormal",argv[3],NULL);
			}else if(pid>0){
				pid= waitpid(pid, &status, 0);
				if ((pid ) == -1){
      				perror("wait() error");
      			}	
			}
		  
		}
		else if(strcmp(token,"rm")==0){
			int tok_num=0;
			bool isf=false;
			bool isi=false;
			char *argv[3];
			int yorn=2;
			while( token != NULL ) {
				if(tok_num==1 && strcmp(token,"-i")==0){

					isi=true;
					token = strtok(NULL, " ");
					tok_num++;
					continue;
				}
				if(tok_num==1 && strcmp(token,"-f")==0){
					//printf("%s\n","budbak" );
					isf=true;
					token = strtok(NULL, " ");
					tok_num++;
					continue;
				}
				if(tok_num==1 && isf==false && isi==false){
					argv[1]=token;
				}
				if(tok_num==2 &&(isf==true || isi==true)){
					argv[1]=token;
				}
				token = strtok(NULL, " ");
				tok_num++;
		   }
		   if(isi==true){
		   	printf("rm: remove file '%s'?",argv[1] ); 	
		   	scanf("%d",&yorn);

		   }

			if(yorn!=0){		  
		   pid_t pid=fork();
			if(pid<0){
				printf("%s\n","error in fork" );
			}
			if(pid==0){
				char *bin_path="./rm";				
				if(isi==true){execl(bin_path,argv[1],"isi",NULL);}
				else if(isf==true)execl(bin_path,argv[1],"isf",NULL);				
				else  execl(bin_path,argv[1],"isnormal",NULL);
			}else if(pid>0){
				pid= waitpid(pid, &status, 0);
				if ((pid ) == -1){
      				perror("wait() error");
      			}	
			}
		}
			
		}
		else if(strcmp(token,"cat")==0){
			int tok_num=0;
			char *argv[20];
			for(int i=0;i<20;i++){
				argv[i]="\0";
			}
			argv[19]=NULL;
			int cnt=2;
			bool isn2;
			bool isE;
			char flag[6];
			while( token != NULL ) {
				if(tok_num==1 && strcmp(token,"-n")==0){
					argv[1]="-n";
					isn2=true;
					token = strtok(NULL, " ");
					tok_num++;
					continue;
				}
				else if(tok_num==1 && strcmp(token,"-E")==0){
					argv[1]="-E";
					isE=true;
					token = strtok(NULL, " ");
					tok_num++;
					continue;
				}
				else if(tok_num==1 && isn2==false && isE==false){
					argv[1]="normal";
					argv[cnt]=token;
					cnt++;
					token = strtok(NULL, " ");
					tok_num++;
					continue;
				}
				else if(tok_num>1){
					argv[cnt]=token;
					cnt++;
				}
				
				token = strtok(NULL, " ");
				tok_num++;
		   }
		   pid_t pid=fork();
			if(pid<0){
				printf("%s\n","error in fork" );
			}
			if(pid==0){

				char *bin_path="./cat";
				execl(bin_path,argv[1],argv[2],argv[3],argv[4],argv[5],argv[6],argv[7],argv[8],argv[9],argv[10],NULL);
				
			}else if(pid>0){
		
				pid= waitpid(pid, &status, 0);
				if ((pid ) == -1){
      				perror("wait() error");
      			}	
			}
		}
		else if(strcmp(token,"date")==0){
			int tok_num=0;
			bool invalid=false;
			char *argv[5];
			argv[1]="normal";
			while( token != NULL ) {
				if(tok_num==1 && strcmp(token,"-R")==0){
					argv[1]="-R";
					token = strtok(NULL, " ");
					tok_num++;
					continue;
				}
				else if(tok_num==1 && strcmp(token,"-u")==0){
					argv[1]="-u";
					token = strtok(NULL, " ");
					tok_num++;
					continue;
				}
				else if(tok_num>=1){
					invalid=true;
				}
				token = strtok(NULL, " ");
				tok_num++;
		   }

		   	if(invalid)printf("%s\n","No such command found" );
		   	else{
		   		pid_t pid=fork();
			if(pid<0){
				printf("%s\n","error in fork" );
			}
			if(pid==0){

				char *bin_path="./date";
				execl(bin_path,argv[1],NULL);
				
			}else if(pid>0){
		
				pid= waitpid(pid, &status, 0);
				if ((pid ) == -1){
      				perror("wait() error");
      			}	
			}
		   	}
		}

		else{
			printf("%s","Command not found" );
		}
		
		
    hisi++;
    if(isn!=true)printf("\n");

	}
}

void lscommand(){
			pid_t pid=fork();
			if(pid==0){
				char *bin_path="./ls";
			 	char *args[]={bin_path,NULL};
			 	execv(bin_path,args);								
			}else if(pid>0){
				pid= waitpid(pid, &status, 0);
				if ((pid ) == -1){
      				perror("wait() error");
      			}
			}

			return;
	
}