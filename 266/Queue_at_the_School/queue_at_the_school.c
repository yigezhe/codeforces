//第一，需要同时处理吗？
//我的思路是：用一个数组来标记找到的不同
//因为如果提前更换，就会重新创造出相邻的！
#include<stdio.h>
#define N 50+5
int main() {
    int n,t;
    scanf("%d%d",&n,&t);
    char arrangement[N];
    scanf("%s",arrangement);
    int i,j;
    int diff[N];
    for(i=0; i<t; i++) {
        for(j=0; j<n-1; j++) {
            if (arrangement[j]=='B' && arrangement[j+1]=='G') {
                diff[j]=1;
            } else {
                diff[j]=0;
            }
        }

        for(j=0; j<n-1; j++) {
            if(diff[j]) {
                char tmp=arrangement[j];
                arrangement[j]=arrangement[j+1];
                arrangement[j+1]=tmp;
            }
        }
    }
    printf("%s\n",arrangement);
    return 0;
}
