//我也感觉这是是超时的！
//整数的长度是m，整个整数各个数字之和是s
//想法一，用一个bfs来求解最小整数。
//用另一个bfs求解最大整数！
/*interface*/
#include<stdio.h>
#define M 100+1
int m,s;
int digits[M];

void print(int *a) {
    int i=0;
    while(i<m) {
        printf("%d",a[i]);
        i++;
    }
}
void min_search(int length,int sum) {
    //printf("min_search(%d,%d)\n",length,sum);
    if(length==m) {
        if(sum==s && digits[0]!=0) {
            print(digits);
        } else {
            printf("%d",-1);
        }
        return;
    } else {
        int i;
        for(i=0; i<10; i++) {
            digits[length]=i;
            if(sum+i<=s) min_search(length+1,sum+i);
            //digits[length]=0;
        }
    }
}
/*
void max_search(int length,int sum) {
    if(length==m) {
        if(sum==s && digits[0]!=0) {
            print(digits);
            return;
        } else {
            printf("%d",-1);
            return;
        }
    }
    int i;
    for(i=9; i>=0; i++) {
        if(sum+i<=s) {
            digits[length]=i;
            max_search(length+1,sum+i);
            digits[length]=0;
        }
    }
}
*/

int main() {
    int i;
    for(i=0; i<M; i++) {
        digits[i]=0;
    }

    //一个整数有100位，这不能在long long中表达！
    scanf("%d%d",&m,&s);
    //printf("%d位，数字和为%d\n",m,s);
    min_search(0,0);
    printf(" ");
    //max_search(0,0);
    printf("\n");
    return 0;
}
