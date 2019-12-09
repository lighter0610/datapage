#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
char command[256];
int main(){
	int rtn, errorno;
	
		printf(">");
		fgets(command, 256, stdin);
		command[strlen(command) - 1] = 0;
		if(fork() == 0){
			errorno = execlp(command, command, NULL, NULL);
			perror(command);
			exit(errorno);
		}else{
			wait(&rtn);
			printf("child return %d\n", rtn);
		}
	
	return 0;
}
 
