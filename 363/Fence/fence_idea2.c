//越高越不好操作，所以要找低的，这是提出这个问题，
//作者指出的原因！
//inf=10^9
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
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&h[i]);
    }

    int sum=0;
    for(i=0;i<k;i++) {
	    sum+=h[i];
    }
    int min=sum;
    int min_j=0;

    //0123456
    //n=7
    //k=3
    //012
    //sum=h[3];
    for(i=1;i<=n-k;i++) {
	    sum+=h[k+i-1];
	    sum-=h[i-1];
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
