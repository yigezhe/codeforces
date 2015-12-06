#include<stdio.h>
#include<string.h>
#define N 100+5
#define S 256
int main() {
	char name[N];
	scanf("%s",name);
	int size=strlen(name);
	//要去掉重复项！
	int see[S];
	int i;
	for(i=0;i<S;i++) {
		see[i]=0;
	}
	int count=0;
	for(i=0;i<size;i++) {
		if(!see[(int)name[i]]) { count++; see[(int)name[i]]=1;}
	}
	if(count%2==0) printf("CHAT WITH HER!\n");
	else printf("IGNORE HIM!\n");
	return 0;
}
