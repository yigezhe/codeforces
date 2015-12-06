#include<stdio.h>
#define N 100
#define MAX 100+1
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    int a[N];
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    int instrument=0;
    int time=0;
    int learn[N];
    int j;
    while(1) {
        //找到最小时间的位置以及时间花费！
        int min_time=MAX;
        int position=-1;
        for(j=0; j<n; j++) {
            if(a[j]<min_time) {
                min_time=a[j];
                position=j+1;
            }
        }
	a[position-1]=MAX;
	//printf("%d\n",min_time);
        if(position==-1) {
            break;
        } else if(time+min_time<=k) {
            time+=min_time;
            learn[instrument]=position;
            instrument++;
        } else {
            break;
        }
    }
    printf("%d\n",instrument);
    for(i=0; i<instrument; i++) {
        if(i==instrument-1) printf("%d\n",learn[i]);
        else printf("%d ",learn[i]);
    }
    return 0;
}
