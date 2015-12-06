/*interface*/
//可能不是按先来的顺序，而是按字母排序！
#include<stdio.h>
#define N 1000
#define INF 10000
#include<string.h>
/*interface implementation*/
char player[N][32+1];
int all_score[N][N];
int nscore[N];
int points[N];
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

    for(i=0; i<n; i++) {
        nscore[i]=0;
    }
    for(i=0; i<n; i++) {
        char name[32+1];
        int score;
        scanf("%s%d",name,&score);
        int who=find(name);
        if(who==(-1)) {
            strcpy(player[np],name);
            points[np]=score;
            all_score[np][0]=score;
            nscore[np]++;
            np++;
        } else {
            points[who]+=score;
            all_score[who][nscore[who]]=points[who];
            nscore[who]++;
        }
    }
    char max_name[32+1];
    int max_points=-INF;

    for(i=0; i<np; i++) {
        if(points[i]>max_points) {
            max_points=points[i];
            strcpy(max_name,player[i]);
        }
    }
    /*
    for(i=0; i<np; i++) {
        printf("%d: %s: ",i,player[i]);
        int j;
        for(j=0; j<nscore[i]; j++) {
            printf(" %d",all_score[i][j]);
        }
        printf("\n");
    }
    */
    int max_times=0;
    int which=0;
    for(i=0; i<np; i++) {
        int j;
	int times=0;
        for(j=nscore[i];j>=0;j++) {
            if(all_score[i][j]!=max_points) {
		    break;
	    }else {
		    times++;
	    }
        }
	if(nscore[i]-times<nscore[which]-max_times) {
		max_times=times;
		which=i;
	}
    }

    //记录每一选手的分数变化！
    //printf("%s\n",max_name);
    printf("%s\n",player[which]);
    return 0;
}
