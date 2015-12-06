//submit ok!
//greedy,很有野心，欲望很强，想得到所有，想得到尽可能多的！
//这个程序在求解最多相同时间！
//我的想法是，用结构表示时间！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 60
int main() {
    int same_count[N][N];
    int i,j;
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            same_count[i][j]=0;
        }
    }
    int n;
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        int hour;
        int minute;
        scanf("%d%d",&hour,&minute);
        same_count[hour][minute]+=1;
    }
    int max=0;
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            if(same_count[i][j]>max) max=same_count[i][j];
        }
    }
    printf("%d\n",max);
    return 0;
}
