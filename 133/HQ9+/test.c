#include<stdio.h>
int main() {
    printf("33=%c\n",(char)33);
    printf("126=%c\n",(char)126);
    int i;
    for(i=33; i<=126; i++) {
        printf("%c ",(char)i);
    }
    //这些表达了键盘上主要的可直接输入的字符！
    printf("\b\n");
    return 0;
}
