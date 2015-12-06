//ribbon是一个棍子？
//先按最短的裁截，再次之，再次次之
//但这样处理有一个问题，就是如果剩下的长度不是a，b，c之一，那么这种处理是不行的！
//这个问题应该是找abc的最大公约数！
//10 4 6 gcd(4,6)=2,10/(2+3)
//10 2 4 gcd(2,4)=2,10/2
//10 1 4 gcd(1,4)=2,10/2
//用生成法来处理！
//coincide,相同！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int n,a,b,c;
#define N 4000+1
int cuts[N];
void sum(int i,int times) {
    //printf("sum(%d,%d)\n",i,times);
    if(i==n) {
        if(times>cuts[n])
            cuts[n]=times;
	return ;
    } else if(i>n) {
	    return;
    } else {
        sum(i+a,times+1);
        sum(i+b,times+1);
        sum(i+c,times+1);
    }
}
int main() {
    scanf("%d%d%d%d",&n,&a,&b,&c);
    //printf("%d %d %d\n",a,b,c);

    //让abc从小到大排列！
    if(a>b) { int tmp=a; a=b; b=tmp; }
    if(b>c) { int tmp=b; b=c; c=tmp; }
    if(a>b) { int tmp=a; a=b; b=tmp; }
    //printf("%d %d %d\n",a,b,c);
    if(n%a==0) {
	    printf("%d\n",n/a);
	    return 0;
    }
    int i;
    for(i=0; i<N; i++) {
        cuts[i]=0;
    }
    sum(0,0);
    printf("%d\n",cuts[n]);

    return 0;
}
