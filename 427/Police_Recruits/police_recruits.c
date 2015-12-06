//submit ok!
//例子一，在雇佣之前，已经有两个犯人是无法管制的！
//这里的管制是一对一的，一个警察对应一个犯人！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
int main() {
    int n;
    scanf("%d",&n);
    int i=0;
    int crime=0;
    int police=0;
    int untreated=0;

    while(i<n) {
        int a;
        scanf("%d",&a);
        if(a==-1) {
            crime++;
        } else if(a>0) {
            police+=a;
        }
        if(police<crime) {
            if(police==0) {
                untreated++;
                crime=0;
            }
        } else if(police>=crime) {
            if(crime!=0) {
                police--;
                crime--;
            }
        }
        i++;
    }
    printf("%d\n",untreated);
    return 0;
}
