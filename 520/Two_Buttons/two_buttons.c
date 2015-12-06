#include<stdio.h>
#define N 10000
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    //printf("here");
    //这里使用bfs来处理
    struct state {
        int x;
        int step;
    };
    struct state queue[2*N];
    int start=0;
    int end=0;
    queue[end].x=n;
    queue[end].step=0;
    end++;
    while(start<end) {
        struct state top;
        top.x=queue[start].x;
        top.step=queue[start].step;
        start++;
        printf("%d->",top.x);
        if(top.x==m) {
            printf("%d\n",top.step);
            return 0;
        }

        struct state red;
        red.x=top.x*2;
        red.step=top.step+1;
        queue[end].x=red.x;
        queue[end].step=red.step;
        end++;
        printf("%d-",red.x);
        struct state blue;
        blue.x=top.x-1;
        blue.step=top.step+1;
        queue[end].x=blue.x;
        queue[end].step=blue.step;
        end++;
        printf("%d\n",blue.x);
    }
    return 0;
}
