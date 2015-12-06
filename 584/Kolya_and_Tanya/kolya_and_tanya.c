
/*interface*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define M 1000000007
/*interface implementation*/
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    long long res=0;
    long long n27=1;
    long long n7=1;
    int i;
    for(i=0;i<n;i++) {
	    n27=(n27*27)%M;
	    //printf("27^%d=%lld\n",i,n27);
	    n7=(n7*7)%M;
	    //printf("7^%d=%lld\n",i,n7);
    }
    res=n27-n7;
    if(res<0) {
	    res=M+res;
    }
    printf("%lld\n",res);
    return 0;
}
