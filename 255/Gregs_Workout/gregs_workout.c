//这还是一个与体育训练有关的题目！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int i;
    int chest=0,biceps=0,back=0;
    for(i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
        if((i+1)%3==1) {
            chest+=a;
        } else if((i+1)%3==2) {
            biceps+=a;
        } else if((i+1)%3==0) {
            back+=a;
        }
    }
    if(chest>biceps) {
        if(chest>back) {
            printf("chest\n");
        } else {
            printf("back\n");
        }
    } else {
        if(biceps>back) {
            printf("biceps\n");
        } else {
            printf("back\n");
        }
    }
    return 0;
}
