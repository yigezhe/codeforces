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
int n,m,k;
int pixel[N][N];
struct point {
    int x,y;
};

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

/*
(p.x-1, p.y-1) (p.x-1, p.y) (p.x-1, p.y+1)
(p.x, p.y-1)   (p.x, p.y)   (p.x, p.y+1)
(p.x+1, p.y-1) (p.x+1, p.y) (p.x+1, p.y+1)
*/
int search_8_direction(struct point p) {
    //围绕一个点可以构建四个方格！
    int find=0;
    //右上角的方格！
    if((p.x-1>=0 && p.y+1<m)
            && (pixel[p.x-1][p.y]==1)
            &&(pixel[p.x-1][p.y+1]==1)
            &&(pixel[p.x][p.y+1]==1)) {
        find=1;
    }
    //右下角的方格！
    //这个题目中，一点小小的数组界线错误都不能出现！
    else if((p.x+1<n && p.y+1<m)
            && (pixel[p.x][p.y+1]==1)
            &&(pixel[p.x+1][p.y]==1)
            &&(pixel[p.x+1][p.y+1]==1)) {
        find=1;
    }
    //左上角的方格！
    //这是一个a类问题，我都把它写得如此复杂，不过这里
    //提出想法，验证想法最重要，而不是因为其他原因而去否定它！
    else if((p.x-1>=0 && p.y-1>=0)
            && (pixel[p.x-1][p.y-1]==1)
            &&(pixel[p.x-1][p.y]==1)
            &&(pixel[p.x][p.y-1]==1)) {
        find=1;
    }
    //左下角的方格！
    else if((p.x+1<n && p.y-1>=0)
            && (pixel[p.x][p.y-1]==1)
            &&(pixel[p.x+1][p.y-1]==1)
            &&(pixel[p.x+1][p.y]==1)) {
        find=1;
    }
    return find;
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
        struct point p;
        p.x=x-1;
        p.y=y-1;
        if(search_8_direction(p)==1) {
            printf("%d\n",i+1);
            find=1;
            break;
        }
    }
    if(!find) printf("0\n");
    return 0;
}
