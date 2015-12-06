#include<stdio.h>
int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    //策略很简单，一个蜡烛一个蜡烛地烧，
    //凑够b个蜡烛，总蜡烛就加一，直到所有的总蜡烛烧完！
    int remain=a;
    //先烧掉b的整数倍个蜡烛！
    int time=0;
    while(remain>0) {
        //printf("r=%d\n",remain);
        if(remain<b) {
            time+=remain;
            remain=0;
        } else {
            time+=b;
            //烧b个
            remain-=b;
            //加一个！
            remain+=1;
        }
    }
    printf("%d\n",time);
    return 0;
}
