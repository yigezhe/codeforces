//初始n个数字，由苹果先生给土豆先生，
//土豆先生把所有和相加
//这个题目应该是在考场排序算法
//把n个数字还给苹果先生
//分割成单个和其他
//从中间分隔
/*interface*/
int compare(const void *,const void *);
/*interface implementation*/
#include<stdio.h>
int compare(const void *a,const void *b) {
    int *x = (int *) a;
    int *y = (int *) b;
    return *y - *x;
}
void print(int *data,int length) {
    int i;
    for(i=0; i<length; i++) {
        printf(" %d",data[i]);
    }
    printf("\n");
}
/*client*/
#include<stdlib.h>
#define N 300000
int main() {
    //自己总结出一个数学公式
    //score=n*a1+(n-1)*a2+...+2*an-1-a1;
    int n;
    scanf("%d",&n);
    int i;
    long long sum=0;
    int a[N];
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }

    //print(a,n);
    qsort(a,n,sizeof(int),compare);
    //print(a,n);
    for(i=0; i<n; i++) {
        //这里如果是两个int相乘，结果会放入int中，超出的部分被剪掉了！
        //所以必须是两个long long相乘，结果保存在long long中，超出int，但不超出long long的整数将被保存！
        sum+=(long long)(n+1-i)*(long long)a[i];
    }
    sum=sum-a[0];
    printf("%lld\n",sum);
    return 0;
}
