//submit ok!
//invert互换！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
    //printf("%d\n",1<<31);
    //printf("%u\n",(unsigned int ) (1<<31));
    long long x;
    scanf("%lld",&x);
    int replace[10];
    replace[0]=0;
    replace[1]=1;
    replace[2]=2;
    replace[3]=3;
    replace[4]=4;
    replace[5]=4;
    replace[6]=3;
    replace[7]=2;
    replace[8]=1;
    replace[9]=0;
    //尽可能替换成最小的！
    int length=0;
    int digit[20];
    while(x>0) {
        digit[length]=x%10;
        //printf("%lld",x%10);
        x=x/10;
        length++;
    }
    int i=length-1;
    if(digit[i]==9) {
        printf("%d",digit[i]);
    } else {
        printf("%d",replace[digit[i]]);
    }
    i--;
    int j;
    for(j=i; j>=0; j--) {
        printf("%d",replace[digit[j]]);
    }
    printf("\n");
    return 0;
}
