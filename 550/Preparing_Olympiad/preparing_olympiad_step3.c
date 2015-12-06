#include<stdio.h>
#define N 15
int counter=0;
int n,r,l,x;
int c[N];
int b[N];
int nb=0;
void print(int *a, int size) {
    int i;
    for(i=0; i<size; i++) {
        printf(" %d",a[i]);
    }
    printf("\n");
}
void sort(int *a, int size) {
    int i,j;
    for(i=0; i<size-1; i++) {
        int k=i;
        for(j=i+1; j<size; j++) {
            if(a[j]<a[k]) {
                k=j;
            }
        }
        //there we only swap min with a[i];
        int tmp=a[k];
        a[k]=a[i];
        a[i]=tmp;
    }
}
void dfs2(int start,int deep) {
    if(nb>=2) {
        /*printf("dfs(%d,%d)\n",start,deep);
        print(b,nb);
	*/
        int sum=0;
        int j;
        for(j=0; j<nb; j++) {
            sum+=b[j];
        }
	/*
	printf("sum = %d\n",sum);
        printf("r=%d, sum=%d, l=%d\n",r,sum,l);
        printf("max=%d, x=%d, min=%d\n",b[nb-1],x,b[0]);
	*/
        if((sum<=r) && (b[nb-1]-b[0]>=x) && (sum>=l)) {
            counter++;
	    /*printf("counter = %d\n",counter);
            print(b,nb);
	    */
        }
    }
    if(deep==n) return;
    else {
        int i;
        for(i=start+1; i<n; i++) {
            b[nb]=c[i];
            nb++;
            dfs2(i,deep+1);
            nb--;
        }
    }
}

int main() {
    scanf("%d%d%d%d",&n,&l,&r,&x);
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&c[i]);
    }
    //print(c,n);
    sort(c,n);
    //print(c,n);
    //dfs(0,0);
    dfs2(-1,0);
    printf("%d\n",counter);

    return 0;
}
