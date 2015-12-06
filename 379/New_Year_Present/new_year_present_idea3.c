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
    //想法三，放之前检查是不是走过来的！
    int move=0;
        i=0;
	int direction=0;
    while(1) {
	    //每走一步就检测一下，量有点大！
        int is_finish=1;
        for(i=0; i<n; i++) {
            if(a[i]>0) {
                is_finish=0;
                break;
            }
        }
        if(is_finish) break;

if(i<n && a[i]>0 && move==0) {
            printf("P");
            a[i]--;
            if(i<n) {
                i++;
                printf("R");
            } else {
                printf("L");
                i--;
            }
        }

	if(direction==0) {
		i++;
	}else {
		i--;
	}
        if(i==n) {
		direction=1;
	} else if(i==0) {
		direction=0;
	}
			
    }
    printf("\n");
    return 0;
}
