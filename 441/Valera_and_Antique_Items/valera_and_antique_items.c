//简单的统计！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#include<stdlib.h>
int main() {
    int n,v;
    scanf("%d%d",&n,&v);
    int *q=malloc(n*sizeof(int));
    if(q==NULL) {
        printf("我们没有分配到足够的内存\n");
        return 1;
    }

    int i,j;
		int counter=0;
    for(i=0; i<n; i++) {
        int k;
        scanf("%d",&k);
	int find=0;
        for(j=0; j<k; j++) {
            int money;
            scanf("%d",&money);
	    if(money<v)find++;
        }
	if(find>0) {
		q[counter]=i+1;
		counter++;
	}
    }
    printf("%d\n",counter);
    for(i=0; i<counter; i++) {
	    printf(" %d",q[i]);
    }
    printf("\n");

    return 0;
}
