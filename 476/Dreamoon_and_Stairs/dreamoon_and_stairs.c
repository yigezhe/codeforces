//我决定采用遍历法！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int start=n/2;
    if(n%2==1) {
        start++;
    }
    //每次走两个台阶，最快，
    //如果总台阶数是结束，最后一步只能走一个台阶！
    //最慢是一步一个台阶。
    //这样一来，最快与最慢之间的所有数字都可以达到！
    //我们从最快的开始，只要遇到被m整除的情况就停止。
    //那个数字就是我们需要的满足要求的最小步数。
    int i;
    for(i=start; i<=n; i++) {
        if(i%m==0) {
            printf("%d\n",i);
            return 0;
        }
    }
    printf("%d\n",-1);
    return 0;
}
