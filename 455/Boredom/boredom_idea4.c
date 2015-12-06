#include<stdio.h>
#define N 100000
long long max(long long a,long long b) {
    if(a>b) return a;
    else return b;
}
/*interface*/
/*interface implementation*/
/*client*/
int main() {
    int n;
    //int a[N];
    scanf("%d",&n);
    int i;
    long long counter[N+1];
    long long score[N+1];
    for(i=0; i<=n; i++) {
        counter[i]=0;
    }
    for(i=0; i<n; i++) {
        //scanf("%d",&a[i]);
	int a;
        scanf("%d",&a);
        //counter[a]+=(long long)a;
        counter[a]+=a;
    }
    //score[i]在前i个数上可以得到的最高分！
    score[0]=0;
    score[1]=counter[1];
    score[2]=max(counter[1],counter[2]);
    for(i=3; i<=n; i++) {
	    score[i]=max(counter[i]+score[i-2],counter[i-1]+score[i-1-2]);
	    //counter[i]表示取第i个元素，则i－1要删除，再加上i-2位和之前的元素的最大得分
	    //counter[i-1]表示取第i-1个元素，则i－2要删除，再加上i-3位和之前的元素的最大得分
	    //我们需要两种得分中最大的！

    }
    printf("%lld\n",score[n]);
    return 0;
}
