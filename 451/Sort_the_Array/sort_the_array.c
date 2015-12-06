//最喜欢array，其实它是最简单，最直接的数据结构！
//增长的顺序！
//逆序中间一段就可以让一个数组建立一个升序！
//如果用全部枚举法，
//时间上好像太多。
//n+n-1+...+1总共n(n+1)/2个片段需要检查，这样问题的时间复杂度是n^2
//n=10^5 问题的级别就是10^10，这样的复杂度无法在1秒内解决！
//
//思路二，能够通过逆序交换变为升序的数组，应该是分三个部分
//升序，逆序，升序！成功了，加油，你是最棒的！
//没有这个结构的就打印no，有这个结构的就打印yes！
//participant参与者！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 100000+1
int main() {
    int n;
    scanf("%d",&n);
    int i;
    int a[N];
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    i=0;
    //int increase1_start=i;
    while(i+1<n) {
        if(a[i]<=a[i+1]) {
            i++;
            //保证第一段是升序！
        } else {
            break;
        }
    }
    //int increase1_end=i;
    //a[0]>=a[1],i=0
    int reduced_start=i;
    while(i+1<n) {
        if(a[i]>=a[i+1]) {
            i++;
            //保证第二段是降序！
        } else {
            break;
        }
    }
    int reduced_end=i;

    //int increase2_start=i;
    while(i+1<n) {
        if(a[i]<a[i+1]) {
            i++;
            //保证第三段是升序！
        } else {
            break;
        }
    }
    int increase2_end=i;
    //321
    //(0,0)(0,2)(2,2)
    //2134
    //(0,0)(0,1)(1,3)
    //2<3
    //3124
    //(0,0)(0,1)(1,3)
    //3>2
    //12
    //(0,1)(1,1)(1,1)
    if(increase2_end==n-1) {
        //还要有进一步的工作！
        //中间第二段是降序，我们还要保证降序互换后整个是一个升序！
        if((a[reduced_start]<=a[reduced_end+1] || reduced_end+1>=n) &&
                (a[reduced_end]>=a[reduced_start-1] || reduced_start-1<0)) {
            printf("yes\n");
            //printf("%d %d\n",a[reduced_end],a[reduced_start]);
            printf("%d %d\n",reduced_start+1,reduced_end+1);

        } else {
            printf("no\n");

        }
    } else {
        printf("no\n");
    }
    return 0;
}
