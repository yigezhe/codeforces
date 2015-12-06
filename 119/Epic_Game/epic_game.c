#include<stdio.h>

int gcd(int a,int b) {
    //保证在处理正整数！
    if(a<0) {
        a=-a;
    }
    if(b<0) {
        b=-b;
    }
    if(b>a) {
        int tmp=a;
        a=b;
        b=tmp;
    }
    //a b
    //b a mode b
    while(b!=0 ) {
    //printf("%d,%d\n",a,b);
        int tmp=a;
        a=b;
        b=tmp%b;
    }
    return a;
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
