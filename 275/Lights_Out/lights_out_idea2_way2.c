#include<stdio.h>
int a[3][3];
void print_grid() {
    int i,j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            printf("%d",a[i][j]);
        }
        printf("\n");
    }
    //printf("----------\n");
}
void toggle(int *v) {
    if(*v==1)*v=0;
    else *v=1;
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
                toggle(&a[i][j]);
                //我知道了只有四个方向，而不是八个方向！
                if(i+1<3) toggle(&a[i+1][j]);
                if(j+1<3) toggle(&a[i][j+1]);
                if(i-1>=0)toggle(&a[i-1][j]);
                if(j-1>=0)toggle(&a[i][j-1]);
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
