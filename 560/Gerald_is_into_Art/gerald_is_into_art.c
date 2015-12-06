/*interface*/
#include<stdio.h>
int max(int a,int b) {
    if(a>b) return a;
    else return b;
}
/*interface implementation*/
/*client*/
int main() {
    int a1,b1;
    scanf("%d%d",&a1,&b1);
    int a2,b2;
    scanf("%d%d",&a2,&b2);
    int a3,b3;
    scanf("%d%d",&a3,&b3);
    int is_ok=0;
    if(b2+b3<=b1 && max(a2,a3)<=a1) {
        is_ok=1;
    } else if(b2+a3<=b1 && max(a2,b3)<=a1) {
        is_ok=1;
    } else if(a2+b3<=b1 && max(b2,a3)<=a1) {
        is_ok=1;
    } else if(a2+a3<=b1 && max(b2,b3)<=a1) {
        is_ok=1;
    } else if(a2+a3<=a1 && max(b2,b3)<=b1) {
        is_ok=1;
    } else if(a2+b3<=a1 && max(b2,a3)<=b1) {
        is_ok=1;
    } else if(b2+a3<=a1 && max(a2,b3)<=b1) {
        is_ok=1;
    } else if(b2+b3<=a1 && max(a2,a3)<=b1) {
        is_ok=1;
    } else {
        is_ok=0;
    }
    if(is_ok) printf("YES\n");
    else printf("NO\n");

    return 0;
}
