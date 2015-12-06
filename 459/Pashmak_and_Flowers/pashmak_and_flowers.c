#include<stdio.h>
#define MAX 1000000000+1
int main() {
    int max=0;
    int min=MAX;
    long long count_max=0;
    long long count_min=0;
    int n;
    scanf("%d",&n);
    int i;
    for(i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
        if(a>max) {
            max=a;
            count_max=1;
        } else if(a==max) {
            count_max++;
        }
        if(a<min) {
            min=a;
            count_min=1;
        } else if(a==min) {
            count_min++;
        }
    }
    if(max==min) {
        printf("%d ",max-min);
        //count_max==count_min
        if(count_max%2==0)  {
            printf("%lld\n",count_max/2*count_min/2);
        } else {

            printf("%lld\n",count_max/2+1*count_min/2);
        }
    } else {
        printf("%d %lld\n",max-min,count_max*count_min);
    }

    return 0;
}
