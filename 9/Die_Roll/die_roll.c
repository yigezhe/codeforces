/*interface*/
#include<stdio.h>
/*interface implementation*/
int max(int a,int b) {
    if(a>b) return a;
    else return b;
}
int gcd(int a,int b) {
    while(b>0) {
        //a b
        //b a%b
        int tmp=a;
        a=b;
        b=tmp%b;
    }
    return a;
}
/*client*/
int main() {
    int y,w;
    scanf("%d%d",&y,&w);
    int a=6-max(y,w)+1;
    int b=6;
    int g=gcd(a,b);
    if(g!=1) {
        a=a/g;
        b=b/g;
    }
    printf("%d/%d\n",a,b);
    return 0;
}
