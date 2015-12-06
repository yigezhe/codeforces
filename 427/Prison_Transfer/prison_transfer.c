/*interface*/
#include<stdio.h>
/*interface implementation*/
/*client*/
int main() {
    int n,t,c;
    scanf("%d%d%d",&n,&t,&c);
    int i=0;
    int times=0;
    int counter=0;
    while(1) {
        if(i>=n) break;
        int severity;
        scanf("%d",&severity);
        if(severity>t) times=0;
        else {
            times++;
            if(times>=c) counter++;
        }
        i++;
    }
    printf("%d\n",counter);
    return 0;
}
