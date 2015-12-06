//没有数字键的手机
//吃咖啡粉末，总是创造各种新奇！
//messed up混淆起来！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#include<string.h>
#define N 100
int main() {
    int s;
    scanf("%d",&s);
    char text[N][N];
    int i;
    for(i=0; i<N; i++) {
        text[i][0]='\0';
    }
    strcpy(text[0],"zero");
    strcpy(text[1],"one");
    strcpy(text[2],"two");
    strcpy(text[3],"three");
    strcpy(text[4],"four");
    strcpy(text[5],"five");
    strcpy(text[6],"six");
    strcpy(text[7],"seven");
    strcpy(text[8],"eight");
    strcpy(text[9],"nine");
    strcpy(text[10],"ten");
    strcpy(text[11],"eleven");
    strcpy(text[12],"twelve");
    strcpy(text[13],"thirteen");
    strcpy(text[14],"fourteen");
    strcpy(text[15],"fifteen");
    strcpy(text[16],"sixteen");
    strcpy(text[17],"seventeen");
    strcpy(text[18],"eighteen");
    strcpy(text[19],"nineteen");
    strcpy(text[20],"twenty");
    strcpy(text[30],"thirty");
    strcpy(text[40],"forty");
    strcpy(text[50],"fifty");
    strcpy(text[60],"sixty");
    strcpy(text[70],"seventy");
    strcpy(text[80],"eighty");
    strcpy(text[90],"ninety");
    if(s<21) {
        printf("%s",text[s]);
    } else {
        if(s%10==0) {
            printf("%s",text[s]);
        } else {
            printf("%s-%s",text[(s/10)*10],text[s%10]);
        }
    }

    return 0;
}
