#include<stdio.h>
#include<string.h>
#define N 100+5
int main() {
    char word[N];
    scanf("%s",word);
    int size=strlen(word);
    int find=0;
    int which=0;
    int i;
    //看一下，该如何确定只出现一次cut！
    //提示用一次，但是题目中没有详细说只用一次！
    //不过只切割一次的要求值得做为一个新问题来尝试一下！
    int cuts=0;
    for(i=0; i<size && cuts<2; i++) {
        if(find==0) {
            if(word[i]=='C') {
                find=1;
                which=i;
                if(i!=0) cuts++;
            }
        } else if(find==1 && word[i]=='O') {
            if(i-which>1) { cuts++; } else { which=i; }
            find=2;
        } else if(find==2 && word[i]=='D') {
            if(i-which>1) { cuts++; } else { which=i; }
            find=3;
        } else if(find==3 && word[i]=='E') {
            if(i-which>1) { cuts++; } else { which=i; }
            find=4;
        } else if(find==4 && word[i]=='F') {
            if(i-which>1) { cuts++; } else { which=i; }
            find=5;
        } else if(find==5 && word[i]=='O') {
            if(i-which>1) { cuts++; } else { which=i; }
            find=6;
        } else if(find==6 && word[i]=='R') {
            if(i-which>1) { cuts++; } else { which=i; }
            find=7;
        } else if(find==7 && word[i]=='C') {
            if(i-which>1) { cuts++; } else { which=i; }
            find=8;
        } else if(find==8 && word[i]=='E') {
            if(i-which>1) { cuts++; } else { which=i; }
            find=9;
        } else if(find==9 && word[i]=='S') {
            if(i-which>1) { cuts++; } else { which=i; }
            find=10;
        }
    }
    if(find==10 && cuts<2) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
    return 0;
}
