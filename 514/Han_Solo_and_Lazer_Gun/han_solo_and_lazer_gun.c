/*interface*/
#include<stdio.h>
/*interface implementation*/
#define N 1000+1
/*client*/
int main() {
    int x[N],y[N];
    int dead[N];
    int n;
    scanf("%d%d%d",&n,&x[0],&y[0]);
    //printf("n=%d,x0=%d,y0=%d\n",n,x[0],y[0]);
    int i;
    for(i=1; i<=n; i++) {
        dead[i]=0;
        scanf("%d%d",&x[i],&y[i]);
    }
    int shoot=0;
    while(1) {
        int find=0;
        for(i=1; i<=n; i++) {
            if(dead[i]==0) {
                dead[i]=1;
                find=i;
                shoot++;
                break;
            }
        }
        //printf("find = %d\n",find);
        if(find==0) {
            break;
        } else {
            for(i=1; i<=n; i++) {
                if(dead[i]==0) {
                    //判断x[i],y[i]没有死掉的，是不是在x[0],y[0]与x[find],y[find]两点构成的直线上！
                    if((x[i]-x[0])*(y[find]-y[0]) == (x[find]-x[0])*(y[i]-y[0])) {
                        dead[i]=1;
                    }
                }
            }
        }
    }
    printf("%d\n",shoot);
    return 0;
}
