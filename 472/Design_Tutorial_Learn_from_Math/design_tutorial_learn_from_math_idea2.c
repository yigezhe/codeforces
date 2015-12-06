#include<stdio.h>
//办法一数组来建立一个素数的判定，只要两个数不是素数就可以！
#define N 1000000+5
int is_prime(int n) {
    int i;
    for(i=2; i*i<=n; i++) {
        if(n%i==0) return 0;
    }
    return 1;
}

int main() {
    int n;
    scanf("%d",&n);
    int a=4,b=n-4;
    while(1) {
	if(!is_prime(a) && !is_prime(b)) break;
	if(a>n) break;
	if(b<0) break;
        a++;
        b--;
	    //printf("%d %d\n",a,b);
    }
    printf("%d %d\n",a,b);
    return 0;
}
