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
int count_field() {
    int i,j;
    int counter=0;
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            if(pixel[i][j]==1) counter++;
        }
    }
    return counter;
}
int count_22square_moves(struct point square) {
    int i;
    int counter=0;
    for(i=0; i<k; i++) {
        if(moves[i].x==square.x && moves[i].y==square.y) counter++;
        if(moves[i].x==square.x && moves[i].y==square.y+1) counter++;
        if(moves[i].x==square.x+1 && moves[i].y==square.y) counter++;
        if(moves[i].x==square.x+1 && moves[i].y==square.y+1) counter++;
    }
    return counter;
}
//这里问的是在哪一步的时候，4方格出现了！
int count_move_square() {
    int i;
    int counter=0;
    for(i=0; i<k; i++) {
        //围绕一个点可以构建四个方格！
        if(pixel[moves[i].x][moves[i].y]==1) {
            //右上角的方格！
            if((moves[i].x-1>=0 && moves[i].y+1<m)
                    && (pixel[moves[i].x-1][moves[i].y]==1)
                    &&(pixel[moves[i].x-1][moves[i].y+1]==1)
                    &&(pixel[moves[i].x][moves[i].y+1]==1)) {
                counter++;
            }
            //右下角的方格！
	    else if((moves[i].x+1<m && moves[i].y+1<m)
                    && (pixel[moves[i].x][moves[i].y+1]==1)
                    &&(pixel[moves[i].x+1][moves[i].y]==1)
                    &&(pixel[moves[i].x+1][moves[i].y+1]==1)) {
                counter++;
            }
            //左上角的方格！
            //这是一个a类问题，我都把它写得如此复杂，不过这里
            //提出想法，验证想法最重要，而不是因为其他原因而去否定它！
	    else if((moves[i].x-1>=0 && moves[i].y-1>=0)
                    && (pixel[moves[i].x-1][moves[i].y-1]==1)
                    &&(pixel[moves[i].x-1][moves[i].y]==1)
                    &&(pixel[moves[i].x][moves[i].y-1]==1)) {
                counter++;
            }
            //左下角的方格！
	    else if((moves[i].x+1<m && moves[i].y-1>=0)
                    && (pixel[moves[i].x][moves[i].y-1]==1)
                    &&(pixel[moves[i].x+1][moves[i].y]==1)
                    &&(pixel[moves[i].x+1][moves[i].y-1]==1)) {
                counter++;
            }
        }
    }
    return counter;
}

struct point search_field() {
    int i,j;
    struct point p;
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
    for(i=0; i<k; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        moves[i].x=x-1;
        moves[i].y=y-1;
        pixel[x-1][y-1]=1;
    }
    print_field();
    struct point p=search_field();
    if(p.x==-1 && p.y==-1) {
        printf("0\n");
    } else {
        //printf("%d\n",count_field());
        //printf("%d\n",count_22square_moves(p));
        printf("%d\n",count_move_square());
    }
    return 0;
}
