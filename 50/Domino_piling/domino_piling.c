#include<stdio.h>
int main() {
	int M,N;
	scanf("%d%d",&M,&N);
	if (M%2==0 && N%2==0) {
		printf("%d\n", (M/2)*(N/2)*2);
	} else if(M%2==0 && N%2!=0) {
		printf("%d\n", (M/2)*(N/2)*2+M/2);
	} else if(M%2!=0 && N%2==0) {
		printf("%d\n", (M/2)*(N/2)*2+N/2);
	}else {
		printf("%d\n", (M/2)*(N/2)*2+N/2+M/2);
	}
	//可以有一个统一的公式
	//printf("%d\n", M/2*N/2*2+M%2*N/2+N%2*M/2);

	return 0;
}
