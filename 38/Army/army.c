//等级不能有跳级！
//梦想成真，实现他的梦想
//realize his dream
/*interface*/
#include<stdio.h>
#define N 100+1
/*interface implementation*/
/*client*/
int main() {
	int n;
	int year[N];
	scanf("%d",&n);
	int i;
	for(i=0;i<n-1;i++) {
		scanf("%d",&year[i]);
	}
	int a,b;
	scanf("%d%d",&a,&b);
	int sum=0;
	for(i=a-1;i<b-1;i++) {
		sum+=year[i];
	}
	printf("%d\n",sum);
	return 0;
}
