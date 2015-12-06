#include<stdio.h>
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int my_sock=n;
    int day=1;
    while(1) {
        printf("day %d: %d socks\n",day,my_sock);
        my_sock--;
        if(day%m==0) {
            my_sock++;
        }

        day++;
        if(my_sock==1) {
            break;
        }

    }
    printf("%d\n",day);
    //这个版本和我的分析是一致的！
    return 0;
}
