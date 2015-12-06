/*interface*/
#include<stdio.h>
#define N 100000
/*interface implementation*/
/*client*/
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int diff[N+1];
    int dp[N+1];
    int i;
    for(i=0; i<=N; i++) {
        diff[i]=0;
    }
    int total=0;
    for(i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
        if(diff[a]==0) {
            total++;
            dp[i+1]=dp[i]+1;
        } else {
            dp[i+1]=dp[i];
        }
        diff[a]++;
    }
    for(i=0; i<=N; i++) {
        if(diff[i]>0) {
            printf("%d--%d\n",i,diff[i]);
        }
    }
    for(i=0; i<=n; i++) {
	    printf("%d--%d\n",i,dp[i]);
    }
    printf("total is %d\n",total);

    for(i=0; i<m; i++) {
        int l;
        scanf("%d",&l);
        printf("%d\n",total-dp[l]+1);
    }
    return 0;
}
