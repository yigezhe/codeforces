//近期的问题，侧重去判断，用数组建立判断函数！
//A-Z,a-z,至少出现一次。
//我可以先统一变为小写，再判断a－z只不是至少出现一次！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define C 265
int main() {
    int ch[C];
    int i;
    for(i=0; i<C; i++) {
        ch[i]=0;
    }
    int n;
    scanf("%d",&n);
    getchar();//去掉读取数字后余留的换行符！
    for(i=0; i<n; i++) {
        char a=getchar();
	if(a>='A' && a<='Z') a=a-'A'+'a';
	//printf("%c",a);
        ch[(int)a]++;
    }
    for(i='a'; i<='z'; i++) {
        if(ch[i]==0) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");
    return 0;
}
