//andreid 是不是写错了，应该是andrewid
//想法一，就是统计一的个数和0的个数，取其差就可以！
//想法二，就是去模拟整个操作过程，内存上是允许的2*10^5就是200KiB
//而且消的方式多种多样，我可以先采用从头消！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    getchar();
    int i;
    int ones=0;
    int zeros=0;
    for(i=0; i<n; i++) {
        char ch=getchar();
        if(ch=='1')
            ones++;
        else if(ch=='0')
            zeros++;
    }
    if(ones>zeros)
        printf("%d\n",ones-zeros);
    else
        printf("%d\n",zeros-ones);
    return 0;
}
