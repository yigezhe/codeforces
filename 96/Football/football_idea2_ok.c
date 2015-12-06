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
    int zeros=0,ones=0;
    for(i=0; i<size && !is_dangerous; i++) {
        if (players[i]=='0') {
            ones=0;
            zeros++;
        } else {
            zeros=0;
            ones++;
        }
	//printf("ones=%d,zeros=%d\n",ones,zeros);
        if(ones>=7 || zeros>=7) {
            is_dangerous=1;
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}
