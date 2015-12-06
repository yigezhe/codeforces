#include<stdio.h>
#include<string.h>
#define N 100+5
int main() {
    char s1[N];
    char s2[N];
    scanf("%s",s1);
    scanf("%s",s2);
    int i;
    int size=strlen(s1);
    for(i=0; i<size; i++) {
        //先把s1，s2都变为小写字母
        if(s1[i]<='Z' && s1[i]>='A') s1[i]=s1[i]-'A'+'a';
        if(s2[i]<='Z' && s2[i]>='A') s2[i]=s2[i]-'A'+'a';
        //在两个都是小写字母的情况下，比较大小！
        if(s1[i]<s2[i]) {
            printf("-1\n");
            return 0;
        }
        if(s1[i]>s2[i]) {
            printf("1\n");
            return 0;
        }
    }
    printf("0\n");
    return 0;
}
