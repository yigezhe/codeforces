#include<stdio.h>
#include<string.h>
#define N 100+5
int main() {
    char players[N];
    scanf("%s",players);
    char one7[]="1111111";
    /*
    int i;
    for(i=0; i<9; i++) {
        printf("%d:%d\n",i,(int)one7[i]);
    }
    */
    char zero7[]="0000000";
    int pi=0;
    int oi=0;
    int zi=0;
    while(players[pi]!='\0') {
        //printf("pi=%d,oi=%d,zi=%d\n",pi,oi,zi);
        if(players[pi]=='1') {
            while((players[pi]!='\0') && (one7[oi]!='\0') && (players[pi]==one7[oi])) {
//8可以进来说明我的这个one7[oi]!='\0'判断没有起作用！
                //printf("1 pi=%d,oi=%d,zi=%d\n",pi,oi,zi);
                oi++;
                pi++;
            }
            if(oi==7) {
                printf("YES\n");
                return 0;
            }

            oi=0;
        } else {
            while(players[pi]!='\0' && zero7[zi]!='\0' && players[pi]==zero7[zi]) {
                //printf("2 pi=%d,oi=%d,zi=%d\n",pi,oi,zi);
                zi++;
                pi++;
            }
            if(zi==7) {
                printf("YES\n");
                return 0;
            }
            zi=0;
        }
    }

    printf("NO\n");
    return 0;
}
