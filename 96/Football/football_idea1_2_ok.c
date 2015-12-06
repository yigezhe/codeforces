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
    i=0;
    while(i<size && !is_dangerous) {
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
    }
    printf("NO\n");
    return 0;
}
