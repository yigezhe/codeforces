#include<stdio.h>
#include<stdlib.h>
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    //printf("n=%d,m=%d\n",n,m);
    int *a=malloc(n*sizeof(int));
    if(a==NULL) {
        printf("a can't get memory!\n");
    }
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    /*
    for(i=0; i<n; i++) {
        printf(" %d",a[i]);
    }
    printf("\n");
    */

    int *child=malloc(n*sizeof(int));
    if(child==NULL) {
        printf("child don't get memory!\n");
    }
    int *is_leaf=malloc(n*sizeof(int));
    if(is_leaf==NULL) {
        printf("is_leaf don't get memory!\n");
    }
    for(i=0; i<n; i++) {
        child[i]=i;
        is_leaf[i]=1;
    }
    for(i=0; i<n-1; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        x--; y--;
	printf("%d to %d\n",x,y);
        child[y]=x;
        is_leaf[x]=1;
        is_leaf[y]=0;
        int j;
        for(j=0; j<n; j++) {
            printf("%d-%d ",j,child[j]);
        }
        printf("\n");
        for(j=0; j<n; j++) {
            printf("%d-%d ",j,is_leaf[j]);
        }
        printf("\n\n");
    }
    int ans=0;
    for(i=0; i<n; i++) {
        if(is_leaf[i]==1) {
            printf("i = %d\n",i);
            int count=0;
            int max=0;
            int leaf=i;
            while(1) {
                if(child[leaf]==leaf) {
                    //at root
                    if(a[leaf]==1) {
                        count++;
                    }
                    if(count>max) max=count;
                    break;
                } else {
                    if(a[leaf]==1) {
                        count++;
                    } else {
                        if(count>max) max=count;
                        count=0;
                    }
                    leaf=child[leaf];
                }
            }
            
                printf("count = %d\n",count);
           
                printf("max = %d\n",count);
            //if(count<=m) ans++;
            if(max<=m) ans++;
        }
    }
    printf("%d\n",ans);
    free(child);
    free(a);
    free(is_leaf);
    return 0;
}
