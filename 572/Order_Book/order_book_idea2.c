//stock exchange orders股票交换顺序？
//order一个命令一个操作！
//一个买入或卖出的操作，在股票交易市场中！
//participant参与者！
//买入或卖出q张股票，在p价格上！
//好的程序软件可以自动化处理股票的买卖！
//这样一来，好的算法可以直接帮助你在股票上挣钱！而且是一种快速的挣钱！
//descending order递减的顺序！
//文字描述有点太复杂！
//no more than,不是no more then!
//只是实现一种分离？
//这里没有考虑一个卖出，买入的时间问题，股票买卖中的时间也是非常重要的！
//mac笔记本的一二三指的不同操作非常有价值！
//未完成的工作，相同价格的股票需要合并！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 100000+1
#define S 50+1

int main() {
    int n,s;
    scanf("%d%d",&n,&s);
    int buy[N];
    int sell[N];
    int i;
    for(i=0; i<N; i++) {
        buy[i]=0;
        sell[i]=0;
    }
    for(i=0; i<n; i++) {
        char direction;
        int price,volume;
        getchar();//把前面的回车键去除！
        scanf("%c",&direction);
        scanf("%d%d",&price,&volume);
        //先分开，再排序！
        if(direction=='B') {
            buy[price]+=volume;
        }
        if(direction=='S') {
            sell[price]+=volume;
        }
    }
    int sell_price[S];
    int sell_volume[S];
    int counter=0;
    int ns=0;
    for(i=0; i<N; i++) {
        if(counter==s) break;
        if(sell[i]!=0) {
            sell_price[ns]=i;
            sell_volume[ns]=sell[i];
	    ns++;
        }
    }
    for(i=ns-1; i>=0; i--) {
            printf("S %d %d\n",sell_price[i],sell_volume[i]);
    }

    counter=0;
    for(i=N-1; i>=0; i--) {
        if(counter==s) break;
        if(buy[i]!=0) {
            printf("B %d %d\n",i,buy[i]);
            counter++;
        }
    }
    return 0;
}
