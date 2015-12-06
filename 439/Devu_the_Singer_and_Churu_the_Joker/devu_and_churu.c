//n首歌的时间，（n－1）*10分钟的休息时间
//2 10 2 10 1
//2 20 2 15 1
//5 2 10 2 10 1
//
//2 10 1 10 1=24
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
	int n,d;
	scanf("%d%d",&n,&d);
	int total=0;
	int i;
	for(i=0;i<n;i++) {
		int a;
		scanf("%d",&a);
		total+=a;
	}
	total+=(n-1)*10;
	int jokes=(n-1)*2;
	if(d<total) {
		printf("%d\n",-1);
		return 0;
	}
	else {
		jokes+=(d-total)/5;
	}
	printf("%d\n",jokes);
	return 0;
}
