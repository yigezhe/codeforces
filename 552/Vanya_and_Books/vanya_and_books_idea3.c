//现在的问题越来越有挑战性了！加油，何伟伟一定成功！永远相信自己！
/*interface*/
/*interface implementation*/
/*client*/
int digit_n(int n) {
    int digits=0;
    while(n>0) {
        digits++;
        n=n/10;
    }
    return digits;
}

#include<stdio.h>
int main() {
    long long n;
    scanf("%lld",&n);
    long long i;
    int digits=digit_n(n);
    //printf("n digits is %d\n",digits);
    long long all_digits=0;
    long long tens=10;
    for(i=1; i<=digits; i++) {
        //printf("all digits = %d\n",all_digits);
        if(n>=tens) {
            if(tens==10) {
                //1~9,9=9*1
                all_digits+=9;
                //printf("1 add %d\n",9);
            } else {
                //把tens与tens/10之间的所有数字都加起来！
                //10~99,(99-10+1)*2=90*2
                //100~999,(999-100+1)*3=900*3
                //依据总结出的规律给出的计算公式！
                all_digits+=(i*9*(tens/10));
                //printf("2 add %d\n",i*9*(tens/10));
            }
        } else {
            if(tens==10) {
                all_digits+=n;
                //printf("3 add %d\n",n);
            } else {
                //99, 10~99
                //999,100~999
                all_digits+=(long long)((n-tens/10+1)*i);

                //printf("4 add %d\n",(n-tens/10+1)*i);
                //printf("%d,%d,%d\n",n,tens/10,i);
            }
        }
        tens*=10;
        //printf("all digits = %d\n",all_digits);
        //printf("\n------------------\n");
    }
    printf("%lld\n",all_digits);
    return 0;
}
