//我有点感受到了，竞赛的好处！
#include<stdio.h>
#define N 1000000+5
int main() {
    //9
    //9个1
    //32, 11,10,1
    //1000000, 1000000,111111,111110,111101,111100,111011
    //1000000
    //2^6=8*8=64中可能！
    //0 1 10 0 1 2
    //00 01 10 11 100 0 1 2 3 4
    int num[64];
    int i;
    for(i=0; i<64; i++) {
        num[i]=0;
    }

    //for(i=64;i>=1;i--) {//这样做应该可以保证num是从大到小排列的！
    int j;
    for(i=64; i>=1; i--) {
        /*
        num[64-i]+=((i&(1<<1))*10);
        num[64-i]+=((i&(1<<2))*100);
        num[64-i]+=((i&(1<<3))*1000);
        num[64-i]+=((i&(1<<4))*10000);
        num[64-i]+=((i&(1<<5))*100000);
        num[64-i]+=((i&(1<<6))*1000000);
        */

        int ten=1;
        num[64-i]+=(i&1);
        for(j=1; j<=6; j++) {
            ten*=10;
            if((i&(1<<j))!=0) {
                num[64-i]+=ten;
            }
        }
    }
    /*
    for(i=0; i<64; i++) {
        printf("%d\n",num[i]);
    }
    */
    int n;
    scanf("%d",&n);
    int count=0;
    int same[N];
    int same_times[N];
    int si=0;
    i=0;
    while(n>0) {
        if(n>=num[i]) {
            count+=(n/num[i]);
            same[si]=num[i];
            same_times[si]=n/num[i];
            n=n%num[i];
            i++;
            si++;
        } else {
            i++;
        }

    }
    printf("%d\n",count);
    for(i=0; i<si; i++) {
        for(j=0; j<same_times[i]; j++) {
            //最后一项单独处理一下！
            if((i==si-1) && (j==same_times[i]-1)) {
                printf("%d\n",same[i]);
            } else {
                printf("%d ",same[i]);
            }
        }
    }

    return 0;
}
