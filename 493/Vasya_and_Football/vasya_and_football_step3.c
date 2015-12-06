//这里需要调整一下步骤！
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
                    //交换一下位置！
                    int k;
                    for(k=0; k<n_state; k++) {
                        if(state[k].card!='r') {
                            char tmp_team=state[k].team;
                            int tmp_player=state[k].player;
                            char tmp_card=state[k].card;
                            int tmp_time=state[k].time;

                            state[k].team=state[j].team;
                            state[k].player=state[j].player;
                            state[k].card=state[j].card;
                            state[k].time=state[j].time;

                            state[j].team=tmp_team;
                            state[j].player=tmp_player;
                            state[j].card=tmp_card;
                            state[j].time=tmp_time;
                            break;
                        }
                    }
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
            if(yr=='r') {
                //交换一下位置！
                int k;
                for(k=0; k<n_state; k++) {
                    if(state[k].card!='r') {
                        char tmp_team=state[k].team;
                        int tmp_player=state[k].player;
                        char tmp_card=state[k].card;
                        int tmp_time=state[k].time;

                        state[k].team=state[n_state-1].team;
                        state[k].player=state[n_state-1].player;
                        state[k].card=state[n_state-1].card;
                        state[k].time=state[n_state-1].time;

                        state[n_state-1].team=tmp_team;
                        state[n_state-1].player=tmp_player;
                        state[n_state-1].card=tmp_card;
                        state[n_state-1].time=tmp_time;

                        break;
                    }
                }
            }
        }
	/*
        for(j=0; j<n_state; j++) {
            printf(" (%c,%d,%c,%d)",state[j].team,state[j].player,state[j].card,state[j].time);
        }
        printf("\n");
	*/
    }
    //也可以根据time来sort整个state！
    for(i=0; i<n_state; i++) {
        if(state[i].card=='r') {
            if(state[i].team=='h') printf("%s",home);
            else printf("%s",away);
            printf(" ");
            printf("%d ",state[i].player);
            printf("%d\n",state[i].time);
        }
    }
    return 0;
}
