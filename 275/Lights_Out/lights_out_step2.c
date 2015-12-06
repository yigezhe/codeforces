#include<stdio.h>
    int a[3][3];
void print_grid(){
	int i,j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
        //printf("----------\n");
}

int main() {
    int i,j;
    int times[3][3];
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            scanf("%d",&times[i][j]);
        }
    }
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            a[i][j]=1;
        }
    }
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            if(times[i][j]%2==1) {
                a[i][j]=a[i][j]^1;
		//我知道了只有四个方向，而不是八个方向！
                if(i+1<3)a[i+1][j]=a[i+1][j]^1;
                if(j+1<3)a[i][j+1]=a[i][j+1]^1;
                if(i-1>=0)a[i-1][j]=a[i-1][j]^1;
                if(j-1>=0)a[i][j-1]=a[i][j-1]^1;
            }
	    /*
	    printf("%d--\n",times[i][j]);
            print_grid();
	    */
        }
    }
            print_grid();
    return 0;
}
