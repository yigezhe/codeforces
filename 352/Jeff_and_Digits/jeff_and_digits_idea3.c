//想法一，就是先组合后检查
//被90整除，先要被10整除，这个数后面肯定有一个零！
//剩下的数字要背9整除，
//则所有的数字之和要被九整除！
//给出所有组合2^1000=1000^100=(10^30)^10，不可行！
//同时整除5，同时整除90
//与给定的5，0的个数是不是相同！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    //printf("n = %d\n",n);
    long long i;
    int five=0;
    int zero=0;
    for(i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
        if(a==5) five++;
        else if(a==0) zero++;
    }
    while(five%9!=0) {
	    five--;
    }
    if(five%9==0) {
        if(zero>0) {
		//看来我只能打印这个数字，而不是用longlong，这个数字
		//也已经超出longlong的范围了!
            long long res=0;
            for(i=0; i<five; i++) {
                res=res*10+5;
            }
            for(i=0; i<zero; i++) {
                res=res*10;
            }
            printf("%lld\n",res);
        } else {

            printf("%d\n",-1);
        }
    } else {
        if(zero>0) {
            printf("%d\n",0);
        } else {
            printf("%d\n",-1);
        }
    }

    return 0;
}
