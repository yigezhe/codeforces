/*interface*/
//可能不是按先来的顺序，而是按字母排序！
#include<stdio.h>
#include<string.h>
/*interface implementation*/
char player[1000][32+1];
int points[1000];
char firster[1000][32+1];
int nf;
int np;
void add(char *name,int score) {
    strcpy(player[np],name);
    points[np]=score;
    np++;
}
int find(char *name) {
    int i;
    for(i=0; i<np; i++) {
        if(strcmp(player[i],name)==0) return i;
    }
    return -1;
}
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    int i;
    np=0;
    char max_name[32+1];
    int max_score=0;

    for(i=0; i<n; i++) {
        char name[32+1];
        int score;
        scanf("%s%d",name,&score);
        //printf("name = %s, score = %d\n",name,score);
        int who=find(name);
        if(who==(-1)) {
            add(name,score);
            if(score>max_score) {
                max_score=score;
                strcpy(max_name,name);
            }
        } else {
            points[who]+=score;
            if(points[who]>max_score) {
                max_score=points[who];
                strcpy(max_name,player[who]);
            }
        }
    }
    printf("%s\n",max_name);
    return 0;
}
