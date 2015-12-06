
/*interface*/
#include<stdio.h>
#define N 100
/*interface implementation*/
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    int a[N];
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    int m;
    scanf("%d",&m);
    for(i=0; i<m; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        x--,y--;
        //printf("%d line %d bird\n",x,y);
        if(x!=0) a[x-1]=a[x-1]+y;
        if(x!=n-1) a[x+1]=a[x+1]+a[x]-y-1;
        a[x]=0;
	/*
	int j;
        for(j=0; j<n; j++) {
            printf(" %d",a[j]);
        }
        printf("\n");
	*/
    }
    for(i=0; i<n; i++) {
        printf("%d\n",a[i]);
    }
    return 0;
}
