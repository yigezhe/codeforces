//按下按钮后，
//第一个顺时针旋转，
//第二个逆时针旋转
//第三个顺时针旋转
//解决办法是遇到偶数使用(a+1)%n
//解决办法是遇到奇数使用(a-1)%n=(a+n-1)%n
/*interface*/
#include<stdio.h>
#define N 1000+1
int a[N];
int n;
/*interface implementation*/
void push() {
    int i;
    for(i=0; i<n; i++) {
        if(i%2==0) {
            a[i]=a[i]+1;
            if(a[i]>=n) a[i]=0;
        } else {
            a[i]=a[i]-1;
            if(a[i]<0) a[i]=n-1;
        }
    }
}
int is_ok() {
    int i;
    for(i=0; i<n; i++) {
        if(a[i]!=i) return 0;
    }
    return 1;
}
void print(int *array,int size) {
    int i;
    for(i=0; i<size; i++) {
        printf(" %d",array[i]);
    }
    printf("\n");
}
/*client*/
int main() {
    scanf("%d",&n);
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    int find=0;
    //不需要更精简，我的目的就是通过！
    //达到目的之外，不做多余的工作！
    for(i=0; i<n-1; i++) {
        //print(a,n);
        if(is_ok()) {
            find=1;
            break;
        } else {
            push();
        }
        //print(a,n);
    }
    //print(a,n);
    if(is_ok()) {
        find=1;
    }
    if(find) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
