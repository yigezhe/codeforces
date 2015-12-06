#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int gcd(int a,int b) {
	if(b==0) return a;
	else return gcd(b,a%b);
}
int main() {
    int x,y,a,b;
    scanf("%d%d%d%d",&x,&y,&a,&b);
    //printf("gcd(%d,%d)=%d",2,4,gcd(2,4));
    //printf("gcd(%d,%d)=%d\n",x,y,gcd(x,y));
    int div=x*y/gcd(x,y);
    //printf("div=%d\n",div);
    int start;
    if(a%div==0)start=a/div;
    else start=a/div+1;
    int end=b/div;

    int res=end-start+1;
    printf("%d\n",res);
    return 0;
}
