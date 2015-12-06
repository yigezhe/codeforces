//想法一，两个方向上的距离，取最小值就可以！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 101
int main() {
    int n;
    scanf("%d",&n);
    int d[N];
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&d[i]);
    }
    int s,t;
    scanf("%d%d",&s,&t);
    if(s==t) {
        printf("0\n");
    } else {
        int small,large;
        if(s>t) {
            small=t;
            large=s;
        } else {
            small=s;
            large=t;
        }
	//减减是为了从零开始，输入数据是从1开始的！
	small--;
	large--;
        int distance1=0;
        for(i=small; i<large; i++) {
            distance1+=d[i];
        }
        int distance2=0;
        for(i=large;i<n;i++) {
            distance2+=d[i];
        }
        for(i=0;i<small;i++) {
            distance2+=d[i];
        }
	if(distance2>distance1) {
		printf("%d\n",distance1);
	}else {
		printf("%d\n",distance2);
	}
    }
    return 0;
}
