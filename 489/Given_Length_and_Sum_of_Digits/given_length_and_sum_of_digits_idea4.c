/*interface*/
#include<stdio.h>
#define M 100+1
#define S 900+1
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
int is_zero(int *a) {
    int i;
    for(i=0; i<m; i++) {
        if(a[i]!=0)return 0;
    }
    return 1;
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

void generate(int sum,int digit_number) {
//printf("generate(%d,%d)\n",sum,digit_number);
    if(sum==0) {
        if(digit_number==m) {
            if(compare(digits,digit_max)>=0) {
                copy(digits,digit_max);
            }
//print(digit_max);
            if(compare(digits,digit_min)<=0) {
                copy(digits,digit_min);
            }
//print(digit_min);
            return;
        } else {

            //copy_minus_one(digit_max);
            //copy_minus_one(digit_min);
            return;
        }
    } else {
        if(digit_number<m) {
            int i;
            for(i=0; i<10; i++) {
                digits[digit_number]=i;
                //if(sum-i>=0) generate(sum-i,digit_number++);这里用++是有问题的！
                if(sum-i>=0) generate(sum-i,digit_number+1);
                digits[digit_number]=0;
            }
	}
            else {
                return ;
            }
    }
}



int main() {
    digit_sum=0;
    int i;
    for(i=0; i<M; i++) {
        digits[i]=0;
        digit_max[i]=0;
        digit_min[i]=9;
    }

    //一个整数有100位，这不能在long long中表达！
    scanf("%d%d",&m,&s);
    //printf("%d位，数字和为%d\n",m,s);
    generate(s,0);
    if(is_zero(digit_max) && is_zero(digit_min)) {
        printf("%d %d\n",-1,-1);
    } else {
        print_digit(digit_min);
        printf(" ");
        print_digit(digit_max);
        printf("\n");
    }
    return 0;
}
