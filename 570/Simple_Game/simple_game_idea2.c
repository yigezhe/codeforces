//misha的初始数字是m
//andrew的初始数字是a
//在1到n之间选择！
//c是一个随机数
//看谁的数接近c，距离相同misha赢！
//距离不同谁近，谁赢！
//n是可以选择的数字范围！
//这是一个概率问题！
//每一个都计算一遍时间肯定超时
//因为题目设置为10^9级别的问题！
//只能先实现一个看有没有超时！
//我的想法是a必须选择中间位置，才能获取最大概率！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int mid=(1+n)/2;
    //printf("mid=%d\n",mid);
    //printf("m=%d\n",m);
    int a;
    if(n%2==1) {
        if(m==mid) {
            //mid-1<1,则mid＝1
            //mid=0不会出现，因为我们从1开始计数！
            //这时n应该是1
            //a只能选1，虽然选一后的胜率只是0！
            if(mid-1>=1) {
                a=mid-1;
            } else {
                a=mid;
            }
        } else if(m>mid) {
            a=m-1;
        } else {
            a=m+1;
        }
    } else {
        if(m==mid) {
            a=mid+1;
            //printf("a=%d\n",a);
        } else if(m==mid+1) {
            a=mid;
        } else if(m<mid) {
            a=m+1;
        } else {
            a=m-1;
        }
    }
    printf("%d\n",a);
    return 0;
}
