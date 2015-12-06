//不重叠的AB和BA
/*interface*/
#include<stdio.h>
#include<string.h>
#define N 100000+1
/*interface implementation*/
/*client*/
int main() {
    char s[N];
    scanf("%s",s);
    //问题的复杂是，
    //ABACAB,这里ABA只能选择BA，把后面的作为AB
    //想法一统计有多少个AB，有多少个BA，
    //如果是1:1，则看两个是不是在一起形成了ABA，BAB！
    int n=(int)strlen(s);
    int i;
    int count_ab=0;
    for(i=0; i<n-1; i++) {
        if(s[i]=='A' && s[i+1]=='B') {
            count_ab++;
        }
    }
    int count_ba=0;
    for(i=0; i<n-1; i++) {
        if(s[i]=='B' && s[i+1]=='A') {
            count_ba++;
        }
    }
    int count_aba=0;
    for(i=0; i<n-2; i++) {
        if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='A') {
            count_aba++;
        }
    }
    int count_bab=0;
    for(i=0; i<n-2; i++) {
        if(s[i]=='B' && s[i+1]=='A' && s[i+2]=='B') {
            count_bab++;
        }
    }
    int count_abab=0;
    for(i=0; i<n-3; i++) {
        if(s[i]=='A' && s[i+1]=='B' && s[i+2]=='A' && s[i+3]=='B') {
            count_abab++;
        }
    }
    //对特殊情况进行专门的统计！
    int count_baba=0;
    for(i=0; i<n-2; i++) {
        if(s[i]=='B' && s[i+1]=='A' && s[i+2]=='B' && s[i+3]=='A') {
            count_baba++;
        }
    }

    int is_contain=1;
    if(count_ab==0 || count_ba==0) {
        is_contain=0;
    } else if(count_ab==1 && count_ba==0) {
        is_contain=0;
    } else if(count_ab==0 && count_ba==1) {
        is_contain=0;
	//ABA
    } else if(count_ab==1 && count_ba==1 && count_aba==1) {
        is_contain=0;
	//BAB
    } else if(count_ab==1 && count_ba==1 && count_bab==1) {
        is_contain=0;
	//ABAB
    } else if(count_ab==2 && count_ba==1 && count_abab==1) {
        is_contain=0;
	//BABA
    } else if(count_ab==1 && count_ba==2 && count_baba==1) {
        is_contain=0;
    } else {
        is_contain=1;
    }
    if(is_contain) printf("YES\n");
    else printf("NO\n");
    return 0;
}
