#include<stdio.h>
#include<string.h>
//#include<math.h>
int main() {
    int n;
    scanf("%d",&n);
    //1<=n<=10^9,n没有超过int的范围！
    //printf("%f\n",pow(2,31));
    char name[5][8];
    strcpy(name[0],"Sheldon");
    strcpy(name[1],"Leonard");
    strcpy(name[2],"Penny");
    strcpy(name[3],"Rajesh");
    strcpy(name[4],"Howard");
    //把0，1，2，3，4放入队列而不是把这些名字放入队列，把名字放入队列太费时间！
    int i;
    int value=0;
    int times=1;
    int t=0;
    //取消count速度应该可以增加！
    i=0;
    while(1) {
        if(value==5) {
            times*=2;
            value=0;
        }

	printf("%d ",value);
        if(i==n-1) {
	break;}
        if(t==times-1) {
            value++;
            t=0;
        } else {
            t++;
        }
	i++;
    }
printf("\nlast last=%d\n",value);

    return 0;
}
