#include<stdio.h>
int main() {
	int n;
	scanf("%d",&n);
	int i;
	int all=0;
	int max=0;
	for(i=0;i<n;i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		all -=  a;
		all += b;
		if(all>max) { max=all;};
	}
	printf("%d\n",max);
	return 0;
}
