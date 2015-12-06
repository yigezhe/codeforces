/*interface*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*interface implementation*/
/*client*/
int main() {
    int n,m;
    //n个灯，n个按钮！
    //m次按键！
    scanf("%d%d",&n,&m);
    int *b=malloc(m*sizeof(int));
    if(b==NULL) {
        printf("b 没有分配到内存\n");
    }
    int i,j;
    for(i=0; i<m; i++) {
        scanf("%d",&b[i]);
	b[i]=b[i]-1;//从1～n更换到0～n-1
    }

    int *on=malloc(n*sizeof(int));
    if(on==NULL) {
        printf("on 没有分配到内存\n");
    }

    for(i=0; i<n; i++) {
        on[i]=-1;
    }

    for(i=0; i<n; i++) {
        for(j=b[i]; j<n; j++) {
            if(on[j]==-1) on[j]=b[i];
        }
    }

    for(i=0;i<n;i++) {
	    printf(" %d",on[i]+1);
    }
    printf("\n");

    free(b);
    free(on);
    return 0;
}
