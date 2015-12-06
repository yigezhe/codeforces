#include<stdio.h>
#define MAX 2020
int main() {
    int n;
    scanf("%d",&n);
    int i;
    int p[MAX];
    for(i=1; i<=n; i++) {
        scanf("%d",p+i);
    }

    int j=1;
    int max=0;
    while(j<=n) {
        i=j;
	//printf("i=%d\n",i);
        int count=0;
        while(i!=-1) {
	//printf("i=%d  ",i);
            i=p[i];
            count++;

        }
	//printf("\n");
        if(count>max) max=count;
	j++;
    }
    printf("%d\n",max);
    return 0;
}
