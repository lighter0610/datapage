#include <stdio.h>
#include <unistd.h>
int main(){
	int a, b;
	a = fork();
	if(a < 0) printf("error");
	else if(a == 0) printf("son c\n");
	else{
		b = fork();
		if(b < 0) printf("error");
		else if(b == 0) printf("son b\n");
		else printf("father a\n");
	}
	return 0;
}
 
