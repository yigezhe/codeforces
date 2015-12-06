//这个没有通过6 OOPS的测试！
#include<stdio.h>
#include<string.h>
#define MAX 105
int main() {
    char word[MAX];
    scanf("%s",word);
    int i;
    if (word[0]>='a' && word[0]<='z') {
        if(word[1]=='\0') {
            printf("%s\n",word);
            return 0;
        } else {
            int find=0;
            for(i=1; word[i]!='\0'; i++) {
                //word［i］不是大写！
                if (word[i]<'A' || word[i]>'Z') {
                    find=1;
                    break;
                }
            }
            if(!find) {
                //把word的第一个字母变为大写！
                //把剩下的都变为小写！

                printf("%c",word[0]-'a'+'A');
                int j;
                for(j=1; word[j]!='\0'; j++) {
                    //printf("%d:%c\n",j,word[j]);
                    if (word[j]>='A' && word[j]<='Z') {
                        printf("%c",word[j]-'A'+'a');
                    } else {
                        printf("%c",word[j]);
                    }
                }
                printf("\n");
                return 0;

            } else {
                printf("%s\n",word);
                return 0;
            }
        }
    }
    printf("%s\n",word);
    return 0;
}
