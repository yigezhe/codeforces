/*interface*/
//可能不是按先来的顺序，而是按字母排序！
#include<stdio.h>
#define N 1000
#define INF 10000
#include<string.h>
/*interface implementation*/
char player[N][32+1];
int points[N];
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
    int max_points=-INF;

    for(i=0; i<n; i++) {
        char name[32+1];
        int score;
        scanf("%s%d",name,&score);
        int who=find(name);
        if(who==(-1)) {
            if(score>max_points) {
                max_points=score;
                strcpy(max_name,name);
            }
            add(name,score);
        } else {
            if(points[who]+score>max_points) {
                max_points=points[who]+score;
                strcpy(max_name,player[who]);
            }
            points[who]+=score;
        }
    }
    printf("%s\n",max_name);
    return 0;
}
