#include<stdio.h>
#include<string.h>
#define N 100+5
int main() {
	char p[N];
	scanf("%s",p);
	int size=strlen(p);
	int i;
	for(i=0;i<size;i++) {
		if(p[i]=='H' || p[i]=='Q' || p[i]=='9' ) {
			printf("YES\n");
			return 0;
		}
	}
	printf("NO\n");
	return 0;
}
