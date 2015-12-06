//想法二：
//25不需要找零！
//50需要一个25！
//100需要一个25和一个50
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int i;
    int change25=0;
    int change50=0;
    for(i=0; i<n; i++) {
        int bill;
        scanf("%d",&bill);
        if(bill==25) {
            change25++;
        } else if(bill==50) {
            if(change25>0) {
                change25--;
                change50++;
            } else {
                printf("NO\n");
                return 0;
            }
        } else if(bill==100) {
            if(change25>0 && change50>0) {
                change25--;
                change50--;
                //收到100元无法用于找零！
            } else if(change25>2) {
                change25-=3;
            } else {
                printf("NO\n");
                return 0;
            }
        }
    }
    printf("YES\n");
    return 0;
}
