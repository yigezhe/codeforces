#include<stdio.h>
#include<string.h>
#define N 100+5
int main() {
	char s[N];
	scanf("%s",s);
	int i;
	int size=strlen(s);
	
	int find=0;
	for(i=0;i<size;i++) {
		if(find==0 && s[i]=='h') {
			find=1;
		} else if(find==1 && s[i]=='e') {
			find=2;
		} else if(find==2 && s[i]=='l') {
			find=3;
		} else if(find==3 && s[i]=='l') {
			find=4;
		} else if(find==4 && s[i]=='o') {
			find=5;
		}
	}
	if(find==5) printf("YES\n");
	else printf("NO\n");

	return 0;
}
