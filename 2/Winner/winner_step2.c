/*interface*/
#include<stdio.h>
#include<string.h>
/*interface implementation*/
char player[1000][32+1];
int winner[1000];
int players;
void add(char *name,int score) {
    //我要根据分数来插入！
    //保证最高分在最前面！
    int i;
    for(i=players-1; i>=0; i--) {
        if(winner[i]>=score) break;
    }
    int where=i+1;
    for(i=players; i>where; i--) {
        strcpy(player[i],player[i-1]);
        winner[i]=winner[i-1];
    }
    strcpy(player[where],name);
    winner[where]=score;
    players++;
}
void adjust(int who,int score) {
    //我要根据分数来插入！
    //保证最高分在最前面！
    //更好的想法是根据score的正负来决定下一步怎么走！
    int i;
    char name2[32+1];
    int score2;

    winner[who]+=score;
    if(score>0) {
        //93218
        //98321
        for(i=who-1; i>=0; i--) {
            if(winner[i]>=winner[who]) break;
        }
        int where=i+1;
        score2=winner[who];
        strcpy(name2,player[who]);
        for(i=who; i>=where; i--) {
            strcpy(player[i],player[i-1]);
            winner[i]=winner[i-1];
        }
        strcpy(player[where],name2);
        winner[where]=score2;
    } else if(score<0) {
        //94021
        //94210
        for(i=who+1; i<players; i++) {
            if(winner[i]<winner[who]) break;
        }
        int where=i-1;
        score2=winner[who];
        strcpy(name2,player[who]);
        for(i=who; i<where; i++) {
            strcpy(player[i],player[i+1]);
            winner[i]=winner[i+1];
        }
        strcpy(player[where],name2);
        winner[where]=score2;

    }
}
int find(char *name) {
    int i;
    for(i=0; i<players; i++) {
        if(strcmp(player[i],name)==0) return i;
    }
    return -1;
}
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    //printf("n = %d\n",n);
    int i;
    players=0;
    for(i=0; i<n; i++) {
        printf("----------\ni = %d\n",i);
        int j;
        for(j=0; j<players; j++) {
            printf("%s %d\n",player[j],winner[j]);
        }
        printf("----------\n");

        char name[32+1];
        int score;
        scanf("%s%d",name,&score);
        //printf("name = %s, score = %d\n",name,score);
        int who=find(name);
        if(who==(-1)) {
            //没找到就添加一个新纪录！
            //printf("add name=%s\n",name);
            add(name,score);
        } else {
            //printf("adjust name=%s\n",player[who]);
            adjust(who,score);
        }
        printf("----------\ni = %d\n",i);
        //int j;
        for(j=0; j<players; j++) {
            printf("%s %d\n",player[j],winner[j]);
        }
        printf("----------\n");
    }
    /*
    for(i=0; i<players; i++) {
        printf("%s %d\n",player[i],winner[i]);
    }
    */
    printf("%s\n",player[0]);
    return 0;
}
