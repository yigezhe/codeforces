//如果两个点构成一个平行于x轴的向量，那么其它两个点无法确定
//如果两个点构成一个平行于y轴的向量，那么其他两个点无法确定！
/*interface*/
int abs(int ) ;

/*interface implementation*/
int abs(int a) {
    if(a<0) return -a;
    else return a;
}

/*client*/
#include<stdio.h>
int main() {
    int x1,y1,x2,y2;
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    if(x2-x1==0) {
        if(y2-y1==0) {
            //两个点重合无法给出其它两个点！
            //printf("here\n");
            printf("%d\n",-1);
        } else {
            //平行于y轴有四种选择！
            //因为x3,y3,x4,y4给的足够大，所以我没有必要
            //从四个中选一个！
            printf("%d %d %d %d\n",x1+y2-y1,y1,x1+y2-y1,y2);
        }
    } else {
	//平行于x轴也有四种选择！
        if(y2-y1==0) {
            printf("%d %d %d %d\n",x1,y1+x2-x1,x2,y1+x2-x1);
        } else {
            if(abs(x2-x1)!=abs(y2-y1)) {
                //printf("%d,%d\n",x2-x1,y2-y1);
                printf("%d\n",-1);
            } else {
                printf("%d %d %d %d\n",x1,y2,x2,y1);
            }
        }
    }
    return 0;
}
