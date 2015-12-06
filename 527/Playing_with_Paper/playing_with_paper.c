//这里用的基本都是俄罗斯的英文名！
//10^12需要long long
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
    //printf("%d\n",1<<30);
    //printf("%lld\n",(long long)1<<62);
    long long a,b;
    scanf("%lld%lld",&a,&b);
    long long square=0;
    while(1) {
        square+=a/b;
        if(a%b==0) break;
	else {
		//这里必须保证全部是64位整数运算，c语言会混合32位与64位！
		long long tmp=a%b;
		a=b;
		b=tmp;
		
	}
    }
    printf("%lld\n",square);
    return 0;
}
