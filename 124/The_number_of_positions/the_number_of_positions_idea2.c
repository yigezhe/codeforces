//
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 100
int main() {
    int n,a,b;
    scanf("%d%d%d",&n,&a,&b);
    //他的前面有不少于a个人！大于等于a个人！
    //他的后面有不多于b个人！小于等于b个人！
    //1,2,...,n-1,n
    //1,2,...,a,a+1,
    //n,n-1,n-b+1
    int i;
    //0,n-1
    //1,n-2
    //n-1,0
    int counter=0;
    for(i=0; i<n; i++) {
        int front=i;
        int behind=n-1-i;
        if(front>=a && behind<=b) {
            counter++;
        }
    }
    printf("%d\n",counter);
    return 0;
}
