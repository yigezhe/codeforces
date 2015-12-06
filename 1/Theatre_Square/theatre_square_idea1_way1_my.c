#include<stdio.h>
//codeforces上的计算机使用的是32bit操作系统
int main() {

    int n,m,a;
    scanf("%d %d %d",&n,&m,&a);
    //这里计算在长度上需要几块瓷砖
    long long l=0;
    if (n%a==0) {
        l=n/a;
    } else {
        l=n/a+1;
    }

    //这里计算在宽度上需要几块瓷砖
    long long w=0;
    if (m%a==0) {
        w=m/a;
    } else {
        w=m/a+1;
    }

    //codeforces上建议不使用%lld
    //只要禁止提醒，lld也是可以通过的！
    //%I64d在gcc上不能用！
    printf("%lli\n",l*w);

    return 0;
}
