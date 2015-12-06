//我在工作的业余时间记忆的单词用到了！
//subway地铁，以前只是一个模糊的记忆！
//我已经决定买房子了！
//concatenated连接！
//女生会根据对你的了解，熟悉程度，决定跟你玩什么！
//k个相互连接的回文字！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#include<string.h>
#define S 1000+1

int is_palindrome(char *str,int n) {
    int i;
    for(i=0; i<n/2; i++) {
        if(str[i]!=str[n-1-i]) return 0;
    }
    return 1;
}
void test_is_palindrome() {
    char a[5];
    a[0]='a';
    a[1]='b';
    a[2]='c';
    a[3]='\0';
    if(is_palindrome(a,3)) {
        printf("%s是回文字\n",a);
    } else {
        printf("%s不是回文字\n",a);
    }

}
int main() {

//test_is_palindrome() ;
    char s[S];
    int k;
    scanf("%s",s);
    scanf("%d",&k);
    int length=(int)strlen(s);
    //我学到的piece by piece直接运用，我觉得这里就是独立的一片片！
    //所以选用了这个单词！这份学习对我的帮助是立刻建立效果的！
    //这个题目还要求处理好这些小细节!
    if(k>length || length%k!=0) {
        printf("NO\n");
        return 0;
    }
    int piece=length/k;
    int where=0;
    while(where<length) {
        char tmp[S];
        int i;
        for(i=0; i<piece; i++) {
            tmp[i]=s[where+i];
        }
        tmp[i]='\0';
        if(!is_palindrome(tmp,piece)) {
            printf("NO\n");
            return 0;
        }
        where+=piece;
    }
    printf("YES\n");

    return 0;
}
