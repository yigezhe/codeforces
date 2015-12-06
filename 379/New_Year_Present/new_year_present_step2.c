//最好的礼物是钱，不同人有不同的最好！
//不错这是一个初级的给机器人设计算法程序的例子！
//至少有一个钱包有钱！
//策略一，一层一层处理！
//300*300=90000,时间够！
//策略左右来回处理！
/*interface*/
#include<stdio.h>
#define N 300+1
/*interface implementation*/
/*client*/
int main() {
    //先实现想法一
    int n;
    scanf("%d",&n);
    int a[N];
    int i;
    int max=0;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
        if(a[i]>max) max=a[i];
    }
    int j;
    //还不能重复放！
    //第二个想法直接可以不重复放！
    if(a[0]>0) {
        printf("P");
    }
    if(0<n)printf("R");

    for(i=0; i<max/2; i++) {
        j=1;
        while(j<n) {
            if(a[j]>0) {
                printf("P");
                a[j]--;
            }
            j++;
            if(j<n)printf("R");
        }
        j=n-2;
        while(j>=0) {
            if(a[j]>0) {
                printf("P");
                a[j]--;
            }
            j--;
            if(j>=0)printf("L");
        }
    }
    if(max%2==1) {
        j=0;
        while(j<n) {
            if(a[j]>0) {
                printf("P");
                a[j]--;
            }
            j++;
            if(j<n)printf("R");
        }
    }
    printf("\n");
    return 0;
}
