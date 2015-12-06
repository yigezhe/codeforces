/*interface*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*interface implementation*/
/*client*/
int main() {
    long long n;
    scanf("%lld",&n);
    int m=(int)sqrt(n);
    int i;
    for(i=2; i<=m; i++) {
        int count=0;
        while(n%i==0) {
            n=n/i;
            count++;
        }
	//就是不管怎样留一个就可以！
        if(count>0) n=n*i;
    }
    printf("%lld\n",n);
    return 0;
}
