#include<stdio.h>
int main() {
    int k,n,w;
    scanf("%d%d%d",&k,&n,&w);
    int need=(k*w*(w+1))/2;
    if(need>n) {
        printf("%d\n",need-n);
    } else {
        printf("%d\n",0);
    }
    return 0;
}
