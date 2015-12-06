//raspberry是熊的食物！
//这个算法像是买卖股票！
//一个价格就是x［i］千克的raspberry!
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 100+1
int main() {
    int n,c;
    scanf("%d%d",&n,&c);
    int x[N];
    int i;
    for (i=0; i<n; i++) {
        scanf("%d",&x[i]);
    }
    int max=0;
    for (i=0; i<n-1; i++) {
        int lent=x[i];
        int sell=x[i+1];
        int profit=lent-sell-c;
        if(profit>max) {
            max=profit;
        }
    }
    printf("%d\n",max);
    return 0;
}
