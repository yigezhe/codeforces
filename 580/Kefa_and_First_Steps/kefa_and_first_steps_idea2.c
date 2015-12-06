//我用两种方式实现，一种是不用数组，一种是用数组
//用数组的实现方式比较快！
/*interface*/
#include<stdio.h>
#define INF 1000000000+1
#define N 100000+1
/*interface implementation*/
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    int i;
    int before=INF;
    int counter=0;
    int max=0;
    for(i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
        //printf("%d %d\n",before,a);
        if(before<=a) {
            counter++;
        } else {
            //printf("current counter is %d\n",counter);
            if(counter>max) max=counter;
            counter=0;
        }
        before=a;
    }
    if(counter>max) max=counter;
    printf("%d\n",max+1);
    return 0;
}
