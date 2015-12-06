#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main() {
    int n,s;
    scanf("%d%d",&n,&s);
    int *a=malloc(n*sizeof(int));
    if(a==NULL) {
        printf("n 没有分配到内存\n");
    }
    int i;
    //int min=1000+1;
    int sum=0;
    int max=0;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
	//if(a[i]<min) min=a[i];
	if(a[i]>max) max=a[i];
	sum+=a[i];
    }
    //if(sum-min<=s) printf("YES\n");
    if(sum-max<=s) printf("YES\n");
    else printf("NO\n");

    free(a);
    return 0;
}
