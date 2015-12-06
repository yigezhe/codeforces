//没读懂题目意思，但从输入输出可以知道题目想做什么！
#include<stdio.h>
#include<string.h>
#define N 100+1
int main() {
    char guest[N];
    char host[N];
    char pile[N];
    scanf("%s",guest);
    scanf("%s",host);
    scanf("%s",pile);
    int count[256];
    int i;
    for(i=0; i<256; i++) {
        count[i]=0;
    }
    int gn=strlen(guest);
    for(i=0; i<gn; i++) {
        count[(int)guest[i]]++;
    }
    int hn=strlen(host);
    for(i=0; i<hn; i++) {
        count[(int)host[i]]++;
    }
    int pile_count[256];
    int pn=strlen(pile);
    for(i=0; i<256; i++) {
        pile_count[i]=0;
    }
    for(i=0; i<pn; i++) {
        pile_count[(int)pile[i]]++;
    }
    for(i=0; i<256; i++) {
        if(count[i]!=pile_count[i]) {
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n");

    return 0;
}
