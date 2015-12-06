//为啥cf可以训练，就是因为它从基础题开始，
//竞赛题目的设计也是基础加中级加高级，
//所以我才可以从基础开始，走过中级，一直走到高级！
//最近已经可以解决cf的div2的c类问题了，何伟伟加油！你已经进步很大了！
/*interface*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
/*interface implementation*/
/*client*/
int main() {
    char digit[100];
    scanf("%s",digit);
    int i;
    //列举所有三位数以内的8的倍数！
    int unchange=1;
    for(i=0; i<1000; i+=8) {
        int find=0;
        int n=strlen(digit);
        int j=n-1,k=i;
        while(j>=0) {
            if(digit[j]-'0'==k%10) {
                k=k/10;
                if(k==0) {
                    find=1;
                    break;
                }
            }
            j--;
        }
        if(find) {
            printf("YES\n%d\n",i);
            unchange=0;
            break;
        }
    }
    if(unchange==1) {
        printf("NO\n");
    }
    return 0;
}
