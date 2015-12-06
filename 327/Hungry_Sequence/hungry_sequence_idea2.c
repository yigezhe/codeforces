#include<stdio.h>
#define N 1400000
int main() {
	//我直接给出n个素数就可以！
    int n;
    scanf("%d",&n);

    int p[N];
    int i,j;
    for(i=2; i<N; i++) {
        p[i]=1;
    }
    for(i=2; i*i<N; i++) {
        if(p[i]) {//这里节省了一些查找！
            for(j=i; i*j<N; j++) {//j=i也节省了一些查找！
                p[i*j]=0;
            }
        }
    }
    p[0]=0;
    p[1]=0;
    int counter=0;
    for(i=2; i<N; i++) {
        if(p[i]){
		counter++;
		printf(" %d",i);
		if(n==counter) break;
	}
    }
    //printf("\nn=%d\n",n);
    printf("\n");
    return 0;
}
