/*interface*/
#include<stdio.h>
int abs(int a) {
    if(a>0) return a;
    else return -a;
}
int max(int a,int b) {
    if(a>b) return a;
    else return b;
}
/*interface implementation*/
/*client*/
int main() {
    char s[3];
    char t[3];
    scanf("%s",s);
    scanf("%s",t);
    int x_s,y_s;
    int x_t,y_t;
    x_s=s[0]-'a';
    y_s=s[1]-'0';
    x_t=t[0]-'a';
    y_t=t[1]-'0';

    int x_ts=x_t-x_s;
    int y_ts=y_t-y_s;
    printf("%d\n",max(abs(x_ts),abs(y_ts)));
    while(1) {
        if(x_ts==0 && y_ts==0) break;
        if(x_ts>0) {
            printf("R");
            x_ts--;
        } else if(x_ts<0) {
            printf("L");
            x_ts++;
        }
        if(y_ts>0) {
            printf("U");
            y_ts--;
        } else if(y_ts<0) {
            printf("D");
            y_ts++;
        }
	printf("\n");
    }

    return 0;
}
