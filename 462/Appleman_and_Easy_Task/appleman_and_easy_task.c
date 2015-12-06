//
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 101
int main() {
    int n;
    scanf("%d",&n);
    char checkerboard[N][N];
    int xo[N][N];
    int i,j;
    getchar();
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            scanf("%c",&checkerboard[i][j]);
            xo[i][j]=0;
        }
        getchar();
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
		//每一个格是否都拥有偶数个o
            if(i-1>=0 && checkerboard[i-1][j]=='o') xo[i][j]++;
            if(i+1<n && checkerboard[i+1][j]=='o') xo[i][j]++;
            if(j-1>=0 && checkerboard[i][j-1]=='o') xo[i][j]++;
            if(j+1<n && checkerboard[i][j+1]=='o') xo[i][j]++;
            if(xo[i][j]%2!=0) {
                printf("NO\n");
                return 0;
            }
        }
    }

    printf("YES\n");
    return 0;
}
