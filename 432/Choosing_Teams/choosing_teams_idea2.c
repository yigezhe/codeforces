//submit ok!
//有思路了，先从小到大排序，之后取前三个，然后循环中统计，什么时候这个队
//的全部成员参加比赛的次数超过三个，就停止！
/*interface*/
#include<stdio.h>
void sort(int *,int);
void insertion_sort(int *,int);
void print(int *,int);
/*interface implementation*/
void sort(int *data,int length) {
    insertion_sort(data,length);
}
void insertion_sort(int *data,int length) {
    //感觉作者写的有点复杂了！
    int i;
    for (i = 0; i < length; i++) {
        int j = i;
        //在i左边的比i大的元素
        //i=1,不会进入while循环！
        while (j > 0 && data[i] < data[j - 1])
            j--;
        int tmp = data[i];
        int k;
        //把比i大的元素都向右统一移动一位！
        for (k = i; k > j; k--)
            data[k] = data[k - 1];
        //把i放在比他大的最左边的那个元素的位置上！
        data[j] = tmp;
    }
}
void print(int *data,int length) {
    int i;
    for(i=0; i<length; i++) {
        printf(" %d",data[i]);
    }
    printf("\n");
}
/*client*/
#include<stdio.h>
#define N 2000
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    int i;
    int y[N];
    for(i=0; i<n; i++) {
        scanf("%d",&y[i]);
    }

    //print(y,n);
    sort(y,n);
    //print(y,n);

    i=0;
    int team=0;
    //这里需要求解的是队
    //让所有队员至少参加k次？
    while(1) {
        //printf("i=%d\n",i);
        if(i+2<n) {
            //in7说明223也是一个组合，刚组好队就已经达到每一个都至少参加过两次的要求！
            //遇到次数等于k的情况要做特别处理！
            //
            if( y[i]+k<=5 &&  y[i+1]<=5 && y[i+2]+k<=5) {
                team++;
                i+=3;
            } else {
                break;
            }
        }
	else {
		break;
	}
    }
    printf("%d\n",team);

    return 0;
}
