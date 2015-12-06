
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 100
int main() {
    int n;
    scanf("%d",&n);
    int b[N][N];
    int col,row;
    int start=n*n;
    for(col=0; col<n; col+=2) {
        for(row=0; row<n; row++) {
            b[row][col]=start;
            start--;
        }
    }
    start=1;
    for(col=1; col<n; col+=2) {
        for(row=0; row<n; row++) {
            b[row][col]=start;
            start++;
        }
    }

    for(row=0; row<n; row++) {
	    //看来这种输出形式是可以被接受的，我没有必要去掉最后一个多余空格！
        for(col=0; col<n; col++) {
            printf("%d ",b[row][col]);
        }
            printf("\n");
    }
    return 0;
}
