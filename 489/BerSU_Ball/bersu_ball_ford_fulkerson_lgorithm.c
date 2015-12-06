//第一步把图建立好！
#include<stdio.h>
#define MAX 210
int main() {
    //添加一个source和sink
    //source=0
    //sink=1
    //boy=2~2+n-1
    //girl=2+n~2+n+m-1
    int i,j;
    int n;
    scanf("%d",&n);
    int vertice[MAX];
    vertice[0]=-MAX;
    vertice[1]=-MAX;
    for(i=2; i<2+n; i++) {
        scanf("%d",&vertice[i]);
    }
    int m;
    scanf("%d",&m);
    for(i=2+n; i<2+m+n; i++) {
        scanf("%d",&vertice[i]);
    }
    int edge[MAX][MAX];
    //创建这个图，用矩阵来表示他们的关系！
    for(i=0; i<MAX; i++) {
        for(j=0; j<MAX; j++) {
            edge[i][j]=0;
        }
    }

    //出发点与所有男孩相连
    for(j=2; j<n+2; j++) {
        edge[0][j]=1;
    }
    //所有女孩与终点相连
    for(i=n+2; i<m+n+2; i++) {
        edge[i][1]=1;
    }

//女孩和男孩根据舞技相差是否为一来相连
    for(i=2; i<n+2; i++) {
        for(j=n+2; j<m+n+2; j++) {
            if(vertice[i]-vertice[j]>=-1 && vertice[i]-vertice[j]<=1) {
                edge[i][j]=1;
            }
        }

    }
    /*
    for(i=0; i<m+n+2; i++) {
        printf("%d=%d\n",i,vertice[i]);
    }
    for(i=0; i<m+n+2; i++) {
        for(j=0; j<m+n+2; j++) {
            if(edge[i][j]==1) {
                printf("(%d,%d)",i,j);
            }
        }
        printf("\n");
    }
    */

    int tmp_edge[MAX][MAX];
    for(i=0; i<MAX; i++) {
        for(j=0; j<MAX; j++) {
            tmp_edge[i][j]=edge[i][j];
        }
    }
    /*
    printf("tmp:\n");
    for(i=0; i<m+n+2; i++) {
        for(j=0; j<m+n+2; j++) {
            if(tmp_edge[i][j]==1) {
                printf("(%d,%d)",i,j);
            }
        }
        printf("\n");
    }
    */

    int path[MAX];
    int max_flow=0;
    while(1) {
        //找到一个路径，没找到就停止循环！
        int visited[MAX];
        for(i=0; i<MAX; i++) {
            visited[i]=0;
        }
        int queue[2*MAX];
        int start=0;
        int end=0;
        queue[end]=0;
        visited[0]=1;
        end++;
        while(start<end) {
            i=queue[start];
            start++;
            //找到目标就退出，而不是找到底
            //if(i==1) break;
            //printf("i=%d",i);
            //printf("start=%d,end=%d",start,end);
            for(j=0; j<m+n+2; j++) {
                if(!visited[j] && tmp_edge[i][j]>0) {
                    queue[end]=j;
                    end++;
                    //我参考的代码用的是反向，我觉得正向更合适！
                    //正向好像无法建立路径，这是什么情况！
                    path[j]=i;
                    //printf("(%d,%d)",i,j);
                    visited[j]=1;
                }
            }
            //printf("\n");
        }
        //如果没有到达终点就退出！
        if (!visited[1]) break;
        int path_flow=MAX;
        for(j=1; j!=0; j=path[j]) {
            //printf("%d-",j);
            i=path[j];
            if(tmp_edge[i][j]<path_flow) {
                path_flow=tmp_edge[i][j];
            }
        }

        /*
        for(j=1; j!=0; j=path[j]) {
            printf("%d-",j);
        }
        */
        //printf("\n");
        for(j=1; j!=0; j=path[j]) {
            i=path[j];
            tmp_edge[i][j]-=path_flow;
            tmp_edge[j][i]+=path_flow;
        }
        max_flow+=path_flow;
    }

    printf("%d\n",max_flow);
    return 0;
}
