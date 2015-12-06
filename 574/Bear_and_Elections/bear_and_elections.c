////有点不可思议，一次性通过了，这是我长期努力的结果！
//力量和荣誉！
//bearland熊王国
//candidates候选人！
//cheat欺骗？
//bribing欺负？
//贿赂！
//选民是熊，熊喜欢糖果！
//5 1 11 2 8
//6 1 10 2 8
//7 1 9 2 8
//8 1 8 2 8
//9 1 7 2 8
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 100+1
#define MAX 2000+1
int main() {
    int n;
    scanf("%d",&n);
    int i;
    int a[N];
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    int win=0;
    int candy=0;
    do {
        int max_i=0;
        int max=-1;
        for(i=0; i<n; i++) {
            //这里的等号很重要，遇到相同时，总是选后面的是必须的
            //因为票数相同不代表你已经取胜！
            if(a[i]>=max) {
                max_i=i;
                max=a[i];
            }
        }
        if(max_i==0) {
            win=1;
        } else {
            a[max_i]--;
            a[0]++;
            candy++;
        }

    } while(!win);
    printf("%d\n",candy);
    return 0;
}
