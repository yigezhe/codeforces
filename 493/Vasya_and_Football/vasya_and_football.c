#include<stdio.h>
#define N 100*2
#define INF 10000000
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
                }
                break;
            }
        }
        if(!find) {
            state[n_state].team=ha;
            state[n_state].player=m;
            state[n_state].card=yr;
            if(yr=='r') {
                state[n_state].time=t;
            } else {
                state[n_state].time=INF;
            }
	    n_state++;
        }
	/*
        for(j=0; j<n_state; j++) {
		printf(" (%c,%d,%c,%d)",state[j].team,state[j].player,state[j].card,state[j].time);
	}
	printf("\n");
	*/
    }
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
