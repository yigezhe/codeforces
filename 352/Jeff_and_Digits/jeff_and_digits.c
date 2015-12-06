//想法一，就是先组合后检查
//想法二，就是把所有90的倍数都造出来，然后，检查这些数中出现的5，0的个数
//与给定的5，0的个数是不是相同！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    printf("n = %d\n",n);
    long long i;
    int five=0;
    int zero=0;
    for(i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
        if(a==5) five++;
        else if(a==0) zero++;
    }
    printf("five = %d\n",five);
    printf("zero = %d\n",zero);
    long long max=0;
    for(i=0; i<n; i++) {
        max=max*10+5;
    }
    printf("max = %lld\n",max);
    int res=-1;
    if(zero>0) res=0;
    for(i=90; i<=max; i+=90) {
	    printf("i = %lld\n",i);
        int count_five=0;
        int count_zero=0;
        int count_other=0;
        long long tmp_i=i;
        while(tmp_i>0) {
            if(tmp_i%10==0) {
                count_zero++;
            } else if(tmp_i%10==5) {
                count_five++;
            } else {
                count_other++;
                break;
            }
            tmp_i = tmp_i/10;
        }
        if(count_other==0) {
            if(count_five<=five && count_zero<=zero) {
                res=i;
            }
        }
    }
    printf("%d\n",res);

    return 0;
}
