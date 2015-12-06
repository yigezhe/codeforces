#include<stdio.h>
int main() {
    long long n,k;
    scanf("%lld%lld",&n,&k);
    //printf("n=%lld,k=%lld\n",n,k);
    //mid也必须设置成long long
    long long mid=0;
    if(n%2==0) {
        mid=n/2;
    } else {
        mid=n/2+1;
    }
    //printf("mid=%lld\n",mid);
    if(k>mid) {
        printf("%lld\n",2*(k-mid));
    } else {
        printf("%lld\n",2*(k-1)+1);
    }
    return 0;
}
