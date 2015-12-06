#include<stdio.h>
#include<string.h>
int is_vowels(char c) {
    if (c=='a') return 1;
    if (c=='o') return 1;
    if (c=='y') return 1;
    if (c=='e') return 1;
    if (c=='u') return 1;
    if (c=='i') return 1;
    return 0;

}
int main() {
    char letters[150];
    scanf("%s",letters);
    int size=strlen(letters);
    //全部变为小写
    int i;
    for(i=0; i<size; i++) {
        if (letters[i]>='A' && letters[i]<='Z') {
            letters[i]=letters[i]-'A'+'a';
        }
    }
    for(i=0; i<size; i++) {
        if (!is_vowels(letters[i])) {
            printf(".%c",letters[i]);
        }
    }
    printf("\n");

    return 0;
}
