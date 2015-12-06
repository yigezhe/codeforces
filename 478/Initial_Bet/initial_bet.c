#include<stdio.h>
int main() {
    int n=5;
    int i;
    int sum=0;
    for(i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
        sum+=a;
    }
    //printf("sum=%d\n",sum);
    //初始要求是硬币数不是零！
    if(sum%5==0 && sum>0) {
        printf("%d\n",sum/5);
    } else {
        printf("%d\n",-1);
    }
    return 0;
}
