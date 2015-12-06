
/*interface*/
#include<stdio.h>
/*interface implementation*/
/*client*/
int main() {
	int x;
	scanf("%d",&x);
	int counter=0;
	while(x>0) {
		if(x%2==1) counter++;
		x=x/2;
	}
	printf("%d\n",counter);
	return 0;
}
