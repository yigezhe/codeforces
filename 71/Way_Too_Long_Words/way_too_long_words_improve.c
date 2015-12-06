#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 100+5
int main() {
    int n;
    scanf("%d",&n);
    int i;
    for(i=0; i<n; i++) {
        char word[N];
        scanf("%s",word);
        int size=strlen(word);
        if (size>10) {
            /*
                printf("%c",word[0]);
                printf("%d",size-2);
                printf("%c\n",word[size-1]);
            */
            printf("%c%d%c\n",word[0],size-2,word[size-1]);

        } else {
            printf("%s\n",word);
        }
    }
    return 0;
}
