/*interface*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define M 1000000007
int fib(int n) {
	double z=sqrt(5.0);
	double x=(1+z)/2;
	double y=(1-z)/2;
	//这是一个超级大的一个数，用通项公式也不行！
	//int res=(int)((pow(x,n)-pow(y,n))/2+0.5)%M;
	int res=(int)((pow(x,n)-pow(y,n))/2)%M;
	return res;
}
/*interface implementation*/
/*client*/
int main() {
	int x,y;
	scanf("%d%d",&x,&y);
	int n;
	scanf("%d",&n);
	int fn;
	if(n%2==0) {
		fn=-fib(n-2)*x+fib(n-1)*y;
		printf("fib(%d)=%d,fib(%d)=%d\n",n-2,fib(n-2),n-1,fib(n-1));
	}else {
		fn=fib(n-2)*x-fib(n-1)*y;
		printf("fib(%d)=%d,fib(%d)=%d\n",n-2,fib(n-2),n-1,fib(n-1));
	}
	if(fn<0) fn=M+fn;
	printf("%d\n",fn%M);

	return 0;
}
