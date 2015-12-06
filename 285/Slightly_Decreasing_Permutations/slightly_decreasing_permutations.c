/*interface*/
#include<stdio.h>
/*interface implementation*/
/*client*/
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	int i;
	for(i=1;i<=n-k-1;i++) {
		printf(" %d",i);
	}
	for(i=n;i>=n-k;i--) {
		printf(" %d",i);
	}
	printf("\n");

	return 0;
}
