/*interface*/
int is_uppercase(char);
int is_lowercase(char);
/*interface implementation*/
int is_uppercase(char ch) {
    if(ch>='A' && ch<='Z') return 1;
    else return 0;
}
int is_lowercase(char ch) {
    if(ch>='a' && ch<='z') return 1;
    else return 0;
}


/*client*/
#include<stdio.h>
#define S 101
int main() {
    char s[S];
    scanf("%s",s);
    int i;
    int upper=0;
    int lower=0;
    for(i=0; s[i]!='\0'; i++) {
        if(is_uppercase(s[i])) {
            upper++;
        }
        if(is_lowercase(s[i])) {
            lower++;
        }
    }
    if(upper>lower) {
        //打印大写
        for(i=0; s[i]!='\0'; i++) {
            if(is_lowercase(s[i])) {
                printf("%c",s[i]-'a'+'A');
            } else {
                printf("%c",s[i]);
            }
        }
            printf("\n");
    } else {
        //打印小写
        for(i=0; s[i]!='\0'; i++) {
            if(is_uppercase(s[i])) {
                printf("%c",s[i]-'A'+'a');
            } else {
                printf("%c",s[i]);
            }
        }

        printf("\n");

    }
    return 0;
}
