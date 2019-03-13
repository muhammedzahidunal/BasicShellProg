#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char *argv[],char ** envp){
while(1){
char inpt[30];
char **inpValues = (char**)malloc(sizeof(char*)*7);
	
int i=0,;
int b=0;
for (i=0; i<7; i++){
	inpValues[i] = (char*)malloc(sizeof(char)*30);
}
int count=0;

printf("myshell>>");
gets(inpt);
char *token = strtok(inpt, " "); 
while (token != NULL) { 
       	strcpy(inpValues[count],token);
       	token = strtok(NULL, " "); 
			
	count++;
} 

pid_t pid=fork();
if(pid==0){
	char **sayilar = (char**)malloc(sizeof(char*)*2) ;
	char **sayilar2 = (char**)malloc(sizeof(char*)*2) ;	
	for (i=0; i<2; i++){
		sayilar[i] = (char*)malloc(sizeof(char)*30);
		sayilar2[i] = (char*)malloc(sizeof(char)*30);
	}
		
	strcpy(sayilar[0],inpValues[1]);
	strcpy(sayilar[1],inpValues[2]);
	
	if (strcmp(inpValues[3],"&")==0){
		if(strcmp(inpValues[0],"mul")==0 && strcmp(inpValues[4],"div")==0){
			pid_t fv= fork();
			if(fv==0){
				i = execv("mul",sayilar);
			}wait(5);
			pid_t ff=fork();
			if(ff==0){
				strcpy(sayilar2[0],inpValues[5]);
				strcpy(sayilar2[1],inpValues[6]);
				i = execv("div", sayilar2);
			}wait(5);
		}
		else if	(strcmp(inpValues[0],"div")==0 && strcmp(inpValues[4],"mul")==0){
			pid_t fv= fork();
			if(fv==0){
				i = execv("div",sayilar);
			}wait(5);
			pid_t ff=fork();
			if(ff==0){
				strcpy(sayilar2[0],inpValues[5]);
				strcpy(sayilar2[1],inpValues[6]);
				i = execv("mul", sayilar2);
			}wait(5);
		}
		else if	(strcmp(inpValues[0],"div")==0 || strcmp(inpValues[0],"mul")==0 && strcmp(inpValues[4],"rakam")==0){
			pid_t fv= fork();
			if(fv==0){
				if(strcmp(inpValues[0],"mul")==0)
					i = execv("mul",sayilar);
				else if(strcmp(inpValues[0],"div")==0)	
					i = execv("div",sayilar);
			}wait(5);
			pid_t ff=fork();
			if(ff==0){
				strcpy(sayilar2[0],inpValues[5]);
				sayilar2[1]=NULL;
				i = execv("rakam", sayilar2);
			}wait(5);
		}
		exit(0);

	}
	if (strcmp(inpValues[2],"&")==0){
		if(strcmp(inpValues[0],"rakam")==0 && strcmp(inpValues[3],"div")==0 || strcmp(inpValues[3],"mul")==0){
			pid_t fv=fork();
			if(fv==0){
				sayilar[1]=NULL;
				i = execv("rakam", sayilar);
			}wait(5);
			pid_t ff= fork();
			if(ff==0){
				if(strcmp(inpValues[3],"mul")==0){
					strcpy(sayilar2[0],inpValues[4]);
					strcpy(sayilar2[1],inpValues[5]);
					i = execv("mul",sayilar2);
				}
				else if(strcmp(inpValues[3],"div")==0){
					strcpy(sayilar2[0],inpValues[4]);
					strcpy(sayilar2[1],inpValues[5]);
					i = execv("div",sayilar2);
				}	
			}wait(5);	
		}
		exit(0);
	}
		

	if(strcmp(inpValues[0],"mul")==0){
	b = execv("mul",sayilar);
	}
	else if(strcmp(inpValues[0],"div")==0){
	b = execv("div",sayilar);
	}

	else if(strcmp(inpValues[0],"rakam")==0){
	strcpy(sayilar[0],inpValues[1]);
	sayilar[1]=NULL;
	i = execv("rakam",sayilar);
	}
	else if(strcmp(inpValues[0],"cat")==0){
	inpValues[2]=NULL;
	printf("cat: %s\n", inpValues[1]);
	}
	else if(strcmp(inpValues[0],"clear")==0){
	system("clear");
	}
	else if(strcmp(inpValues[0],"exit")==0){
	printf("");
	}
	else if(strcmp(inpValues[0],"")==0){
	continue;
	}
	else{
	printf("yanlış bir komut girdiniz\n");
	}
	exit(0);
}
else{
wait(&b);
}	

if(strcmp(inpValues[0],"exit")==0){
break;
}
	
}
}
