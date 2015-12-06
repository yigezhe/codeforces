//vanya是俄国流行的名字！
//从下往上，1，2，。。。，100
//从左往右，1，2，。。。，100
//21 22
//11 12
//n时长方形的多少！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 100
void print(int table[][100],int n) {
    int i,j;
    for(i=N-n; i<N; i++) {
        for(j=0; j<n; j++) {
            printf(" %d",table[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int table[N][N];
    int i,j,k;
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            table[i][j]=0;
        }
    }
    int n;
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        //int x1,y1,x2,y2;
        //x1 and y1 are the number of the column and row of the lower left cell and x2 and y2 are the number of the column and row of the upper right cell of a rectangle.
        //x1=column left;
        //y1=row lower;
        //x2=column right;
        //y2=row upper;
        int left,lower,right,upper;
        scanf("%d%d%d%d",&left,&lower,&right,&upper);
        //从零开始计数，例子中是从1开始的！
        left--,right--;
        //N-1 ~ 1
        for(j=N-lower; j>=N-upper; j--) {
            for(k=left; k<=right; k++) {
                table[j][k]++;
            }
        }
    }
    //print(table,5);
    int sum=0;
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            sum+=table[i][j];
        }
    }
    printf("%d\n",sum);
    return 0;
}
