//我用两种方式实现，一种是不用数组，一种是用数组
//用数组的实现方式比较快！
/*interface*/
#include<stdio.h>
#define N 100000+1
/*interface implementation*/
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    int a[N];
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

    int counter=0;
    int max=0;
    for(i=0; i<n-1; i++) {
        if(a[i]<=a[i+1]) {
            //printf("%d<=%d\n",a[i],a[i+1]);
            counter++;
        } else {
            if(counter>max) max=counter;
            counter=0;
        }
    }
    if(counter>max) max=counter;
    printf("%d\n",max+1);
    return 0;
}
