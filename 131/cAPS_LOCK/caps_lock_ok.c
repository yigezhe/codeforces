#include<stdio.h>
#include<string.h>
#define MAX 105
int main() {
    char word[MAX];
    scanf("%s",word);
    int size=strlen(word);
    int is_reverse=1;
    int i;
    if (word[0]>='A' && word[0]<='Z') {
        for(i=1; i<size; i++) {
            if (word[i]>='a' && word[i]<='z') {
                is_reverse=0;
                break;
            }
        }
    } else if (word[0]>='a' && word[0]<='z') {
        for(i=1; i<size; i++) {
            if (word[i]>='a' && word[i]<='z') {
                is_reverse=0;
                break;
            }
        }
    }
    if(is_reverse) {
        for(i=0; i<size; i++) {
            if (word[i]>='A' && word[i]<='Z') {
		    printf("%c",word[i]-'A'+'a');
            } else {
		    printf("%c",word[i]-'a'+'A');
	    }
        }
	printf("\n");

    } else {
	    printf("%s\n",word);
    }

    return 0;
}
