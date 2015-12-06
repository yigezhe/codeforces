//用a[1]=1
//用a[7]=1
//用a[3]=2
//a[other]=0
//可以可以，但是s最大是10^9
//a[10^9]~=4G不可取！
#include<stdio.h>
int main() {
    int diff[4];
    int i,j;
    int di=0;
    for(i=0; i<4; i++) {
        int a;
        scanf("%d",&a);
        int same=0;
        for(j=0; j<di; j++) {
            if(diff[j]==a) {
                same=1;
            }
        }
	if(!same) {
		//把不同的加入！
		diff[di]=a;
		di++;
	}
    }
    printf("%d\n",4-di);
    /*
    printf("di=%d\n",di);
    for(i=0; i<di; i++) {
	    printf(" %d",diff[i]);
    }
    printf("\n");
    */
    return 0;
}
