/*interface*/
#include<stdio.h>
#define N 100000
/*interface implementation*/
/*client*/
int main() {
    int dp[N+1];
    int h[N+1];
    int n;
    scanf("%d",&n);
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&h[i]);
    }
    dp[n-1]=0;
    int max=h[n-1];
    for(i=n-2; i>=0; i--) {
        //printf("max=%d\n",max);
        if(h[i]>max) {
            dp[i]=0;
            max=h[i];
        } else {
            dp[i]=max-h[i]+1;
        }
    }
    for(i=0; i<n; i++) {
        printf(" %d",dp[i]);
    }
    printf("\n");
    return 0;
}
