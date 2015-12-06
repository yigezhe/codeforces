/*interface*/
#include<stdio.h>
#define M 100+1
#define S 900+1
int m,s;
int digit[M];
void print(int *a) {
    int i;
    for(i=0; i<m; i++) {
        printf("%d",a[i]);
    }
}
int sum(int *a) {
    int i;
    int res=0;
    for(i=0; i<m; i++) {
        res+=a[i];
    }
    return res;
}

int main() {
    //先求最小值，再求最大值！
    //最小值总结的规律是
    //m=3
    //s=1,min=100
    //s=2,min=101
    //s=3,min=102
    //s=4,min=103
    //s=5,min=104
    //s=6,min=105
    //s=7,min=106
    //s=8,min=107
    //s=9,min=108
    //s=10,min=109
    //s=11,119
    //s=12,129
    //s=13,139
    //s=14,149
    //s=15,159
    //s=16,169

    //一个整数有100位，这不能在long long中表达！
    scanf("%d%d",&m,&s);
    //printf("%d位，数字和为%d\n",m,s);
    int i;
    digit[0]=1;
    for(i=1; i<m; i++) {
        digit[i]=0;
    }
    //print(digit); printf("\n");

    int position=m-1;
    for(i=2; i<=s; i++) {

        if(digit[position]==9) position--;
        if(position<0) {
            break;
        }
        digit[position]++;
        //print(digit); printf("\n");

    }
    //因为我的生成没有考虑s=0的情况，所以这种情况要单独处理！
    if(s==0) {
        if(m==1) {
            printf("%d",0);
        } else {
            printf("%d",-1);
        }
    } else if(sum(digit)!=s) {
        printf("%d",-1);
    } else {

        print(digit);
    }
    printf(" ");
    //最大值总结的规律是
    //m=3
    //s=1,max=100
    //s=2,max=200
    //s=3,max=300
    //s=4,max=400
    //s=5,max=500
    //s=6,max=600
    //s=7,max=700
    //s=8,max=800
    //s=9,max=900
    //s=10,max=910
    //s=11,920
    //s=12,930
    //s=13,940
    //s=14,950
    //s=15,960
    //s=16,970

    digit[0]=1;
    for(i=1; i<m; i++) {
        digit[i]=0;
    }
    //printf("----------\n");
    //print(digit); printf("\n");

    position=0;
    for(i=2; i<=s; i++) {
        if(digit[position]==9) {
            position++;
        }
        if(position>=m) {
            break;
        }
        digit[position]++;
        //print(digit); printf("\n");

    }
    //要把边界条件处理一下！
    if(s==0) {
        if(m==1) {
            printf("%d",0);
        } else {
            printf("%d",-1);
        }
    } else if(sum(digit)!=s) {
        printf("%d",-1);
    } else {
        print(digit);
    }
    printf("\n");
    return 0;
}
