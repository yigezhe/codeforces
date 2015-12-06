//candidates议员，代表！
//选举n个议员，有m个城市！
//先选城市内的，再选城市间的！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 100+1
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int a[N][N];
    int i,j;
    for(i=0; i<m; i++) {
        for(j=0; j<n; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    //the first stage of elections
    int city_winner[N];
    for(i=0; i<m; i++) {
        int max=-1;
        for(j=0; j<n; j++) {
            if(a[i][j]>max) {
                max=a[i][j];
                city_winner[i]=j;
            }
        }
    }
    /*
    for(i=0; i<m; i++) {
        printf("city %d winner is %d\n",i,city_winner[i]);
    }
    */
    //the second stage of elections
    int winner_city[N];
    for(i=0; i<n; i++) {
        winner_city[i]=0;
    }
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            if(city_winner[j]==i) {
                winner_city[i]++;
            }
        }
    }
    /*
    for(i=0; i<n; i++) {
        printf("candidate %d wins %d city\n",i,winner_city[i]);
    }
    */

    int max=-1;
    int winner=-1;
    for(i=0; i<n; i++) {
        if(winner_city[i]>max) {
            max=winner_city[i];
            winner=i;
        }
    }
    printf("%d\n",winner+1);

    return 0;
}
