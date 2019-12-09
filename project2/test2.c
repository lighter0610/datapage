#include <stdio.h>
#include <string.h>
#include <unistd.h>
int main(){
	int a, b;
	int file[2];
	pipe(file);
	a = fork();
	if(a < 0) printf("error");
	else if(a == 0){
		printf("son c\n");
		char buf2[] = "Child 2 is sending a message!\n";
		write(file[1], buf2, strlen(buf2));
	}else{
		b = fork();
		if(b < 0) printf("error");
		else if(b == 0){
			printf("son b\n");
			char buf1[] = "Child 1 is sending a message!\n";
			write(file[1], buf1, strlen(buf1));
		}else{
			printf("father a\n");
			char str1[100] = {0};
			read(file[0], str1, sizeof(str1));
			printf("%s\n",str1);
			char str2[100] = {0};
			read(file[0], str2, sizeof(str2));
			printf("%s\n",str2);
		}
	}
	return 0;
}
 
