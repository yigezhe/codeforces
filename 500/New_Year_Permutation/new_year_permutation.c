#include<stdio.h>
#include<math.h>
#define N 305
int main() {
    int n;
    int p[N];
    int i,j;
    scanf("%d",&n);
    printf("n=%d\n",n);
    for(i=0; i<n; i++) {
        scanf("%d",p+i);
        printf(" %d",p[i]);
    }
    printf("\n");
    char A[N][N];
    struct exchange {
        int x,y;
    };
    struct exchange ex[N*N];
    int k=0;
    for(i=0; i<n; i++) {
        scanf("%s",A[i]);
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(A[i][j]=='1') {
                ex[k].x=i;
                ex[k].y=j;
                k++;
            }
        }
    }
    printf("k=%d\n",k);
    int tmp_p[N];
    int prettier_p[N];
    for(i=0; i<N; i++) {
        prettier_p[i]=p[i];
    }

    for(i=0; i<pow(2,k); i++) {
        for(j=0; j<N; j++) {
            tmp_p[j]=p[j];
        }

        printf("i=%x\n",i);
        for(j=0; j<k; j++) {
            if(i & 1<<j) {
                int tmp=tmp_p[ex[j].x];
                tmp_p[ex[j].x]=tmp_p[ex[j].y];
                tmp_p[ex[j].y]=tmp;
            }

        }
        int is_prettier=0;
        for(j=0; j<n; j++) {
            if(tmp_p[j]<prettier_p[j]) {
                is_prettier=1;
                break;
            }
        }
        if(is_prettier) {
            for(j=0; j<n; j++) {
                prettier_p[j]=tmp_p[j];
            }

        }
    }
    for(j=0; j<n; j++) {
        printf("%d ",prettier_p[j]);
    }
    printf("\n");

    return 0;
}
