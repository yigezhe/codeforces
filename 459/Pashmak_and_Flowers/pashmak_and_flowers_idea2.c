//给一对花！
//两朵花之间的美丽度差距最大！
//先获取最大值与最小值，
//其实可以先排序，然后看最小值多少个，最大值多少个。
//也可以不排序，直接找出最大值，并统计个数。
//找出最小值，并统计个数，然后，两个个数相乘就是我们想要的结果！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 200000
int main() {
    int n;
    int b[N];
    scanf("%d",&n);
    int i;
    int min=1000000001;
    int max=0;
    //我可以同时处理掉，但是我先看主要部分如何实现，
    //再去调整实现细节
    for(i=0; i<n; i++) {
        scanf("%d",&b[i]);
        if(b[i]>max) max=b[i];
        if(b[i]<min) min=b[i];
    }
    //printf("%d %d\n",max,min);
    //这里int不能满足要求！
    long long mins=0;
    long long maxs=0;
    for(i=0; i<n; i++) {
        if(b[i]==max) maxs++;
        if(b[i]==min) mins++;
    }
    //printf("%lld %lld\n",maxs,mins);
    if(max==min) {
	    //c(maxs,2);
	    //从相同元素里选出两个的个数，才是我们要的解答！
        printf("%d %lld\n",0,maxs*(maxs-1)/2);
    } else {
        printf("%d %lld\n",max-min,maxs*mins);
    }
    //printf("%d\n",1<<30);

    return 0;
}
