#include<stdio.h>
#define MAX 200
int main() {
    int n,m;
    scanf("%d%d",&n,&m);
    char chess[MAX][MAX];
    int i,j;
    for(i=0; i<n; i++) {
        scanf("%s",chess[i]);
    }

    struct cell {
        int x;
        int y;
    };
    struct cell queue[2*MAX*MAX];
    int start=0;
    int end=0;

    char new_chess[MAX][MAX];
    int visited[MAX][MAX];
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            new_chess[i][j]=chess[i][j];
            visited[i][j]=0;
        }
    }

    //我们认为全部是连通的！
    queue[end].x=0;
    queue[end].y=0;
    visited[queue[end].x][queue[end].y]=1;
    new_chess[queue[end].x][queue[end].y]='B';
    end++;


    while(start<end) {
        struct cell top;
        top.x=queue[start].x;
        top.y=queue[start].y;
	//printf("(%d,%d)-%c->",top.x,top.y,new_chess[top.x][top.y]);
        start++;

        //只需处理两个方向

        if (top.y+1<m && !visited[top.x][top.y+1]) {
            queue[end].x=top.x;
            queue[end].y=top.y+1;
            visited[queue[end].x][queue[end].y]=1;
            if(new_chess[queue[end].x][queue[end].y]!='-') {
                if(new_chess[top.x][top.y]=='B') {
                    new_chess[queue[end].x][queue[end].y]='W';
                } else if(new_chess[top.x][top.y]=='W') {
                    new_chess[queue[end].x][queue[end].y]='B';
                } else {
                    new_chess[queue[end].x][queue[end].y]='B';
                }
            }

		//printf("(%d,%d)-%c->",queue[end].x,queue[end].y,new_chess[queue[end].x][queue[end].y]);
            end++;
        }
        if (top.x+1<n && !visited[top.x+1][top.y]) {
            queue[end].x=top.x+1;
            queue[end].y=top.y;
            visited[queue[end].x][queue[end].y]=1;
            if(new_chess[queue[end].x][queue[end].y]!='-') {
                if(new_chess[top.x][top.y]=='B') {
                    new_chess[queue[end].x][queue[end].y]='W';
                } else if(new_chess[top.x][top.y]=='W') {
                    new_chess[queue[end].x][queue[end].y]='B';
                } else {
                    new_chess[queue[end].x][queue[end].y]='B';
                }
            }
            end++;
        }
	//printf("\n");
    }
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            printf("%c",new_chess[i][j]);
        }
	printf("\n");
    }

    return 0;
}
