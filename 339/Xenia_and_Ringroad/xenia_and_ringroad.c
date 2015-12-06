#include<stdio.h>
#define M 100000
//完成3之前，必须完成2，如果2有重复，时间是不增加的
int step(int a,int b,int n) {
    if(a>=b) {
        return a-b;
    } else {
        return a+n-b;
    }
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int a[M];
    int i;
    for(i=0; i<m; i++) {
        scanf("%d",&a[i]);
    }
    long long t=a[0]-1;
    for(i=1; i<m; i++) {
        t+=step(a[i],a[i-1],n);
    }
    printf("%lld\n",t);

    return 0;
}
