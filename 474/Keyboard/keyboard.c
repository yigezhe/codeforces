#include<stdio.h>
#include<string.h>
char str1[11];
char str2[11];
char str3[11];
char shifted(char a,int add,int head) {
	int i;
	for(i=0;i<10;i++) {
		if(a==str1[i]) {
			if(i==head) return str1[i];
			else return str1[i+add];
		}
	}
	for(i=0;i<10;i++) {
		if(a==str2[i]) {
			if(i==head) return str2[i];
			else return str2[i+add];
		}
	}
	for(i=0;i<10;i++) {
		if(a==str3[i]) {
			if(i==head) return str3[i];
			else return str3[i+add];
		}
	}
	//printf("a=%c\n",a);
	return '@';
}
int main() {
	strcpy(str1,"qwertyuiop");
	strcpy(str2,"asdfghjkl;");
	strcpy(str3,"zxcvbnm,./");
	//printf("%s\n",str1);
	//printf("%s\n",str2);
	//printf("%s\n",str3);
	char shift=getchar();
	int add,head;
	if(shift=='R') {
		add=-1;
		head=0;
	}else {
		add=1;
		head=9;
	}
	getchar();//去掉回车！
	while(1) {
		char a=getchar();
		if(a==EOF || a=='\n') {
			break;
		}else {
			printf("%c",shifted(a,add,head));
		}
	}
	printf("\n");

	return 0;
}
