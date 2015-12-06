//题目越来越有趣，越来越有挑战性，继续攻克！
//可以把没有草莓的行标记为可以吃的行，然后数一数可以吃的行有多少个块！
//poj上的习题更专业，不适合我现在的能力。
//而且codeforces上的题很有想象力，我比较喜欢！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 11
int main() {
    int r,c;
    scanf("%d%d",&r,&c);
    int i,j;
    char cake[N][N];
    int eat[N][N];
    getchar();//去掉换行符\n
    for(i=0; i<r; i++) {
        for(j=0; j<c; j++) {
            scanf("%c",&cake[i][j]);
            //printf("%c",cake[i][j]);
            eat[i][j]=0;
        }
        getchar();//去掉换行符\n
        //printf("\n");
    }
    for(i=0; i<r; i++) {
        int find=0;
        for(j=0; j<c; j++) {
            if(cake[i][j]=='S') {
                find=1;
                break;
            }
        }
        //这一行没有发现草莓，则这一行是可以吃的！
        if(!find) {
            for(j=0; j<c; j++) {
                eat[i][j]=1;
            }
        }
    }
    for(i=0; i<c; i++) {
        int find=0;
        for(j=0; j<r; j++) {
            if(cake[j][i]=='S') {
                find=1;
                break;
            }
        }
        //这一列没有发现草莓，则这一列是可以吃的！
        if(!find) {
            for(j=0; j<r; j++) {
                eat[j][i]=1;
            }
        }
    }
    int counter=0;
    for(i=0; i<r; i++) {
        for(j=0; j<c; j++) {
            if(eat[i][j]==1) {
                counter++;
            }
        }
    }
    printf("%d\n",counter);
    return 0;
}
