//这里的英语表达不够好！
/*interface*/
#include<stdio.h>
#include<string.h>
#define N 100000+1
/*interface implementation*/
/*client*/
int main() {
    char currency[N];
    scanf("%s",currency);
    int i;
    int even[N];
    int en=0;
    int n=strlen(currency);
    for(i=0; i<n; i++) {
        if((currency[i]-'0')%2==0) {
            even[en]=i;
            en++;
        }
    }
    if(en==0) {
        printf("-1\n");
    } else {
        i=0;
        //while((currency[even[i]]> currency[n-1]) && (i<en)) {
	//发现问题了，必须先检查是不是超范围了！
	//再去运用，否则超范围使用就会出错！
        while( (i<en) && (currency[even[i]]> currency[n-1])) {
            i++;
        }
        int change=i;
        if(i==en) {
            change=en-1;
        }
        char tmp=currency[even[change]];
        currency[even[change]]=currency[n-1];
        currency[n-1]=tmp;
        for(i=0; i<n; i++) {
            printf("%c",currency[i]);
        }
        printf("\n");

    }
    return 0;
}
