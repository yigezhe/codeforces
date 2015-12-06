/*interface*/
#include<stdio.h>
#include<string.h>
/*interface implementation*/
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    int score[2];
    score[0]=0;
    score[1]=0;
    char team[2][10+1];
    int nteam=0;
    int i;
    for(i=0; i<n; i++) {
        char name[10+1];
        scanf("%s",name);
        int j;
        int find=0;
        for(j=0; j<nteam; j++) {
            if(strcmp(name,team[j])==0) {
                find=1;
                score[j]++;
                break;
            }
        }
        if(!find) {
            strcpy(team[nteam],name);
            nteam++;
        }
    }
    if(nteam==1) printf("%s\n",team[0]);
    else if(nteam==2) {
        if(score[0]>score[1]) {
            printf("%s\n",team[0]);
        } else {
            printf("%s\n",team[1]);
        }
    }
    return 0;
}
