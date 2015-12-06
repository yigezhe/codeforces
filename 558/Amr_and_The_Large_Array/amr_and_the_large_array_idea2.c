/*interface*/
#include<stdio.h>
#include<stdlib.h>
/*interface implementation*/
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    int *a=malloc(n*sizeof(int));
    if(a==NULL) {
        printf("a 没有分配到内存\n");
    }
    //printf("n=%d\n",n);
    int i;
    int max=0;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
        if(a[i]>max) max=a[i];
    }
    //printf("max = %d\n",max);
    int *count=malloc((max+1)*sizeof(int));
    int *head=malloc((max+1)*sizeof(int));
    int *tail=malloc((max+1)*sizeof(int));
    if(count==NULL) {
        printf("count 没有分配到内存\n");
    }
    if(head==NULL) {
        printf("head 没有分配到内存\n");
    }
    if(tail==NULL) {
        printf("tail 没有分配到内存\n");
    }
    for(i=0; i<=max; i++) {
        count[i]=0;
        head[i]=0;
        tail[i]=0;
    }
    for(i=0; i<n; i++) {
        if(count[a[i]]==0) {
            head[a[i]]=i;
        }
        count[a[i]]++;
        tail[a[i]]=i;
    }
    /*
    for(i=1; i<=max; i++) {
        printf("%d times %d\n",i,count[i]);
        printf("%d head %d\n",i,head[i]);
        printf("%d tail %d\n",i,tail[i]);
    }
    */
    int max_times=count[1];
    for(i=2; i<=max; i++) {
        if(count[i]>max_times) {
            max_times=count[i];
        }
    }
    //printf("max times is %d\n",max_times);
    int min_head=0;
    int min_tail=n-1;
    for(i=0; i<n; i++) {
        //printf("min head %d min tail %d\n",min_head,min_tail);
        if(count[a[i]]==max_times) {
            /*
            printf("%d %d count = %d\n",i,a[i],count[a[i]]);
            printf("head = %d tail = %d\n",head[a[i]],tail[a[i]]);
            */
            if((tail[a[i]]-head[a[i]])<(min_tail-min_head)) {
                min_tail=tail[a[i]];
                min_head=head[a[i]];
            }
        }
    }
    printf("%d %d\n",min_head+1,min_tail+1);
    free(head);
    free(a);
    free(tail);
    free(count);

    return 0;
}
