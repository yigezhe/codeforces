/*interface*/
#include<stdio.h>
#include<stdlib.h>
#define N 100000
#define M 100000+1
/*interface implementation*/
/*client*/
int main() {
    int n;
    int a[N];
    struct data{
	    int count;
	    int head;
	    int tail;
    };
    struct data *counter=malloc(M*sizeof(struct data));
    if(counter==NULL) {
        printf("没有分配到内存\n");
    }
    scanf("%d",&n);
    printf("n=%d\n",n);
    int i;
    for(i=0; i<M; i++) {
        counter[i].count=0;
        counter[i].head=0;
        counter[i].tail=0;
    }
    printf("here\n");
    int max;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
        if(counter[a[i]].count==0) {
            counter[a[i]].head=i;
        }
        counter[a[i]].count++;
        counter[a[i]].tail=i;
    }
    max=counter[1].count;
    for(i=2; i<M; i++) {
        if(counter[i].count>max) {
            max=counter[i].count;
        }
    }
    int min_head=0;
    int min_tail=n-1;
    for(i=1; i<M; i++) {
        if(counter[i].count==max) {
            if(counter[i].tail-counter[i].head<min_tail-min_tail) {
                min_tail=counter[i].tail;
                min_head=counter[i].head;
            }
        }
    }
    printf("%d %d\n",min_head+1,min_tail+1);
    free(counter);

    return 0;
}
