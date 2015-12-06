//inf=10^9
#define INF 1000000000
/*interface*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*interface implementation*/
/*client*/
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    int *h=malloc(n*sizeof(int));
    if(h==NULL) {
        printf("n 没有分配到内存\n");
    }
    int i,j;
    for(i=0; i<n; i++) {
        scanf("%d",&h[i]);
    }
    int min=INF;
    int min_j=0;
    //012345
    //n=6,k=3;
    for(i=0;i<=n-k;i++) {
	    int sum=0;
	    for(j=i;j<i+k;j++) {
		    sum+=h[j];
	    }
	    if(sum<min) {
		    min=sum;
		    min_j=i;
	    }
    }
    //printf("%d\n",min);
    printf("%d\n",min_j+1);
    free(h);
    return 0;
}
