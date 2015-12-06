//这里的思路是
//2!不能分解
//3!不能分解
//4!=3!2!2!
//5!不能分解
//6!=5!3!
//7!不能分解
//8!=7!2!2!2!
//9!不能分解
//这时做一个替换就可以！
//+1+1+3=+5
#include<stdio.h>
#include<math.h>

//15个每一个都加三，15*4=60,还要包括\0,至少61！
#define N 70
//int 最多表示十位！

int main() {
    int n;
    scanf("%d",&n);
    char a[N];
    scanf("%s",a);
    int i;
    char b[N];
    int j=0;
    for(i=0; i<n; i++) {
        if(a[i]!='1' && a[i]!='0') {
            if(a[i]=='4') {
                b[j]='3';
                j++;
                b[j]='2';
                j++;
                b[j]='2';
                j++;

            } else if(a[i]=='6') {
                b[j]='5';
                j++;
                b[j]='3';
                j++;
            } else if(a[i]=='8') {
                b[j]='7';
                j++;
                b[j]='2';
                j++;
                b[j]='2';
                j++;
                b[j]='2';
                j++;
            } else {
                b[j]=a[i];
                j++;
            }
        }
    }
    b[j]='\0';
    printf("%s\n",b);
    return 0;
}
