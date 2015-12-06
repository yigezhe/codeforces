/*interface*/
#include<stdio.h>
/*interface implementation*/
/*client*/
int main() {
	int n,k;
	scanf("%d%d",&n,&k);
	int i;
	for(i=k+1;i>=1;i--) {
		printf(" %d",i);
	}
	for(i=k+2;i<=n;i++) {
		printf(" %d",i);
	}
	printf("\n");

	return 0;
}
