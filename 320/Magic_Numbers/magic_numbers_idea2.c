//首先有一个1，接下来是0个，一个，两个4
/*interface*/
/*interface implementation*/
/*client*/
#define N 10
#include<stdio.h>
void print(int *a,int n) {
    int i;
    for(i=0; i<n; i++) {
        printf(" %d",a[i]);
    }
    printf("\n");
}
int main() {
    int n;
    scanf("%d",&n);
    //从头开始处理，
    //需要建立一个数组来保存这个整数的各个数位！
    //从尾巴开始处理，我们需要先统计4，再统计1,可以不需要建立数组！
    //两种方法我都处理一下！
    int is_magic=1;
    int digit[N];
    int nd=0;
    while(n>0 ) {
        digit[nd]=n%10;
	nd++;
        n/=10;
    }
    //print(digit,nd);
    int i;
    for(i=0; i<nd/2; i++) {
        int tmp=digit[i];
        digit[i]=digit[nd-1-i];
        digit[nd-1-i]=tmp;
    }
    //print(digit,nd);
    i=0;
    while(i<nd) {
        int counter=0;
        while(digit[i]==1 && i<nd) {
            i++;
            counter++;
        }
        //4前面至少有一个1
        if(counter==0) {
            is_magic=0;
            break;
        }
        //1后面必须是4而不是其他数！
        if(i<nd && digit[i]!=4) {
            is_magic=0;
            break;
        }

        counter=0;
        while(digit[i]==4 && i<nd) {
            i++;
            counter++;
        }
        //1后面可以有0个，1个，2个4，但是不能超过2个！
        if(counter>2) {
            is_magic=0;
            break;
        }
    }
    if(is_magic) printf("YES\n");
    else printf("NO\n");
    return 0;
}
