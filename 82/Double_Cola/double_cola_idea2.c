//现在的想法是看看可以找到一个数学公式不！
#include<stdio.h>
#include<string.h>
#include<math.h>
#define N 1000000000
//#include<math.h>
int main() {
    int n=60;
    //scanf("%d",&n);
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
    printf("i%%5\n");
    for(i=0;i<n;i++) {
	    printf("%d ",i%5);
    }
    printf("\n");
    printf("(i/2)%%5\n");
    for(i=0;i<n;i++) {
	    printf("%d ",(i/2)%5);
    }
    printf("\n");
    printf("(i/4)%%5\n");
    for(i=0;i<n;i++) {
	    printf("%d ",(i/4)%5);
    }
    printf("\n");
    printf("(int)log2(i)\n");
    for(i=0;i<n;i++) {
	    if(i==0) printf("0 ");
	    else printf("%d ",(int)log(i));
    }
    printf("\n");
    int f=0;
    int c=0;
    for(i=0;i<50;i++) {
	    if(f<N) { printf("%d:%d ",c,f); c++; }
	    else break;
	   f+=(int)pow(2,i)*5;
    }
    printf("\n");
    for(i=0;i<n;i++) {
	    printf("%d ",(int)log(i/5+1));
    }
    printf("\n");
    for(i=0;i<n;i++) {
	    printf("%d ",(int)log(i/5.0+1));
    }
    printf("\n");




    return 0;
}
