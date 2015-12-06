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
int abs(int a) {
    if(a<0) return -a;
    else return a;
}
double possible(int m,int a,int n) {
    int c;
    int counter=0;
    for(c=1; c<=n; c++) {
        if(abs(c-a)<abs(c-m)) counter++;
    }
    return counter*1.0/n;
}
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int a;
    double max_possible=-10.0;
int best_a=0;
    for(a=1; a<=n; a++) {
        double p=possible(m,a,n);
        if(p>max_possible) {
            max_possible=p;
            best_a=a;
        }
    }
    printf("%d\n",best_a);
    return 0;
}
