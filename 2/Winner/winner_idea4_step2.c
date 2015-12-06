/*interface*/
//可能不是按先来的顺序，而是按字母排序！
#include<stdio.h>
#define N 1000
#define INF 10000
#include<string.h>
/*interface implementation*/
char player[N][32+1];
int points[N];
int history_points[N];
int np;
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

    char final_max_name[32+1];
    int final_max_points=-INF;
    int final_max_points_i=0;


    for(i=0; i<n; i++) {
        char name[32+1];
        int score;
        scanf("%s%d",name,&score);
        int who=find(name);
        if(who==(-1)) {
            strcpy(player[np],name);
            points[np]=score;
            np++;
        } else {
            points[who]+=score;
        }
        char current_max_name[32+1];
        int current_max_points=-INF;
        int current_max_points_i=0;
        int j;

        for(j=0; j<np; j++) {
            if(points[j]>history_points[j]) {
                history_points[j]=points[j];
            }
            //printf(" %s:%d",player[j],points[j]);
            if(points[j]>current_max_points) {
                current_max_points=points[j];
                current_max_points_i=j;
                strcpy(current_max_name,player[j]);
            }
        }
        //printf("\n");

        if(current_max_points>final_max_points) {
            final_max_points=current_max_points;
            final_max_points_i=current_max_points_i;
            strcpy(final_max_name,current_max_name);
        }
        if(points[final_max_points_i]!=final_max_points) {
            final_max_points=current_max_points;
            final_max_points_i=current_max_points_i;
            strcpy(final_max_name,current_max_name);
        }

    }

    int j;
    for(j=0; j<np; j++) {
        if(points[j]==final_max_points) {
            if(history_points[j]>history_points[final_max_points_i]) {
                final_max_points_i=j;
            }
        }
    }

        //printf("%s\n",final_max_name);
        printf("%s\n",player[final_max_points_i]);
        return 0;
    }
