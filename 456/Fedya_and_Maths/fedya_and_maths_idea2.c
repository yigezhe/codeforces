//为什么不用homework，而用hometask?
//这里，好像要看后两位！
//这里我觉得可能要实现一个除法！
//这个代码是实现最快的！
//2/2=2
//12/2=6
//22/2=11
/*interface*/
#include<stdio.h>
#include<string.h>
#define N 100000+1
int n;
char value[N];
/*interface implementation*/
void devide_by_2(char *v) {
    int i;
    for(i=0; i<n; i++) {
        v[i]=v[i]-'0';
    }
    for(i=0; i<n; i++) {
        if(v[i]%2==0) {
            v[i]=v[i]/2;
        } else {
            v[i]=v[i]/2;
            v[i+1]=v[i+1]+10;
        }
    }
    //取消前面的零！
    i=0;
    while(v[i]==0 && i<n) {
        i++;
    }
    int j;
    for(j=i; j<n; j++) {
        v[j-i]=v[j]+'0';
    }
    n=n-i;
}
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
    scanf("%s",value);
    //printf("n=%s\n",value);
    n=strlen(value);
    if(value[n-1]=='1' ||
            value[n-1]=='3' ||
            value[n-1]=='5' ||
            value[n-1]=='7' ||
            value[n-1]=='9' ) {
        printf("0\n");
    } else {
        devide_by_2(value);
    //printf("n/2=%s\n",value);
        if(value[n-1]=='1' ||
                value[n-1]=='3' ||
                value[n-1]=='5' ||
                value[n-1]=='7' ||
                value[n-1]=='9' ) {
            printf("0\n");
        } else {
            printf("4\n");
        }
    }
    return 0;
}
