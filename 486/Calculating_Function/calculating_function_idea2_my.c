#include<stdio.h>
int main() {
    long long n;
    scanf("%lld",&n);
    long long fn=0;
    int sign=-1;
    long long i;
    //速度不够！
    for(i=1;i<=n;i++) {
	    fn += sign*i;
	    printf("+ %d*%lld\n",sign,i);
	    sign*=-1;
    }
    printf("%lld\n",fn);
    return 0;
}
