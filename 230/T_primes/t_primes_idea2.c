//t primes 应该是1 p p*p结构！
//这里第一步是判断n是平方数，
//第二步时判断sqrt(n)是素数！
/*interface*/
#include<stdio.h>
#include<math.h>
/*interface implementation*/
/*client*/
int is_squre(long long n) {
    if((long long)sqrt(n)==sqrt(n)) return 1;
    else return 0;
}
int is_prime(long long n) {
    if(n<=1) return 0;
    //所有偶数都去除掉！
    else if(n==2) return 1;
    else if(n%2==0) return 0;
    else {
        long long i;
	//只用奇因数来测试整除性！
        for(i=3; i*i<=n; i+=2) {
            if(n%i==0) return 0;
            }
        return 1;
    }
}
int is_t_prime(long long n) {
    if(is_squre(n)) {
        long long p=(long long)sqrt(n);
        if(is_prime(p)) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}
int main() {
    int n;
    scanf("%d",&n);
    int i;
    for(i=0; i<n; i++) {
	    //这里处理的是12位整数，所以需要longlong
        long long x;
        scanf("%lld",&x);
        if(is_t_prime(x)) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
    return 0;
}
