//submit ok!
//判断奇偶数之间的差别？
//evenness是奇偶性的意思？
//平整度是什么？数组的平整度是什么？
/*interface*/
int abs(int  ) ;
/*interface implementation*/
int abs(int a) {
    if(a<0) return -a;
    else return a;
}
/*client*/
#include<stdio.h>
#define N 100
int main() {
    //偶数里有一个奇数
    //奇数里有一个偶数！
    int n;
    scanf("%d",&n);
    int i;
    int a[N];
    int even=0;
    int odd=0;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
        if(a[i]%2==0) even++;
        else odd++;
    }
    if(even==1) {
        for(i=0; i<n; i++) {
            if(a[i]%2==0) {
                printf("%d\n",i+1);
                return 0;
            }
        }
    } else if(odd==1) {
        for(i=0; i<n; i++) {
            if(a[i]%2==1) {
                printf("%d\n",i+1);
                return 0;
            }
        }
    } else {
        printf("我不知道如何处理、\n");
        return 1;
    }

    return 0;
}
