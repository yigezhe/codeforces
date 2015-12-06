#include<stdio.h>
#define N 9
#define M 2*N+1
int main() {
    int n;
    scanf("%d",&n);
    int m=2*n+1;
    //p代表组成手帕图案的二维数组！
    int p[M][M];
    int i,j;
    for(i=0; i<M; i++) {
        for(j=0; j<M; j++) {
            p[i][j]=-1;
        }
    }
    //pt代表一个点！
    struct pt {
        int x,y;
    };
    struct pt queue[M*M];
    int start=0;
    int end=0;
    queue[end].x=n;
    queue[end].y=n;
    p[n][n]=n;
    end++;
    while(start<end) {
        /*
        for(i=start; i<end; i++) {
            printf("(%d,%d)=%d",queue[i].x,queue[i].y,p[queue[i].x][queue[i].y]);
        }
        printf("\n");
        */

        struct pt t;
        t.x=queue[start].x;
        t.y=queue[start].y;
        start++;

        //如果当前节点的值为零，那么我们不用再向四个方向寻找！
        if(p[t.x][t.y]!=0) {
            //向四个方向扩展
            struct pt up;
            up.x=t.x-1;
            up.y=t.y;
            if(up.x>=0 && up.y<m && p[up.x][up.y]==-1) {
                queue[end].x=up.x;
                queue[end].y=up.y;
                p[up.x][up.y]=p[t.x][t.y]-1;
                end++;
            }
            struct pt down;
            down.x=t.x+1;
            down.y=t.y;
            if(down.x>=0 && down.y<m && p[down.x][down.y]==-1) {
                queue[end].x=down.x;
                queue[end].y=down.y;
                p[down.x][down.y]=p[t.x][t.y]-1;
                end++;
            }
            struct pt left;
            left.x=t.x;
            left.y=t.y-1;
            if(left.x>=0 && left.y<m && p[left.x][left.y]==-1) {
                queue[end].x=left.x;
                queue[end].y=left.y;
                p[left.x][left.y]=p[t.x][t.y]-1;
                end++;
            }
            struct pt right;
            right.x=t.x;
            right.y=t.y+1;
            if(right.x>=0 && right.y<m && p[right.x][right.y]==-1) {
                queue[end].x=right.x;
                queue[end].y=right.y;
                p[right.x][right.y]=p[t.x][t.y]-1;
                end++;
            }
        }
    }
    for(i=0; i<m; i++) {
        for(j=0; j<m-1; j++) {
            if(p[i][j]!=-1) {
                printf("%d ",p[i][j]);
            } else {
                printf("  ");
            }
        }
        if(p[i][m-1]!=-1) {
            printf("%d",p[i][m-1]);
        } else {
            printf(" ");
        }

        printf("\n");
    }

    return 0;
}
