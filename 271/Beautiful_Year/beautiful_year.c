#include<stdio.h>

int distinct(int y) {
    int see[10];
    int i;
    for(i=0; i<10; i++) {
        see[i]=0;
    }
    while(1) {
        //printf("y=%d\n",y);
        if(y<10) {
            if(!see[y]) {
                return 1;
            } else {
                return 0;
            }
        } else {
            if(!see[y%10]) {
                see[y%10]=1;
                y=y/10;
            } else {
                return 0;
            }
        }
    }
    return 1;
}
int main() {
    int y;
    scanf("%d",&y);

    /*
    printf("%d=%d\n",y,distinct(y));
    printf("%d=%d\n",2013,distinct(2013));
    printf("%d=%d\n",2014,distinct(2014));
    printf("%d=%d\n",2114,distinct(2114));
    */
    int i;
    for(i=y+1; i<10000; i++) {
            //printf("%d\n",i);
        if(distinct(i)) {
            printf("%d\n",i);
            return 0;
        }
    }
    return 0;
}
