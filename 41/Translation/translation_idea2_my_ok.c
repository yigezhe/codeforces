#include<stdio.h>
#include<string.h>
#define N 100+1
int main() {
    char s[N];
    int i=0;
    while(1) {
        char a=getchar();
        if(a=='\n'|| a==EOF) {
            break;
        } else {
            s[i]=a;
            i++;
        }
    }
    s[i]='\0';
    int len=i;
    i=0;
    int is_reverse=1;
    while(1) {
        char a=getchar();
        if(a=='\n'|| a==EOF) {
            break;
        } else if(i<0) {
            break;
        } else if(s[len-1-i]==a) {
            //printf("%c==%c\n",s[len-1-i],a);
            i++;
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
