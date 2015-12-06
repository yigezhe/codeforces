//inscribed镶嵌在里面,内在描述
//describe描述，表面描述
//办法，我用四条直线来处理这个问题
//x+y-a=0,保证方格内是正，方格外是负数！
//x-y+a=0
//-x-y+3*a=0
//-x+y+a=0
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 101
int main() {
    int n;
    scanf("%d",&n);
    char crystal[N][N];
    int i,j;
    int mid=n/2;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            if(i+j-mid>=0 && i-j+mid>=0 && -i-j+3*mid>=0 && -i+j+mid>=0) {
                crystal[i][j]='D';
            } else {
                crystal[i][j]='*';
            }
        }
    }
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
		printf("%c",crystal[i][j]);
        }
	printf("\n");
    }

    return 0;
}
