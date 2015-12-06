//为什么不用homework，而用hometask?
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
    char before,current;
    char last;
    before='a';
    int counter=0;
    while(1) {
        current=getchar();
        if(current==EOF || current=='\n') {
            last=before;
            break;
        } else {
            before=current;
            if(counter<3)counter++;
        }
    }
    printf("last char is %c\n",last);
    int last_num=last-'0';
    if(last_num==0) {
        //这时n＝0
        if(counter==1) {
            printf("4\n");
        } else {
            printf("0\n");
        }
    } else if(last_num % 2 == 1) {
        printf("0\n");
    } else {
        if((last_num/2) % 2 == 1) {
            printf("0\n");
        } else {
            printf("4\n");
        }
    }
    return 0;
}
