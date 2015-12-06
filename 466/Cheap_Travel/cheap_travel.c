//submit ok!
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
    int n,m,a,b;
    scanf("%d%d%d%d",&n,&m,&a,&b);
    //n个站
    //一个站a元
    //m个站，b元！可以计算出平均每站多少钱！
    if(a<=(1.0*b/m)) {
        printf("%d\n",a*n);
    } else {
        if(n%m==0) {
            printf("%d\n",(n/m)*b);
        } else {
            if(((n/m)*b+(n%m)*a)> (n/m+1)*b) {
                printf("%d\n",(n/m+1)*b);
            } else {
                printf("%d\n",(n/m)*b+(n%m)*a);
            }
        }
    }
    //10 3 5 1
    //三站一元，十站，可以买十二站，话四元，就是可以多买！
    //这里比较夸张，就是一站要5元！
    return 0;
}
