#include<stdio.h>
#define N 50
//排一个序，把第n个和第一个相减就可以！
int main() {
    int f[N];
    int n,m;
    scanf("%d%d",&n,&m);
    int i;
    for(i=0; i<m; i++) {
        scanf("%d",&f[i]);
    }
    int j;
    for(i=0; i<m; i++) {
        for(j=i+1; j<m; j++) {
            if(f[i]>f[j]) {
                //swap i and j
                int tmp=f[i];
                f[i]=f[j];
                f[j]=tmp;
            }
        }
    }
    printf("%d\n",f[n-1]-f[0]);
    return 0;
}
