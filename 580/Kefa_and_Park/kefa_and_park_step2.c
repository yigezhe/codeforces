//书中的数据没有按我希望的顺序给！
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
    int *counter=malloc(n*sizeof(int));
    if(counter==NULL) {
        printf("counter don't get memory!\n");
    }

    for(i=0; i<n; i++) {
        child[i]=i;
        counter[i]=0;
    }
    for(i=0; i<n-1; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        x--;
        y--;
	if(x!=y) {
        counter[x]++;
        counter[y]++;
	}
        //printf("%d to %d\n",x,y);
        child[y]=x;
            int j;
            for(j=0; j<n; j++) {
                printf("%d-%d ",j,child[j]);
            }
            printf("\n");
            for(j=0; j<n; j++) {
                printf("%d-%d ",j,counter[j]);
            }
            printf("\n\n");
    }
    int ans=0;
    //i=0肯定不是叶子，所以从1开始！
    for(i=1; i<n; i++) {
        //用counter[i]==1,来判断i点是不是叶子！
        if(counter[i]==1) {
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

                    //printf("count = %d\n",count);
                    printf("max = %d\n",count);
            //if(count<=m) ans++;
            if(max<=m) ans++;
        }
    }
    printf("%d\n",ans);
    free(child);
    free(a);
    free(counter);
    return 0;
}
