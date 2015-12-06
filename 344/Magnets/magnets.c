#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    char before='a';
    int count=1;
    if(n==0)count=0;
    //去掉读取n之后余留的\n
    while(1) {
        char a=getchar();//a==1 or 0
        //我做了一个统一处理！
	/*
        if(a=='\n')
            printf("%c,\\n\n",before);
        else
            printf("%c,%c\n",before,a);
	    */
        if(a==EOF) {
            break;
        }
        if(a!='\n') {
            if(a==before) {
                count++;
            }
	    //保证a与before同时在变！
            before=a;
        }
    }
    printf("%d\n",count);
    return 0;
}
