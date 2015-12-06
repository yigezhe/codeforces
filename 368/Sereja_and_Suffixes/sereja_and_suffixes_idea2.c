/*interface*/
#include<stdio.h>
#define N 100001
/*interface implementation*/
/*client*/
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int diff[N+1];
    int dp[N+1];
    int a[N+1];
    int i;
    for(i=0; i<=N; i++) {
        diff[i]=0;
    }
    //我觉得还是从后往前找！
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    dp[n]=0;
    for(i=n-1; i>=0; i--) {
        if(diff[a[i]]==0) {
            dp[i]=dp[i+1]+1;
        } else {
            dp[i]=dp[i+1];
        }
        diff[a[i]]++;
    }
    /*
    for(i=0; i<=N; i++) {
        if(diff[i]>0) {
            printf("%d--%d\n",i,diff[i]);
        }
    }
    for(i=0; i<=n; i++) {
	    printf("%d--%d\n",i,dp[i]);
    }
    */
    for(i=0; i<m; i++) {
        int l;
        scanf("%d",&l);
        printf("%d\n",dp[l-1]);
    }
    return 0;
}
