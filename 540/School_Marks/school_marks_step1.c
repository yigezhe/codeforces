#include<stdio.h>
#define N 1000+5
int main() {
    int n,k,p,x,y;
    //n [1,999] 奇数 总的测试数
    //k [0,n) 已经写出来的测试数！
    //p [1,1000] 一个测试所能得到的最大分值！
    //x [n,n*p] 同学不会抄的值
    //y [1,p] 妈妈不会批评的值！
    //a1,...,ak就是依据取得的分值！
    scanf("%d%d%d%d%d",&n,&k,&p,&x,&y);
    int sum=0;
    int i,j;
    int mark[N];
    for(i=0; i<n; i++) {
        //因为至少是一分，所以全部初始化为1是合适的！
        mark[i]=1;
    }
    for(i=0; i<k; i++) {
        scanf("%d",mark+i);
    }
    //按最低分来取！
    //这里应该是每题得到y分？
    //这里的中间值，使问题复杂了一点！
    //这是概率里的一个基本知识！
    //中间数！
    //要先排序，才可以用下面的公式找到中间数！
    for(i=0; i<n; i++) {
        for(j=j+1; j<n; j++) {
            if(mark[i]>mark[j]) {
                int tmp=mark[i];
                mark[i]=mark[j];
                mark[j]=tmp;
            }
        }
    }

    int median=mark[(n+1)/2];
    printf("中间数：%d\n",median);
    //median>=y
    sum=0;
    for(i=0; i<n; i++) {
        sum+=mark[i];
    }
    printf("总和：%d\n",sum);
    //sum<=x
    return 0;
}
