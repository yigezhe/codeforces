//submit ok!
//candies蜡烛?
//这里想让初学者掌握栈或队列的思维？
//想法二是我按照分析的思路实现的！
/*interface*/
/*interface implementation*/
#include<stdio.h>
void print(int *a,int n) {
    printf("[");
    int i;
    for(i=0; i<n; i++) {
        printf(" %d",a[i]);
    }
    printf("]\n");
}
/*client*/
#include<stdio.h>
#define N 100
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int a[N];
    int position[N];
    int candies[N];
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
        position[i]=i;
        candies[i]=0;
    }
    int head=0;
    int tail=n;
    int child=n;

    while(head<tail) {
        //printf("%d: %d--",m,a[head]);
        //print(position,tail);
	//想法二里没有让a跟着变！
        if(m+candies[head]>=a[position[head]]) {
            child--;
            //printf("%d go home\n",head);
            if(child==0) {
                //printf("last head = %d\n",head);
                printf("%d\n",position[head]+1);
                //printf("last head = %d\n",head);
                break;
            }
            for(i=head; i<tail-1; i++) {
                position[i]= position[i+1];
                candies[i]=candies[i+1];
            }
            tail--;
        } else {
            int tmp1=position[head];
            int tmp2=candies[head];
            for(i=head; i<tail-1; i++) {
                position[i]= position[i+1];
                candies[i]=candies[i+1];
            }
            position[tail-1]= tmp1;
            candies[tail-1]=tmp2+m;
        }
    }
    return 0;
}
