//石头攀岩，我越来越喜欢codeforces上设计的题目
//俄罗斯能成为帝国，与人民的智慧不可分割！
//石头攀岩！可以放脚，可以抓手的高度！
/*interface*/
/*interface implementation*/
/*client*/
int difficulty(int *a,int n,int remove) {
    int i;
    int max=0;
    // 1 2 3 4 5
    // 2 remove
    // 1 3 i=0
    // 3 4 i=2
    for(i=0; i<n; i++) {
        //在符合条件的情况下去比较！
        if(i+1<n) {
            if(i+1==remove) {
                //在符合条件的情况下去比较！
                if(i+2<n) {
                    if(a[i+2]-a[i]>max) {
                        max=a[i+2]-a[i];
                    }
                    i++;
                }
            } else {
                if(a[i+1]-a[i]>max) {
                    max=a[i+1]-a[i];
                }
            }
        }
    }
    return max;
}
#include<stdio.h>
#define N 100+1
int main() {
    int n;
    scanf("%d",&n);
    int i;
    int a[N];
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    //不用remove，直接比较！
    int min=1000+1;
    for(i=1; i<(n-1); i++) {
        //printf("remove %d difficulty is %d\n",i,difficulty(a,n,i));
        int diff=difficulty(a,n,i);
        if(diff<min) {
            min=diff;
        }
    }
    printf("%d\n",min);
    return 0;
}
