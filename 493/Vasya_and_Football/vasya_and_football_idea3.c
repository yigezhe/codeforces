//办法三就是不去合并相同项，只是得到两张黄牌后，把那个队员的牌变为红牌！
//这样一来时间顺序不会改变！
#include<stdio.h>
#define N 100*2
int main() {
    char home[20+1];
    scanf("%s",home);
    char away[20+1];
    scanf("%s",away);
    int n;
    scanf("%d",&n);
    struct record {
        char team;
        int player;
        char card;
        int time;
    };
    struct record state[N];
    int n_state=0;
    int i,j;
    for(i=0; i<n; i++) {
        int t;
        char ha;
        int m;
        char yr;
        scanf("%d %c %d %c",&t,&ha,&m,&yr);
        //printf("time=%d,team=%c,player=%d,card=%c\n",t,ha,m,yr);
        int find=0;
        for(j=0; j<n_state; j++) {
            if(state[j].team==ha && state[j].player==m) {
                find=1;
            }
        }
        state[n_state].team=ha;
        state[n_state].player=m;
        if(find) {
            state[n_state].card='r';
        } else {
            state[n_state].card=yr;
        }
        state[n_state].time=t;
        n_state++;
    }
    //如果得到两张黄牌就不会继续再得到什么牌，那么我的程序是可以正常运转的！
    /*
    for(i=0; i<n_state; i++) {
        printf(" (%c,%d,%c,%d)",state[i].team,state[i].player,state[i].card,state[i].time);
    }
    printf("\n");
    */
    //这里过滤一下，只打印首次得到红牌的时间！
    int seen[256][90];
    for(i=0; i<256; i++) {
        for(j=0; j<90; j++) {
            seen[i][j]=0;
        }
    }
    for(i=0; i<n_state; i++) {
        if(!seen[(int)state[i].team][state[i].player] && state[i].card=='r') {
            if(state[i].team=='h') printf("%s",home);
            else printf("%s",away);
            printf(" ");
            printf("%d ",state[i].player);
            printf("%d\n",state[i].time);
            seen[(int)state[i].team][state[i].player]=1;
        }
    }
    return 0;
}
