#include<stdio.h>
//办法一数组来建立一个素数的判定，只要两个数不是素数就可以！
#define N 1000000+5
int main() {
    //n 1 n-1
    //n 2 n-2
    //n 3 n-3
    //n 4 n-4
    int p[N];
    int i,j;
    int n;
    scanf("%d",&n);
    for(i=1; i<n; i++) {
        p[i]=1;
    }
    for(i=4; i<n; i++) {
        for(j=2; j*j<n; j++) {
            if(i%j==0) p[i]=0;
        }
    }
    int a=4,b=n-4;
    while(p[a] || p[b]) {
	    a++;
	    b--;
    }
    printf("%d %d\n",a,b);
    return 0;
}
