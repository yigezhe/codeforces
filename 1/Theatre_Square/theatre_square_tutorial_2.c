#include<stdio.h>
int main() {
	int n,m,a;
	scanf("%d%d%d",&n,&m,&a);
	printf("%d\n",((m+a-1)/a)*((n+a-1)/a));
	return 0;
}
