/*interface*/
#include<stdio.h>
#define N 50
/*interface implementation*/
/*client*/
int main() {
    int vertical[N+1];
    int horizontal[N+1];
    int i;
    for(i=0; i<=N; i++) {
        vertical[i]=0;
        horizontal[i]=0;
    }
    int n;
    scanf("%d",&n);
    for(i=1; i<=n*n; i++) {
	    int h,v;
        scanf("%d%d",&h,&v);
        if(vertical[v]==0 && horizontal[h]==0) {
            printf(" %d",i);
            vertical[v]=1;
            horizontal[h]=1;
        }
    }
    printf("\n");
    return 0;
}
