//这个问题在考查gcd的实现！
#include<stdio.h>
//我用最简单的实现先试一下！
int gcd(int a,int b) {
    if(a<0) {
        a=-a;
    }
    if(b<0) {
        b=-b;
    }
    if(a==0) return b;
    if(b==0) return a;
    int gcd_ab=1;
    int i;
    for(i=2; i<=a; i++) {
        if(a%i==0 && b%i==0) {
            gcd_ab=i;
        }
    }
    return gcd_ab;
}

int main() {
    int a,b,n;
    scanf("%d%d%d",&a,&b,&n);
    while(1) {
        int take0=gcd(a,n);
        n-=take0;
        if(n<0) {
            printf("1\n");
            return 0;
        }
        int take1=gcd(b,n);
        n-=take1;
        if(n<0) {
            printf("0\n");
            return 0;
        }
    }
    return 0;
}
