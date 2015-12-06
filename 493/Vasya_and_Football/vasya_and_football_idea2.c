//这里需要调整一下步骤！
//办法一，就是直接sort一下！
//这里要操作整个巨大的struct，不好！
//办法二，也是sort，但是数据依然保存在那里，但是只是sort一下数据的位置
//就是我们单独拿出一个数组来sort！
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
    int i;
    for(i=0; i<n; i++) {
        int t;
        char ha;
        int m;
        char yr;
        scanf("%d %c %d %c",&t,&ha,&m,&yr);
        //printf("time=%d,team=%c,player=%d,card=%c\n",t,ha,m,yr);
        int j;
        int find=0;
        for(j=0; j<n_state; j++) {
            if(state[j].team==ha && state[j].player==m) {
                find=1;
                if(state[j].card!='r') {
                    state[j].card='r';
                    state[j].time=t;
                    break;
                }
            }
        }
        if(!find) {
            state[n_state].team=ha;
            state[n_state].player=m;
            state[n_state].card=yr;
            state[n_state].time=t;
            n_state++;
        }
    }
    //也可以根据time来sort整个state的位置！
    /*
    for(i=0; i<n_state; i++) {
	    printf(" (%c,%d,%c,%d)",state[i].team,state[i].player,state[i].card,state[i].time);
    }
    printf("\n");
    */

    int position[N];
    for(i=0; i<n_state; i++) {
        position[i]=i;
    }
    //这是我的sort！
    for(i=0; i<n_state-1; i++) {
        int j;
        int min=i;
        for(j=i+1; j<n_state; j++) {
            //if(state[j].time<state[min].time) {//必须在改变后的位置上来比较！
            if(state[position[j]].time<state[position[min]].time) {
                min=j;
            }
        }
        int tmp=position[i];
        position[i]=position[min];
        position[min]=tmp;
    }
	/*
    for(i=0; i<n_state; i++) {
        printf(" %d",position[i]);
    }
    printf("\n");
    for(i=0; i<n_state; i++) {
	    int pi=position[i];
	    printf(" (%c,%d,%c,%d)",state[pi].team,state[pi].player,state[pi].card,state[pi].time);
    }
    printf("\n");

    */

    for(i=0; i<n_state; i++) {
        int pi=position[i];
        if(state[pi].card=='r') {
            if(state[pi].team=='h') printf("%s",home);
            else printf("%s",away);
            printf(" ");
            printf("%d ",state[pi].player);
            printf("%d\n",state[pi].time);
        }
    }
    return 0;
}
