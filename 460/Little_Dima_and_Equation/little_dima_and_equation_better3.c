/*interface*/
#include<stdio.h>
#include<math.h>
/*interface implementation*/
int s(long long n) {
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
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int rn=0;
    //小于10^9的数是一个9位数，而不是一个8位数
    //所以9*8是错的，9*9才是对的！
    int record[9*9+1];
    int sx;
    for(sx=1; sx<=9*9; sx++) {
        //取消对pow的使用！
	long long x=1L;
	int i;
	for(i=0;i<a;i++) {
		x*=sx;
	}
        x=b*x+c;
        if(x<1000000000L) {
            if(s(x)==sx) {
                //if(fabs(s(x)-sx)<0.0000001) {
                //printf("s(%d)=%d=%d\n",x,sx,s(x));
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
