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
		if(all>max) { max=all;};//到站前的情况
		all -=  a;
		all += b;
		//到站后出发的情况！
	}
	printf("%d\n",max);
	return 0;
}
