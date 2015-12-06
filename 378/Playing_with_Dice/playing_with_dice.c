
/*interface*/
/*interface implementation*/
int abs(int a) {
    if(a>0)return a;
    else return -a;
}
/*client*/
#include<stdio.h>
int main() {
    int a,b;
    scanf("%d%d",&a,&b);
    int i;
    int first_win=0;
    int second_win=0;
    int draw=0;
    for(i=1; i<=6; i++) {
        if(abs(i-a)>abs(i-b)) {
            second_win++;
        } else if(abs(i-a)<abs(i-b)) {
            first_win++;
        } else {
            draw++;
        }
    }
    printf("%d %d %d\n",first_win,draw,second_win);
    return 0;
}
