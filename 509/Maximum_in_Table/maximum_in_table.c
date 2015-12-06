//n很小只有10，允许我直接模拟产生最大值。
//其实可以找到一个公式来直接计算最大值！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 10
int main() {
    int n;
    scanf("%d",&n);
    int a[N][N];
    int i,j;
    for(i=0; i<n; i++) {
        a[i][0]=1;
        a[0][i]=1;
    }
    for(i=1; i<n; i++) {
        for(j=1; j<n; j++) {
            a[i][j]=a[i-1][j]+a[i][j-1];
        }
    }
    /*
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            printf("%4d",a[i][j]);
        }
	printf("\n");
    }
    */
    printf("%d\n",a[n-1][n-1]);


    return 0;
}
