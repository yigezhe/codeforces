/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
//32 31 10 9
//min=9
//32/9=3
//31/9=3
int main() {
    int n1,n2,k1,k2;
    scanf("%d%d%d%d",&n1,&n2,&k1,&k2);
    //于k1,k2无关！
    if(n1<=n2) {
        printf("Second\n");
    } else {
        printf("First\n");
    }
    return 0;
}
