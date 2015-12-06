/*interface*/
#include<stdio.h>
#include<math.h>
/*interface implementation*/
int s(int n) {
    int sum=0;
    while(n>0) {
        sum+=n%10;
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
    int record[9*8+1];
    int sx;
    for(sx=1; sx<=9*8; sx++) {
        double x=b*pow(sx,a)+c;
        //if(s(x)==sx) {
        if(fabs(s(x)-sx)<0.0000001) {
            printf("s(%f)=%d=%d\n",x,sx,s(x));
            record[rn]=x;
            rn++;
        }
    }
    printf("%d\n",rn);
    int i;
    for(i=0; i<rn; i++) {
        printf(" %d",record[i]);
    }
    printf("\n");
    return 0;
}
