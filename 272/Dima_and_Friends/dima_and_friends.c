/*interface*/
#include<stdio.h>
#define M 100+2
#define N 5*M
/*interface implementation*/
/*client*/
int main() {
    int n;
    int clean[N][M];
    int i,j;
    for(i=1; i<N; i++) {
        for(j=1; j<M; j++) {
            if(i%j==1) clean[i][j]=1;
            else clean[i][j]=0;
        }
    }
    int other=0;
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        int finger;
        scanf("%d",&finger);
        other+=finger;
    }
    int counter=0;
    for(i=1; i<=5; i++) {
	    //其实可以更简单？
        if(clean[i+other][n+1]==0) counter++;
    }
    printf("%d\n",counter);
    return 0;
}
