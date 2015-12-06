/*interface*/
#include<stdio.h>
#define N 100
#define M 100+1
/*interface implementation*/
/*client*/
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    char subject[N][M];
    int successfull[N];
    for(i=0; i<n; i++) {
        scanf("%s",subject[i]);
        successfull[i]=0;
    }
    int j;
    for(i=0; i<m; i++) {
        int max=subject[0][i];
        for(j=1; j<n; j++) {
            if(subject[j][i]>max) {
                max=subject[j][i];
            }
        }
        for(j=0; j<n; j++) {
            if(subject[j][i]==max) {
                successfull[j]=1;
            }
        }
    }
    int counter=0;
    for(i=0; i<n; i++) {
        if(successfull[i]==1) counter++;
    }
    printf("%d\n",counter);

    return 0;
}
