/*interface*/
#include<stdio.h>
/*interface implementation*/
/*client*/
int main() {
    int n;
    int i;
    int other=0;
    scanf("%d",&n);
    for(i=0; i<n; i++) {
        int finger;
        scanf("%d",&finger);
        other+=finger;
    }
    //printf("other = %d\n",other);
    int counter=0;
    for(i=1; i<=5; i++) {
        //其实可以更简单？
        if((i+other)%(n+1)!=1) counter++;
    }
    printf("%d\n",counter);
    return 0;
}
