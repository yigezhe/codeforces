/*interface*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
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
    int shift=0;
    int find=0;
    for(i=0; i<n-1; i++) {
        //先看是不是排序好了，在平移！
        int is_ok=1;
        int j;
        for(j=0; j<n-1; j++) {
            if(a[j]>a[j+1]) {
                //printf("%d>%d\n",a[j],a[j+1]);
                is_ok=0;
                break;
            }
        }
        if(is_ok) {
            find=1;
            break;
        }

        int tmp=a[0];
        for(j=0; j<n-1; j++) {
            a[j]=a[j+1];
        }
        a[n-1]=tmp;
        shift++;
    }
    //多一次判断！
    int is_ok=1;
    int j;
    for(j=0; j<n-1; j++) {
        if(a[j]>a[j+1]) {
            //printf("%d>%d\n",a[j],a[j+1]);
            is_ok=0;
            break;
        }
    }
    if(is_ok) {
        find=1;
    }

    if(find) {
        printf("%d\n",shift);
    } else {
        printf("-1\n");
    }

    free(a);
    return 0;
}
