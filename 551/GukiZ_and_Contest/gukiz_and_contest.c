//1加比他分数高的人数！
//题目介绍有问题，
//例子中求解的是等级分数，而不是具体位置！
//这里位置就是等级？
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 2000
int main() {
    int n;
    scanf("%d",&n);
    int a[N];
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    int place[N];
    int j;
    for(i=0; i<n; i++) {
        int counter=1;
        for(j=0; j<n; j++) {
            if(i!=j && a[j]>a[i]) {
                counter++;
            }
        }
	place[i]=counter;
    }
    for(i=0; i<n; i++) {
	    if(i==0) printf("%d",place[i]);
	    else printf(" %d",place[i]);
    }
	    printf("\n");
    return 0;
}
