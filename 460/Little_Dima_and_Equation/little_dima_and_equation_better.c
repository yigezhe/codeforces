/*interface*/
#include<stdio.h>
#include<math.h>
/*interface implementation*/
long long power(long long x,int a) {
    int i;
    long long prod=1;
    for(i=0; i<a; i++) {
        prod*=x;
    }
    return prod;
}
int s(int n) {
    int sum=0;
    while(n>0) {
        sum+=(n%10);
        n=n/10;
    }
    return sum;
}
/*client*/
int main() {
    //因为x是1到10^9之间的整数，
    //所以s(x)的最小值是1，最大值是9*8
    long long a,b,c;
    scanf("%Ld%Ld%Ld",&a,&b,&c);
    int rn=0;
    int record[9*8+1];
    long long sx;
    for(sx=1; sx<=9*8; sx++) {
        //取消对pow的使用！
        long long x=b*power(sx,a)+c;
        if(x<1000000000L) {
            if(s(x)==sx) {
                //if(fabs(s(x)-sx)<0.0000001) {
                //printf("s(%Ld)=%Ld=%d\n",x,sx,s(x));
                //这里不记录10^9以上的，我的判断是对的！
                record[rn]=x;
                rn++;
            }
        }
    }
    printf("%d\n",rn);
    int i;
    for(i=0; i<rn; i++) {
        printf(" %d",record[i]);
    }
    printf("\n");
//printf("%Ld\n",(long long)(9998*50*50*50*50*50+9998));
    return 0;
}
