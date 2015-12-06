//这道题让我们去了解计算机整数处理的原理！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 1000
int main() {
	int n;
	scanf("%d",&n);
	char integer[N];
	scanf("%s",integer);
	int i;
	int change=0;
	for(i=0;i<n;i++) {
		if(integer[i]-'0'+1==2) change++;
		else break;
	}
	if(i<n)change++;
	printf("%d",change);
	return 0;
}
