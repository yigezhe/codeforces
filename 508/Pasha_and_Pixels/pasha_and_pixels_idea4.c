//irrelevant杂乱无章！
//因为玩游戏而头发乱了！
//总是说点题外话！
//类似迷宫问题！
//应该是一个直接运用bfs的问题！
//这里的问题是，如果有一个四个格子的小正方形都是黑色，那么pasha就输了！
//(i,i+1) (j,j+1)构成一个方格应该查找(n-1)*(m-1)次，由于n，m最大1000，所以问题的复杂度是10^6级别，可以在1秒内完成！
//这里看来出现在方格上的所有点，我都要统计？
//不只一个四方格！
//先处理一个！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 1000+1
#define K 100000+1
int n,m,k;
int pixel[N][N];
struct point {
    int x,y;
};
struct point moves[K];

void print_field() {
    int i,j;
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            if(pixel[i][j]==1) printf("#");
            else printf(".");
        }
        printf("\n");
    }
}

//这里问的是在哪一步的时候，4方格出现了！
//还是题意没有理解清楚！

struct point search_field() {
    int i,j;
    struct point p;
    //把这个查找降到n级别的查找！
    for(i=0; i<n-1; i++) {
        for(j=0; j<m-1; j++) {
            if(pixel[i][j]==1 && pixel[i][j+1]==1 && pixel[i+1][j]==1 && pixel[i+1][j+1]==1) {
                p.x=i;
                p.y=j;
                return p;
            }
        }
    }
    p.x=-1;
    p.y=-1;
    return p;

}
int main() {
    scanf("%d%d%d",&n,&m,&k);
    int i,j;
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            pixel[i][j]=0;
        }
    }
    //这样的话，问题的复杂度超了！
    //k*n*m=1000*1000*100000
    int find=0;
    for(i=0; i<k; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        pixel[x-1][y-1]=1;
	//加入一个点，我们只看它周围的8个点，
	//而不是全盘查找！
        struct point p=search_field();
        if(p.x==-1 && p.y==-1) {
            //现在还没有形成四方格！
        } else {
            //找到了一个四方格子！
            printf("%d\n",i+1);
	    find=1;
	    break;
        }
    }
    if(!find) printf("0\n");
    return 0;
}
