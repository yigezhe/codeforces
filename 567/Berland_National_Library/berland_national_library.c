//berland，俄国人也喜欢柏林？
//一般识别是进入了几个人，出来了几个人
//这里的识别时进入的人的识别码，出入的人的识别码？
//一个东西的必要性,就是对现有工作的帮助性
//以及她所带来的利益！
//阅读室的最小容量？
/*interface*/
#include<stdio.h>
#define N 1000000+1
/*interface implementation*/
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    int visitor[N];
    int i;
    for(i=0; i<N; i++) {
        visitor[i]=0;
    }
    int capacity=0;
    getchar();
    int out=0;
    for(i=0; i<n; i++) {
        char sign;
        int registration;
        scanf("%c %d",&sign,&registration);
        getchar();
        //printf("%c %d\n",sign,registration);
        if(sign=='+') {
            visitor[registration]=1;//代表进来过至少一次！
            if(out==0) capacity++;//只要有人进入，我们就要增加容量！
            //只要有人出去，我们就不用增加容量！
            else if(out>0) {
                out--;
            }
        } else {
            out++;
            //这里看来，就是出去的人多于容量时，才需要增加容量！
            //我们这里需要从来没有进来的！
            if(visitor[registration]==0 ) capacity++;
            //visitor[registration]--;//这是一个多余的代码！
        }
    }
    printf("%d\n",capacity);

    return 0;
}
