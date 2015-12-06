//为什么不用homework，而用hometask?
//这里，好像要看后两位！
//2/2=2
//12/2=6
//22/2=11
//只需要看后两位是有道理的！
//因为100/2=50还是偶数，所以百位以上不影响后面的奇偶性！
//10/2=5,这样各位是奇数和偶数是影响整体的奇偶性的！
//所以结论是个位和十位综合决定了一个整数的奇偶性！
/*interface*/
#include<stdio.h>
/*interface implementation*/
/*client*/
int main() {
    //寻找到了规律！
    //4=5-1
    //4^n=(5-1)^n
    //4^n mod 5 = (5-1)^n mod 5 = (-1)^n mod 5
    //3=5-2
    //3^n=(5-2)^n
    //3^n mod 5 = (5-2)^n mod 5 = (-2)^n mod 5
    //
    //(1^n+2^n+3^n+4^n) mod 5 = (1^n+2^n+(-2)^n+(-1)^n) mod 5
    //一个有用的结论是当n是奇数时，结果是0
    //这里我们只需要最后一个数字！
    //
    //(1^2k+2^2k+3^2k+4^2k) mod 5 = (1^2k+2^2k+(-2)^2k+(-1)^2k) mod 5
    //= (2+4^k+4^k) mod 5
    //= (2+2*4^k) mod 5
    //= (2+2*(5-1)^k) mod 5
    //= (2+2*(-1)^k) mod 5
    //= (2(1+(-1)^k)) mod 5
    //当k是奇数，结果是0
    //当k是偶数，结果是4
    //继续进一步探讨n时偶数的情况！
    char first,second,current;
    first='a';
    second='b';
    while(1) {
        current=getchar();
        if(current==EOF || current=='\n') {
            break;
        } else {
            first=second;
            second=current;
        }
    }
    //只处理后面两位应该看看能成不？
    //printf("1:%c 2:%c 3:%d\n",first,second,current);
    int second_num=second-'0';
    int first_num=first-'0';
    int num;
    //把后面两位形成的整数单独计算出来！
    if(first=='b') {
        //说明数字是一位数！
        num=second_num;
    } else {
        num=first_num*10+second_num;
    }
    if(num%2==1) {
	    printf("0\n");
    } else {
	    num=num/2;
	    if(num%2==1) {
		    printf("0\n");
	    }else {
		    printf("4\n");
	    }
    }
    return 0;
}
