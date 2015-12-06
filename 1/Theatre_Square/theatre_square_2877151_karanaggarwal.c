#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define REPi(i,a,b) for(i=a-1;i>=b;i--)
#define rep(i,b) REP(i,0,b)
#define repi(i,b) REPi(i,b,0)
#define si(n) scanf("%d",&n)
#define sort(arrr,n) qsort(arrr,n,sizeof(int),compare)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a<b?a:b)
#define pi(n) printf("%d\n",n)

int main() {
    int t,n,m,a,x,y;
    //这个偷懒我挺欣赏的！
    si(n);
    si(m);
    si(a);
    x=n/a;
    y=m/a;
    if(n%a)x++;
    if(m%a)y++;
    //x，y应该同时都是长整数，
    //这里应该是只把x变为长整数！
    //测试结果是只要其中一个是长整数，计算结果也是长整数！
    printf("%lld",(long long)(x*y));
    return 0;
}

