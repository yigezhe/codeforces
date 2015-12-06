#include<stdio.h>
//这里我只留下最核心的！其它的多余的都要去掉！

int main() {
    unsigned long long n,m,a,t,s=0,u;
    scanf("%llu %llu %llu",&n,&m,&a);
    t=(m%a)?1:0;
    u=(n%a)?1:0;
    s=((m/a)+t)*((n/a)+u);
    printf("%llu\n",s);
    return 0;
}
