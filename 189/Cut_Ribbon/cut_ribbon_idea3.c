//想法3就是使用硬币问题的算法！
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
	//硬币的面值，a,b,c;
	//硬币的个数,n/a,n/b,n/c;
	//先尽可能使用面值小的硬币，这样我们得到的硬币总数应该最多！
	//好像行不通？
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
