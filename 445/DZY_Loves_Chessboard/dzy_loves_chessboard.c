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
        int h;
        int w;
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
    queue[end].h=0;
    queue[end].w=0;
    visited[queue[end].h][queue[end].w]=1;
    new_chess[queue[end].h][queue[end].w]='B';
    end++;


    while(start<end) {
        struct cell top;
        top.h=queue[start].h;
        top.w=queue[start].w;
        //printf("(%d,%d)-%c->",top.h,top.w,new_chess[top.h][top.w]);
        printf("\n");
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            printf("%c",new_chess[i][j]);
        }
        printf("\n");
    }

        start++;

        //只需处理两个方向

        if (top.w+1<m && !visited[top.h][top.w+1]) {
            queue[end].h=top.h;
            queue[end].w=top.w+1;
            visited[queue[end].h][queue[end].w]=1;
            if(new_chess[queue[end].h][queue[end].w]=='.') {
                if(new_chess[top.h][top.w]=='B') {
                    new_chess[queue[end].h][queue[end].w]='W';
                } else if(new_chess[top.h][top.w]=='W') {
                    new_chess[queue[end].h][queue[end].w]='B';
                } else {
                    //这里的情况必须讨论一下
                    //这里new_chess[top.h][top.w]=='-') {
                    if (queue[end].w-1>=0) {
                        if(new_chess[queue[end].h][queue[end].w-1]=='B')
                            new_chess[queue[end].h][queue[end].w]='W';
                        else if(new_chess[queue[end].h][queue[end].w-1]=='W')
                            new_chess[queue[end].h][queue[end].w]='B';
                        else
                            new_chess[queue[end].h][queue[end].w]='B';
                    } else {
                        new_chess[queue[end].h][queue[end].w]='B';
                    }
                }
            }

            //printf("(%d,%d)-%c->",queue[end].h,queue[end].w,new_chess[queue[end].h][queue[end].w]);
            end++;
        }
        if (top.h+1<n && !visited[top.h+1][top.w]) {
            queue[end].h=top.h+1;
            queue[end].w=top.w;
            visited[queue[end].h][queue[end].w]=1;
            if(new_chess[queue[end].h][queue[end].w]=='.') {
                if(new_chess[top.h][top.w]=='B') {
                    new_chess[queue[end].h][queue[end].w]='W';
                } else if(new_chess[top.h][top.w]=='W') {
                    new_chess[queue[end].h][queue[end].w]='B';
                } else {
                    //这里的情况必须讨论一下
                    //这里new_chess[top.h][top.w]=='-') {
                    if (queue[end].h-1>=0) {
                        if(new_chess[queue[end].h-1][queue[end].w]=='B')
                            new_chess[queue[end].h][queue[end].w]='W';
                        else if(new_chess[queue[end].h-1][queue[end].w]=='W')
                            new_chess[queue[end].h][queue[end].w]='B';
                        else
                            new_chess[queue[end].h][queue[end].w]='B';
                    } else {
                        new_chess[queue[end].h][queue[end].w]='B';
                    }
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
