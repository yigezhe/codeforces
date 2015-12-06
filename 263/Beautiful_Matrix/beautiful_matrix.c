#include<stdio.h>
#define N 5+5
int abs(int n) {
	if(n<0) return -n;
	else return n;
}
int main() {
    //找到1之后，其它的数据就不用读取了。
    //但是没有必要做出这种节省！
    int matrix[N][N];
    int n=5;
    int x1,y1;
    int i,j;
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
		scanf("%d",&matrix[i][j]);
		if(matrix[i][j]==1) {
			x1=i;
			y1=j;
		}
        }
    }
    printf("%d\n",abs(x1-2)+abs(y1-2));
    return 0;
}
