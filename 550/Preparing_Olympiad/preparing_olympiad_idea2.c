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
void comb(int set,int select,int cn,int cm) {
        int i;
    if(select==cm) {
        int sum=0;
        int max=0;
        int min=1000001;
        for(i=0; i<cm; i++) {
            sum+=b[i];
            if(b[i]>max)max=b[i];
            if(b[i]<min)min=b[i];
        }
        if((sum<=r) && (max-min>=x) && (sum>=l)) {
            print(b,cm);
            counter++;
        }
    } else {
        for(i=set; i<cn; i++) {
            b[select]=c[i];
            comb(i+1,select+1,cn,cm);
        }
    }
}
int main() {
    scanf("%d%d%d%d",&n,&l,&r,&x);
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&c[i]);
    }
    sort(c,n);
    //print(c,n);
    for(i=2; i<=n; i++) {
        comb(0,0,n,i);
    }
    printf("%d\n",counter);

    return 0;
}
