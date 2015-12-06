//greedy有野心，贪婪的，饥渴的，想得到最多的！
/*interface*/
/*interface implementation*/
//1 2 3 4 5 6 7
//的选择方案
//7+5+3+1 ，6+4+2
/*client*/
#include<stdio.h>
#define N 1000
int main() {
    int n;
    scanf("%d",&n);
    int card[N];
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&card[i]);
    }
    int sereja=0;
    int dima=0;
    int head=0;
    int tail=n-1;
    while(head<=tail) {
        if(card[head]>card[tail]) {
            sereja+=card[head];
            head++;
        } else {
            sereja+=card[tail];
            tail--;
        }
        if(head<=tail) {
            if(card[head]>card[tail]) {
                dima+=card[head];
                head++;
            } else {
                dima+=card[tail];
                tail--;
            }
        } else {
            break;
        }

    }
    printf("%d %d",sereja,dima);
    return 0;
}
