
/*interface*/
#include<stdio.h>
#include<math.h>
/*interface implementation*/
/*client*/
int main() {
    int r,x,y,x1,y1;
    scanf("%d%d%d%d%d",&r,&x,&y,&x1,&y1);
    //double distance=sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
    long double distance=sqrtl((long double)(x-x1)*(x-x1)+(long double)(y-y1)*(y-y1));
    //printf("distance=%Lf\n",distance);
    long double steps=distance/2.0/r;
    if(distance==0.0) {
        printf("0\n");
	//这里我用(int)steps代替了floor(steps)
    } else if(steps-(int)steps==0.0) {
        printf("%d\n",(int)steps);
    } else {
        printf("%d\n",(int)steps+1);
    }
    return 0;
}
