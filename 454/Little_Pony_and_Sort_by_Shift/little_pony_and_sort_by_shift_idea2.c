/*interface*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct interval {
    int start;
    int end;
};

/*interface implementation*/
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    //printf("n=%d\n",n);
    int *a=malloc(n*sizeof(int));
    if(a==NULL) {
        printf("n 没有分配到内存\n");
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

    struct interval *record=malloc(n*sizeof(struct interval));
    if(record==NULL) {
        printf("n 没有分配到内存\n");
    }
    int nd=0;
    i=0;
    while(i<n) {
        int start=i;
        while(i<n-1 && a[i]<=a[i+1]) {
            i++;
        }
        int end=i;
	//printf("start=%d,end=%d\n",start,end);
        record[nd].start=start;
        record[nd].end=end;
        nd++;
	if(nd>2) break;//插入这一句话减少不必要的工作！
	i++;
    }
    int shift=0;
    if(nd==1) {
        shift=0;
    } else if(nd==2) {
        if(a[record[1].end]<=a[record[0].start]) {
            shift=record[1].end-record[1].start+1;
        } else {
            shift=-1;
        }
    } else {
        //能分成两段的才可以通过shift排序成功！
        shift=-1;
    }
    printf("%d\n",shift);
    free(a);
    a=NULL;
    free(record);
    record=NULL;
    return 0;
}
