//s是kirito的初始力量！
//n是龙的数量，或者怪物的数量！
//策略一，就是寻找它能打败的怪物中给他力量贡献最大的！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 10000
int main() {
    int s,n;
    scanf("%d%d",&s,&n);
    int x[N];
    int y[N];
    int i;
    for(i=0; i<n; i++) {
        scanf("%d%d",&x[i],&y[i]);
    }
    int deads=0;
    while(deads<n) {
	    /*
        for(i=0; i<n; i++) {
            printf(" %d",x[i]);
        }
        printf("    %d\n",s);
	*/

        int max_yi=-1;
        int max_y=-1;
        //寻找最大增量！
        int find=0;
        for(i=0; i<n; i++) {
            //力量小于s的龙才可以被消灭！
	    //力量相同也不行！
            if(x[i]<s) {
                find=1;
                if(max_y<y[i]) {
                    max_y=y[i];
                    max_yi=i;
                }
            }
        }
        if(find) {
            deads++;
            //x[max_yi]=-1;
            //让其变得不可消灭！
            x[max_yi]=N+1;
            //printf("max y = %d\n",max_y);
            s+=max_y;
        } else if(deads<n) {
            //无法消灭！
            printf("NO\n");
            return 0;
        }
	/*
        for(i=0; i<n; i++) {
            printf(" %d",x[i]);
        }
        printf("    %d\n",s);
	*/
    }
    printf("YES\n");
    return 0;
}
