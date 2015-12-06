//submit ok!
//讲了一段故事！
//vanya喜欢玩牌，natasha把vanya的牌藏了起来。
//natasha找到了n张牌，他想在这n张牌里找到和为零的组合！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 1000+1
int main() {
    int n,x;
    scanf("%d%d",&n,&x);
    int i;
    int positive=0;
    int negative=0;

    for(i=0; i<n; i++) {
        int card;
        scanf("%d",&card);
        if(card>0)positive+=card;
        if(card<0)negative+=-card;
    }
    int sum;
    if(positive>negative) {
        sum=positive-negative;
        if(sum%x==0) {
            printf("%d\n",sum/x);
        } else {
            printf("%d\n",sum/x+1);
        }

    } else if(positive<negative) {
        sum=negative-positive;
        if(sum%x==0) {
            printf("%d\n",sum/x);
        } else {
            printf("%d\n",sum/x+1);
        }

    } else {
        printf("0\n");
    }

    return 0;
}
