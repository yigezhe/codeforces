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
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    for(i=0; i<n; i+=2) {
        //printf("i=%d\n",i);
        while(1) {
            if(a[i]>0) {
                printf("P");
                a[i]--;
            }
            if(!(a[i]==0 && a[i+1]==0 && i+2>=n)) {
            printf("R");
	    }
            if(a[i+1]>0) {
                printf("P");
                a[i+1]--;
            }
            if(a[i]==0 && a[i+1]==0) {
                if(i+2<n) printf("R");
                break;
            } else {
                printf("L");
            }
        }
    }
    if(n%2==1) {
        i=n-1;
        printf("R");
        while(1) {
            if(a[i]==0 && a[i-1]==0) break;
            if(a[i]>0) {
                printf("P");
                a[i]--;
            }
            if(a[i]>0) {
                printf("L");
                printf("R");
            } else {
                break;
            }
        }

    }
    printf("\n");
    return 0;
}
