#include<stdio.h>
#include<string.h>
#define N 100+1
int main() {
    char s[N];
    char t[N];
    scanf("%s",s);
    scanf("%s",t);
    int len=strlen(s);
    int si=0;
    int ti=len-1;
    int is_reverse=1;
    while(1) {
        if(ti<0 || si>len-1) {
            break;
        } else if(s[si]==t[ti]) {
            si++;
            ti--;
        } else {
            is_reverse=0;
            break;
        }
    }
    if(is_reverse) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
