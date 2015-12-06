//办法一，把所有人都统一转到二楼，到二楼的留下，再把剩下的统一转到三楼，到三楼的留下，剩下的统一转到四楼
//这就是一个模拟！
#include<stdio.h>
#define N 2000
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    int f[N];
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&f[i]);
    }
    int seconds=0;
    int reminder=n;
    int floor=1;
    while(reminder>0) {
        //移动所有元素到二楼
        floor++;
        //printf("floor=%d\n",floor);
        if(reminder%k!=0)  {
            seconds+=2*(reminder/k)+1;
        } else {
            seconds+=2*(reminder/k)-1;
        }
        //把所有到二楼的人都留下！
        //我的办法是吧已经到达的人标记为f［i］＝0
        for(i=0; i<n; i++) {
            if(f[i]==floor) {
                f[i]=0;
                reminder--;
            }
        }
    }
    seconds+=floor-1;
    printf("%d\n",seconds);

    return 0;
}
