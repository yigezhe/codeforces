/*interface*/
//可能不是按先来的顺序，而是按字母排序！
//看来是历史上第一次得到或者超过那个最终的最高分的，并且最终还是那个最高分的人，才是最后的胜利者！！
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


    char name[N][32+1];
    int score[N];

    for(i=0; i<n; i++) {
        scanf("%s%d",name[i],&score[i]);
        int who=find(name[i]);
        if(who==(-1)) {
            strcpy(player[np],name[i]);
            points[np]=score[i];
            np++;
        } else {
            points[who]+=score[i];
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
        final_max_points=current_max_points;
        final_max_points_i=current_max_points_i;
        strcpy(final_max_name,current_max_name);
    }
    //先找到最高分！
    int new_points[N];
    int new_np=0;
    char new_player[N][32+1];
    int find=final_max_points_i;
    int is_ok=1;
    for(i=0; i<n && is_ok; i++) {
        int who=-1;
        int j;
        for(j=0; j<new_np; j++) {
            if(strcmp(new_player[j],name[i])==0) {
                who=j;
                break;
            }
        }
        if(who==(-1)) {
            strcpy(new_player[new_np],name[i]);
            new_points[new_np]=score[i];
            new_np++;
        } else {
		//printf("who  = %d\n",who);
            new_points[who]+=score[i];
        }
	/*
	printf("%s %d\n",name[i],score[i]);
        for(j=0; j<new_np; j++) {
		printf("%d: %s %d\n",j,new_player[j],new_points[j]);
	}
	*/
        for(j=0; j<np && is_ok; j++) {
            if(points[j]==final_max_points && new_points[j]>=final_max_points) {
                find=j;
                is_ok=0;
		break;
            }
        }
    }


    //printf("%s\n",final_max_name);
    //printf("%s\n",player[final_max_points_i]);
    printf("%s\n",player[find]);
    return 0;
}
