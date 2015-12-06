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
void dfs1(int start,int deep) {
    printf("dfs(%d,%d)\n",start,deep);
    print(b,nb);
    if(deep==n) return;
    else {
	    int i;
        for(i=start; i<n; i++) {
            b[nb]=c[i];
            nb++;
                dfs1(i,deep+1);
		nb--;
            }
        }
    }
void dfs2(int start,int deep) {
	if(nb>=2) {
    printf("dfs(%d,%d)\n",start,deep);
    print(b,nb);
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

void dfs(int start,int deep) {
    printf("dfs(%d,%d)\n",start,deep);
    print(b,n);
    int i;
    if(deep==n) return;
    else if(deep==0) {
        for(i=0; i<n-1; i++) {
            b[nb]=c[i];
            nb++;
            dfs(i,deep+1);
            nb--;
        }
    } else {
        for(i=start+1; i<n; i++) {
            b[nb]=c[i];
            nb++;
            int j;
            int sum=0;
            for(j=0; j<nb; j++) {
                sum+=b[j];
            }
            //if sum is exceed, then next element we don't need.
            if(sum<=l) {
                //if x and r don't satisfy, add next element will satisfy, when all condition is satisfy, we will count once.
                if(b[nb]-b[0]>=x && sum>=r) {
                    counter++;
                }
                dfs(i,deep+1);
		nb--;
            }
        }
    }
}

int main() {
    scanf("%d%d%d%d",&n,&l,&r,&x);
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&c[i]);
    }
    print(c,n);
    sort(c,n);
    print(c,n);
    //dfs(0,0);
    //dfs1(0,0);
    dfs2(-1,0);
    printf("%d\n",counter);

    return 0;
}
