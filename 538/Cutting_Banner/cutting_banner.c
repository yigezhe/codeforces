#include<stdio.h>
#include<string.h>
#define N 100+5
int main() {
    char word[N];
    scanf("%s",word);
    int size=strlen(word);
    int begin;
    int end;
    for(begin=0; begin<size; begin++) {
        for(end=0; end<size; end++) {
            char cut_word[N];
            int i;
            int cw=0;
            for(i=0; i<size; i++) {
                if(i<begin || i>end) {
                    cut_word[cw]=word[i];
                    cw++;
                }
            }
            cut_word[cw]='\0';
	    if(strcmp(cut_word,"CODEFORCES")==0) {
		    printf("YES\n");
		    return 0;
	    }
        }
    }
    printf("NO\n");
    return 0;
}
