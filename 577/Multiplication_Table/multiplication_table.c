//构造一个棋盘，内存会超掉！
//10^10的内存是很大的！
//还是从数学角度来考虑！
/*interface*/
#include<stdio.h>
/*interface implementation*/
/*client*/
int main() {
    int n,x;
    scanf("%d%d",&n,&x);
    //printf("%d %d\n",n,x);
    int i;
    int counter=0;
    //这个可以减少一半的工作量！
    for(i=1; i<=n && i*i<x; i++) {
        if(x%i==0) {
            if(i<=n && (x/i)<=n) {
                //printf("%d %d\n",i,x/i);
                counter++;
            }
        }
    }
    counter*=2;
    //printf("i=%d,%d %d\n",i,n,x);
    if(i<=n && (i*i)==x && x%i==0) counter++;
    printf("%d\n",counter);
    return 0;
}
