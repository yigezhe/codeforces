//paragraph图景，段落！
//collides碰撞，相撞！
//没有相撞，还可以翻过去？
//就是统计没有翻车的车！
//没有翻车的车就是健康的！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 101
int main() {
    int n;
    scanf("%d",&n);
    int i,j;
    int collision[N][N];
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            scanf("%d",&collision[i][j]);
        }
    }
    int good[N];
    for(i=0; i<n; i++) {
        good[i]=0;
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(collision[i][j]==1) {
                good[i]++;
            } else if(collision[i][j]==2) {
                good[j]++;
            } else if(collision[i][j]==3) {
                good[i]++;
                good[j]++;
            }
        }
    }
    int counter=0;
    for(i=0; i<n; i++) {
        if(good[i]==0) counter++;
    }
    printf("%d\n",counter);
    for(i=0; i<n; i++) {
        if(good[i]==0) printf(" %d",i+1);
    }
    printf("\n");
    return 0;
}
