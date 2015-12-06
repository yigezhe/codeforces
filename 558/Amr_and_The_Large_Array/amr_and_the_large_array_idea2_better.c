/*interface*/
#include<stdio.h>
#include<stdlib.h>
#define N 100000
#define M 1000000+1
/*interface implementation*/
/*client*/
int main() {
    int n;
    int a[N];
    int *count=malloc(M*sizeof(int));
    if(count==NULL) {
        printf("没有分配到内存\n");
    }
    scanf("%d",&n);
    printf("n=%d\n",n);
    int i;
    for(i=0; i<M; i++) {
        count[i]=0;
    }
    printf("here\n");
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
        count[a[i]]++;
    }


    //找出最大值次数！
    int max=count[1];
    for(i=2; i<M; i++) {
        if(count[i]>max) {
            max=count[i];
        }
    }

    //找到最大次数的个数！
    int total=0;
    for(i=1; i<M; i++) {
        if(count[i]==max) {
            total++;
        }
    }

    int *head=malloc(total*sizeof(int));
    int *tail=malloc(total*sizeof(int));
    int *element=malloc(total*sizeof(int));
    if(head==NULL) { printf("没有分配到内存\n"); }
    if(element==NULL) { printf("没有分配到内存\n"); }
    if(tail==NULL) {
        printf("没有分配到内存\n");
    }
    int *max_member=malloc(total*sizeof(int));
    if(max_member==NULL) {
        printf("没有分配到内存\n");
    }
    int mm=0;

    //找到最大次数的元素！
    for(i=1; i<M; i++) {
        if(count[i]==max) {
            max_member[mm]=i;
            mm++;
        }
    }

    int total=0;
    int see[N];
    mm=0;
    for(i=0; i<n; i++) {
        see[i]=0;
    }
    for(i=0; i<n; i++) {
        if(!see[i] && count[a[i]]==max) {
            head[mm]=i;
	    element[mm]=a[i];
            see[i]=1;
            count[a[i]]=mm;//统计完以后，count已经没有用了！
        } else if(see[i]) {
            tail[count[a[i]]]=i;
        }
    }


    int min_head=0;
    int min_tail=n-1;
    for(i=0; i<total; i++) {
        if(tail[i]-head[i]<min_tail-min_tail) {
            min_tail=tail[i];
            min_head=head[i];
        }
    }
    printf("%d %d\n",min_head+1,min_tail+1);
    free(head);
    free(tail);
    free(count);

    return 0;
}
