#include<stdio.h>
//办法一数组来建立一个素数的判定，只要两个数不是素数就可以！
#define N 1000000+5
int main() {
    int p[N];
    int i,j;
    int n;
    scanf("%d",&n);
    for(i=2; i<=n; i++) {
        p[i]=1;
    }
    for(i=2; i*i<n; i++) {
        for(j=2; i*j<n; j++) {
            p[i*j]=0;
        }
    }
    p[1]=0;
    int a=4,b=n-4;
    while(p[a] || p[b]) {
        a++;
        b--;
    }
    printf("%d %d\n",a,b);
    return 0;
}
