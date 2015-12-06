//这是一个简化版的皇后问题！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 1000
int main() {
    int n;
    scanf("%d",&n);
    char chessboard[N][N];
    int i,j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            chessboard[i][j]='O';
        }
    }
    int counter=0;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(chessboard[i][j]=='O') {
                chessboard[i][j]='C';
                counter++;
                if(i+1<n)chessboard[i+1][j]='.';
                if(i-1>=0)chessboard[i-1][j]='.';
                if(j+1<n)chessboard[i][j+1]='.';
                if(j-1>=0)chessboard[i][j-1]='.';
            }
        }
    }
    printf("%d\n",counter);
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%c",chessboard[i][j]);
        }
        printf("\n");
    }
    return 0;
}
