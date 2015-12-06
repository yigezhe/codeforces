/*interface*/
//我的工作太出色了，程序运作异常好！何伟伟，加油！
#include<stdio.h>
/*interface implementation*/
int max(int a,int b) {
    if(a>b) return a;
    else return b;
}
int min(int a,int b) {
    if(a<b) return a;
    else return b;
}

/*client*/
int main() {
    int a1,a2,a3,a4,a5,a6;
    scanf("%d%d%d%d%d%d",&a1,&a2,&a3,&a4,&a5,&a6);
    //我的六边形取向
    //a1是顶部
    //a4是底部
    //a2，a6是两个上侧边
    //a5，a3是两个下侧边
    int sum=0;
    int min_a3_a5=min(a3,a5);
    int max_a3_a5=max(a3,a5);
    int bottom=2*a4+1;
    sum+=bottom;
    //printf("current bottom is %d\n",bottom);
    int i;
    for(i=0; i<min_a3_a5-1; i++) {
        bottom+=2;
        sum+=bottom;
      //  printf("current bottom is %d\n",bottom);
    }
    //printf("current bottom is %d\n",bottom);
    if(a3!=a5) {
	    //对于规则的不加一，对于不规则的就要加一！
        bottom+=1;
    }
    for(i=min_a3_a5; i<max_a3_a5; i++) {
        sum+=bottom;
        //printf("current bottom is %d\n",bottom);
    }
    if(a3!=a5) {
        bottom-=1;
    }
    int min_a2_a6=min(a2,a6);
    for(i=min_a2_a6; i>0; i--) {
        sum+=bottom;
        bottom-=2;
        //printf("current bottom is %d\n",bottom);
    }
    printf("%d\n",sum);
    return 0;
}
