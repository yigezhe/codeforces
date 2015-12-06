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
#define S 1000+1
struct stock {
    int price,volume;
};
void sort(struct stock *,int);
void insertion_sort(struct stock *,int);
void sort(struct stock *data,int length) {
    insertion_sort(data,length);
}
//这个问题，n^2级别复杂度的排序算法也是可以的，因为这里的n是1000！
void insertion_sort(struct stock *data,int length) {
    int i;
    for (i = 0; i < length; i++) {
        int j = i;
        //找到i左边不符合次序的元素！
        while (j > 0 && data[i].price > data[j - 1].price) {
            j--;
        }
        struct stock tmp;
        tmp.price = data[i].price;
        tmp.volume = data[i].volume;
        int k;
        //元素后撤！
        for (k = i; k > j; k--) {
            data[k].price = data[k - 1].price;
            data[k].volume = data[k - 1].volume;
        }
        //把元素i放在不符合的元素的位置上！
        data[j].price = tmp.price;
        data[j].volume = tmp.volume;
    }
}

int main() {
    int n,s;
    scanf("%d%d",&n,&s);
    struct stock buy[S];
    int nb=0;
    struct stock sell[S];
    int ns=0;
    int i;
    for(i=0; i<n; i++) {
        char direction;
        int price,volume;
        getchar();//把前面的回车键去除！
        scanf("%c",&direction);
        scanf("%d%d",&price,&volume);
        //先分开，再排序！
        if(direction=='B') {
            buy[nb].price=price;
            buy[nb].volume=volume;
            nb++;
        }
        if(direction=='S') {
            sell[ns].price=price;
            sell[ns].volume=volume;
            ns++;
        }
    }
    sort(sell,nb);
    i=0;
    //我们只打印最后面s个价格低的！
    if(ns>s) {
        i=ns-s;
    }
    //1234 3
    for(; i<s && i<ns; i++) {
        printf("S %d %d\n",buy[i].price,buy[i].volume);
    }
    sort(buy,nb);
    for(i=0; i<s && i<nb; i++) {
        printf("B %d %d\n",sell[i].price,sell[i].volume);
    }
    return 0;
}
