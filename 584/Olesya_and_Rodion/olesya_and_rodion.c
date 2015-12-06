/*interface*/
#include<stdio.h>
/*interface implementation*/
/*client*/
int main() {
    int n,t;
    scanf("%d%d",&n,&t);
    int i;
    if(t!=10) {
        printf("%d",t);
        for(i=0; i<n-1; i++) {
            printf("0");
        }
        printf("\n");
    } else {
        if(n==1) {
            printf("-1\n");
        } else {
            printf("%d",t);
            for(i=0; i<n-2; i++) {
                printf("0");
            }
            printf("\n");
        }
    }
    return 0;
}
