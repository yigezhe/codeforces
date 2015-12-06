#include<stdio.h>
#include<string.h>
#define N 100+5
int main() {
    char players[N];
    scanf("%s",players);
    int size=strlen(players);
    //printf("size = %d\n",size);
    //printf("%s\n",players);
    int is_dangerous=0;
    int i;
    int zeros,ones;
    for(i=0; i<size && !is_dangerous; i++) {
        zeros=0;
        while(i<size && !is_dangerous) {
            if (players[i]=='0') {
                //printf("%d:",i);
                i++;
                zeros++;
                if(zeros>=7) {
                    is_dangerous=1;
                    printf("YES\n");
                    return 0;

                }
            } else {
                break;
            }
        }
        //printf("0s=%d\n",zeros);
        //printf("i=%d in %c\n\n",i,players[i]);
        ones=0;
        while(i<size && !is_dangerous) {
            if(players[i]=='1') {
                //printf("%d:",i);
                i++;
                ones++;
                if(ones>=7) {
                    is_dangerous=1;
                    printf("YES\n");
                    return 0;

                }
            } else {
                break;
            }
        }
        //printf("1s=%d\n",ones);
        //printf("i=%d in %c\n\n",i,players[i]);
        i--;//这里减少i的原因是，我们已经进入下一个i了
        //但是for循环还会加一，导致我们进入下下一个i，这是我们
        //不想发生的事情，所以我用i－－来取消for循环里的i＋＋！

    }
    printf("NO\n");
    return 0;
}
