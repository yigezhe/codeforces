#include<stdio.h>
#include<string.h>
#define N 100+5
int main() {
    char word[N];
    scanf("%s",word);
    int size=strlen(word);
    int find=0;
    int i;
    for(i=0; i<size; i++) {
        if(find==0 && word[i]=='C') {
            find=1;
        } else if(find==1 && word[i]=='O') {
            find=2;
        } else if(find==2 && word[i]=='D') {
            find=3;
        } else if(find==3 && word[i]=='E') {
            find=4;
        } else if(find==4 && word[i]=='F') {
            find=5;
        } else if(find==5 && word[i]=='O') {
            find=6;
        } else if(find==6 && word[i]=='R') {
            find=7;
        } else if(find==7 && word[i]=='C') {
            find=8;
        } else if(find==8 && word[i]=='E') {
            find=9;
        } else if(find==9 && word[i]=='S') {
            find=10;
        }
    }
    if(find==10) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
