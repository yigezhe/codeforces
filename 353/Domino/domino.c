/*interface*/
#include<stdio.h>
/*interface implementation*/
int abs(int a) {
    if(a<0) return -a;
    else return a;
}
/*client*/

int main() {
    int n;
    scanf("%d",&n);
    int upper_odd=0;
    int lower_odd=0;
    int i;
    for(i=0; i<n; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        if(x%2==1) upper_odd++;
        if(y%2==1) lower_odd++;
    }
    int diff=upper_odd-lower_odd;
    int change=0;
    //printf("upper_odd=%d,lower_odd=%d\n",upper_odd,lower_odd);

    if(upper_odd==1 && lower_odd==1 && n==1) {
        change=-1;
    } else if(upper_odd%2==0 && lower_odd%2==0) {
        change=0;
    } else if(upper_odd%2==1 && lower_odd%2==1) {
        change=1;
    } else if(upper_odd%2==0 && lower_odd%2==1) {
        change=-1;
    } else if(upper_odd%2==1 && lower_odd%2==0) {
        change=-1;
    }
    printf("%d\n",change);
    //1 1怎么换都不行！
    //1 1
    //2 2就可以换！

    return 0;
}
