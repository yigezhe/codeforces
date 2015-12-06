/*interface*/
#include<stdio.h>
/*interface implementation*/
/*client*/
int main() {
	int k,l;
	scanf("%d%d",&k,&l);
	int counter=0;
	while(l%k==0) {
		l=l/k;
		counter++;
	}
	if(l==1) printf("YES\n%d\n",counter-1);
	else printf("NO\n");
	return 0;
}
