//装不下可以分批走不？
//这些简单的题目能很扎实地训练我的编程基本功，加油何伟伟！
//countryside边疆！
//思路是做一个累加
//把几个组放在一个bus中！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 100+1
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    int a[N];
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    i=0;
    int buses=0;
    while(i<n) {
        //printf("i=%d,",i);
        int sum=a[i];
        while(sum+a[i+1]<=m && i+1<n) {
            //printf("++i");
            sum+=a[i+1];
            i++;
        }
        //printf("\n");
        if(i<=n)buses++;
        i++;
    }
    printf("%d\n",buses);
    return 0;
}
