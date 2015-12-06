//submit ok!
//s是kirito的初始力量！
//n是龙的数量，或者怪物的数量！
//策略一，就是寻找它能打败的怪物中给他力量贡献最大的！
//我的想法是，不仅是贡献越大，越先消灭，在贡献相同的情况下
//应该先消灭力量小的，这里我可以做出一个按上面要求的排序！
/*interface*/
typedef struct {
    int x;
    int y;
} dragon;
int compare(const void*,const void*);
/*interface implementation*/
int compare(const void* a,const void* b) {
    dragon *c=(dragon *)a;
    dragon *d=(dragon *)b;
    //贡献值按从大到小排列，
    //贡献值相同，按力量从小到大排列！
    //*c.y的表示被解释为*(c.y)!而我们需要(*c).y
    if((*c).y < (*d).y) return 1;
    else if((*c).y > (*d).y) return -1;
    else {
        if((*c).x > (*d).x) return 1;
        else if((*c).x < (*d).x) return -1;
        else return 0;
    }
}
/*client*/
#include<stdio.h>
#include<stdlib.h>
#define N 10000
int main() {
    int s,n;
    scanf("%d%d",&s,&n);
    dragon xy[N];
    int i;
    for(i=0; i<n; i++) {
        scanf("%d%d",&xy[i].x,&xy[i].y);
    }
    /*
    for(i=0; i<n; i++) {
        printf(" %d,%d ",xy[i].x,xy[i].y);
    }
        printf("\n");
	*/
    //*xy其实代表xy数组的第一个元素！
    //所以xy[0]的表达会更好一些！
    qsort(xy,n,sizeof(xy[0]),compare);
    /*
    for(i=0; i<n; i++) {
        printf(" %d,%d ",xy[i].x,xy[i].y);
    }
        printf("\n");
	*/

    int deads=0;
    while(deads<n) {
	    /*
        for(i=0; i<n; i++) {
            printf(" %d",xy[i].x);
        }
        printf("    %d\n",s);
	*/

        //寻找最大增量！
        int find=0;
        for(i=0; i<n; i++) {
            //力量小于等于s的龙才可以被消灭！
            if(xy[i].x<s) {
                find=1;
                deads++;
                xy[i].x=N+1;
                s+=xy[i].y;
                break;
                //排序之后可以用break了！
            }
        }
        if(!find && deads<n) {
            //无法消灭！
            printf("NO\n");
            return 0;
        }
	/*
        for(i=0; i<n; i++) {
            printf(" %d",xy[i].x);
        }
        printf("    %d\n",s);
	*/
    }
    printf("YES\n");
    return 0;
}
