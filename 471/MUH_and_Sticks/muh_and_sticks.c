//四个相同的棍子表示动物的腿
//一个较长的棍子表示头
//一个较短的棍子表示身子
//如果头部和身子一样长，那么就是大象，
//如果头部比身子短，就是熊！
//办法一，首先找到四个相同的棍子
//之后判断剩余的两个棍子是不是相同。

/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define S 10
#define L 6
int main() {
    int same[S];
    int i;
    for(i=0; i<S; i++) {
        same[i]=0;
    }
    for(i=0; i<L; i++) {
	    int a;
        scanf("%d",&a);
        same[a]++;
    }
    int maybe=0;
    for(i=0; i<S; i++) {
        if(same[i]>=4) {
            maybe=1;
            break;
        } else {
            maybe=0;
        }
    }
    if(maybe==0) {
        printf("Alien\n");
        return 0;
    }
    //去掉相同的四条腿！
    for(i=0; i<S; i++) {
        if(same[i]>=4) same[i]-=4;
    }
    //达到目的就可以，不用做更多的工作！
    //如果有相同的两个数字，那么就是头部与身子相同，就是大象！
    for(i=0; i<S; i++) {
        if(same[i]==2) {
            printf("Elephant\n");
            return 0;
        }
    }
    printf("Bear\n");
    return 0;
}
