//想法二是用bfs来处理！
#include<stdio.h>
#include<stdlib.h>
struct state {
    int point;
    int cats;
    int max;
};

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
    int *x=malloc((n-1)*sizeof(int));
    if(x==NULL) printf("x don't get memory\n");
    int *y=malloc((n-1)*sizeof(int));
    if(y==NULL) printf("y don't get memory\n");
    for(i=0; i<n-1; i++) {
        scanf("%d%d",&x[i],&y[i]);
    }

    struct state *queue=malloc(n*sizeof(struct state));
    if(queue==NULL) printf("queue don't get memory\n");
    int start=0;
    int end=0;
    queue[0].point=0;
    if(a[0]==1) queue[0].cat=1;
    else queue[0].cat=0;
    queue[0].max=queue[0].cat;
    end++;
    //可以实现搜索，但是却不能达到最后的目标！
    while(start<end) {
        struct state cur;
        cur.point=queue[start].point;
        cur.cat=queue[start].cat;
        cur.max=queue[start].max;
        start++;
        for(i=0; i<n-1; i++) {
            if(x[i]==cur.point) {
                queue[end].point=y[i];
                if(a[y[i]]==1) {
                    queue[end].cat=cur.cat+1;
                    if(cur.cat+1>cur.max) {
                        queue[end].max=cur.cat+1;
                    } else {
                        queue[end].max=cur.max;
                    }
                } else {
                    queue[end].max=cur.max;
                    queue[end].cat=0;
                }
                end++;
            }
        }
    }



    x--;
    y--;
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
    printf("%d\n",ans);
    free(child);
    free(a);
    free(is_leaf);
    return 0;
}
