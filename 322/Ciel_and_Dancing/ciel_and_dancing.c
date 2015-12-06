/*interface*/
#include<stdio.h>
/*interface implementation*/
/*client*/
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d\n",n+m-1);
	int i;
	for(i=0;i<m;i++) {
		printf("1 %d\n",i+1);
	}
	for(i=0;i<n-1;i++) {
		printf("%d 1\n",i+2);
	}

	return 0;
}
