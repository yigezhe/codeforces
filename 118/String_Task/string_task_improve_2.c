#include<stdio.h>
#include<string.h>
int main() {
    char letters[150];
    scanf("%s",letters);
    int size=strlen(letters);
    //全部变为小写
    int is_vowels[256];
    int i;
    for(i=0; i<256; i++) {
        is_vowels[i]=0;
    }
    is_vowels[(int)'a']=1;
    is_vowels[(int)'o']=1;
    is_vowels[(int)'y']=1;
    is_vowels[(int)'e']=1;
    is_vowels[(int)'u']=1;
    is_vowels[(int)'i']=1;


    for(i=0; i<size; i++) {
        if (letters[i]>='A' && letters[i]<='Z') {
            letters[i]=letters[i]-'A'+'a';
        }
        if (!is_vowels[(int)letters[i]]) {
            printf(".%c",letters[i]);
        }

    }
    printf("\n");

    return 0;
}
