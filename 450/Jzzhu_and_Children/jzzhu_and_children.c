//submit ok!
//candies蜡烛?
//这里想让初学者掌握栈或队列的思维？
//这里的问题是我无限制地使用了内存！
//想法一里，无限制地使用了内存！
//这里用有限内存实现想法一
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 10000
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int a[N];
    int b[N];
    //b用来保存获取的蜡烛。
    //a还是保存期望获取的蜡烛！
//number[i]=i;表示位置i上对应的是谁的蜡烛！
    int number[N];
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
        b[i]=0;
        number[i]=i;
    }
    int head=0;
    int tail=n;
    int child=n;

    while(head<tail) {
        //printf("%d: %d--",m,a[head]);
        if(m+b[head]>=a[head]) {
            child--;
            //printf("%d go home\n",head);
            if(child==0) {
                printf("%d\n",number[head]+1);
                break;
            }
            //head++;//变成一个平移
            for(i=head; i<tail-1; i++) {
                a[i]=a[i+1];
                b[i]=b[i+1];
                number[i]=number[i+1];
            }
            tail--;
        } else {
            int tmp1=a[head];
            int tmp2=b[head];
            int tmp3=number[head];
            for(i=head; i<tail-1; i++) {
                a[i]=a[i+1];
                b[i]=b[i+1];
                number[i]=number[i+1];
            }
            a[tail-1]=tmp1;
            b[tail-1]=tmp2+m;
            number[tail-1]=tmp3;
        }
    }
    return 0;
}
