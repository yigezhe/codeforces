//这里需要使用long long整数！
#include<stdio.h>
int main() {
    long long n;
    scanf("%lld",&n);
    long long fn=n/2;
    if(n%2==1) {
        fn=(-n/2-1);
    }
    printf("%lld\n",fn);
    return 0;
}
