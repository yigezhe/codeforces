//我也感觉这是是超时的！
//整数的长度是m，整个整数各个数字之和是s
//想法一，用一个bfs来求解最小整数。
//用另一个bfs求解最大整数！
/*interface*/
#include<stdio.h>
#define M 100+1
int m,s;
int digits[M];
int digit_max[M];
int digit_min[M];
int digit_sum;
int compare(int *a,int *b) {
    int i;
    for(i=0; i<m; i++) {
        if(a[i]>b[i]) return 1;
        else if(a[i]<b[i]) return -1;
    }
    return 0;
}
void copy(int *a,int *b) {
    int i;
    for(i=0; i<m; i++) {
        b[i]=a[i];
    }
}
/*
void copy_minus_one(int *a) {
    int i;
    for(i=0; i<m-1; i++) {
        a[i]=0;
    }
    a[m-1]=-1;
}
*/
int min_change(int *a) {
    int i;
    for(i=0; i<m; i++) {
        if(a[i]!=10)return 1;
    }
    return 0;
}
int max_change(int *a) {
    int i;
    for(i=0; i<m; i++) {
        if(a[i]!=-1)return 1;
    }
    return 0;
}

void print_digit(int *a) {
    int i=0;
    while(a[i]==0 && i<m) {
        i++;
    }
    while(i<m) {
        printf("%d",a[i]);
        i++;
    }
}
void print(int *a) {
    int i=0;
    while(i<m) {
        printf("%d",a[i]);
        i++;
    }
    printf("|");
}
void search(int length) {
//print(digits);
//printf(" search(%d)\n",length);
    //不仅长度够，而且第一个不能是0
    if(length==m) {
        if( digit_sum==s && digits[0]!=0) {
            if(compare(digits,digit_max)>=0) {
                copy(digits,digit_max);
            }
//print(digit_max);
            if(compare(digits,digit_min)<=0) {
                copy(digits,digit_min);
            }
        }
//print(digit_min);
        return;
        //取消不必要的搜索！
    } else {
        int i;
        //if(length==0) i=1;
        //else i=0;
        for(i=0; i<10; i++) {
            digits[length]=i;
            digit_sum+=i;
            if(digit_sum<=s) search(length+1);
            //digits[length]=-1;//这个不好！
            digits[length]=0;
            digit_sum-=i;
        }
    }
}

int main() {
    digit_sum=0;
    int i;
    for(i=0; i<M; i++) {
        digits[i]=0;
        digit_max[i]=-1;
        digit_min[i]=10;
    }

    //一个整数有100位，这不能在long long中表达！
    scanf("%d%d",&m,&s);
    //printf("%d位，数字和为%d\n",m,s);
    search(0);
    if(max_change(digit_max) && min_change(digit_min)) {
        print_digit(digit_min);
        printf(" ");
        print_digit(digit_max);
        printf("\n");
    } else {
        printf("%d %d\n",-1,-1);
    }
    return 0;
}
