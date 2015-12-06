//counterexample应该是反例的意思！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
//4 2, 2 4%2, 2 2%2
long long gcd(long long a,long long b) {
    long long tmp;
    while(b>0) {
        //printf("a=%lld b=%lld\n",a,b);
        tmp=a;
        a=b;
        b=tmp%b;
    }
    return a;
}
int main() {

    //printf("gcd(%d,%d)=%lld\n",4,2,gcd(4,2));
    long long l,r;
    scanf("%lld%lld",&l,&r);
    long long i,j,k;
    int find=0;
    //50*50*50可以在一秒内完成！
    for(i=l; i<=r && !find; i++) {
        for(j=l+1; j<=r && !find; j++) {
            if(i!=j) {
                for(k=l+1; k<=r && !find; k++) {
                    if(k!=i && k!=j) {
                        if(gcd(i,j)==1 && gcd(j,k)==1 && gcd(i,k)!=1) {
                            printf("%lld %lld %lld\n",i,j,k);
                            find=1;
                        }
                    }
                }

            }
        }
    }
    if(!find) printf("%d\n",-1);
    return 0;
}
