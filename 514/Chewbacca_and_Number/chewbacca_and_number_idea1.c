//submit ok!
//invert互换！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
	//printf("%d\n",1<<31);
	//printf("%u\n",(unsigned int ) (1<<31));
	long long x;
	scanf("%lld",&x);
	int replace[10];
	replace[0]=0;
	replace[1]=1;
	replace[2]=2;
	replace[3]=3;
	replace[4]=4;
	replace[5]=4;
	replace[6]=3;
	replace[7]=2;
	replace[8]=1;
	replace[9]=0;
	//尽可能替换成最小的！
	long long newx=0;
	long long ten=1;
	while(x>0) {
		//这里的if就是为了处理，首数字是9时，我们不能把它变为0
		//而是要保持9！
		if(x==9) newx=newx+x*ten;
		else newx=newx+replace[x%10]*ten;
		x=x/10;
		ten*=10;
	}
	printf("%lld\n",newx);
	return 0;
}
