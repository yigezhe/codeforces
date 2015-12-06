#include<stdio.h>
#define MAX 210
int main() {
    //添加一个source和sink
    //source=0
    //sink=1
    //boy=2~2+n-1
    //girl=2+n~2+n+m-1
    int n;
    scanf("%d",&n);

    int i,j;
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
    for(i=0; i<m+n+2; i++) {
        for(j=0; j<m+n+2; j++) {
            edge[i][j]=0;
        }
    }

    //出发点与所有男孩相连
    for(i=2; i<n+2; i++) {
        edge[0][i]=1;
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


    /*
    int visited[MAX_N][MAX_M];
    for(i=0; i<MAX_N; i++) {
        for(j=0; j<MAX_M; j++) {
            visited[i][j]=0;
        }
    }
    //找到起始点
    int is_pairs[MAX_N][MAX_M];
    //把等级相差为一的舞伴全部找出来！
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            if (a[i]-b[j]>=-1 && a[i]-b[j]<=1) {
                is_pairs[i][j]=1;
            } else {
                is_pairs[i][j]=0;
            }
        }
    }

    //找到需要查找的第一个值！
    int find=0;
    struct pairs start_state;

    for(i=0; i<n && !find; i++) {
        for(j=0; j<m && !find; j++) {
            if (!visited[i][j] && is_pairs[i][j]) {
                find=1;
                start_state.boy=i;
                start_state.girl=j;
                start_state.deep=1;
            }
        }
    }

    printf("%d,%d,%d\n",start_state.boy,start_state.girl,start_state.deep);
    queue[end].boy=start_state.boy;
    queue[end].girl=start_state.girl;
    queue[end].deep=start_state.deep;
    visited[queue[end].boy][queue[end].girl]=1;
    end++;
    //方法是，大胆把自己的想法写出来，
    //大胆边走边看！
    int visited_girl[MAX_M];
    for(i=0; i<MAX_M; i++) {
        visited_girl[i]=0;
    }
    while(start<end) {
        struct pairs top;
        top.boy=queue[start].boy;
        top.girl=queue[start].girl;
        top.deep=queue[start].deep;
        printf("\n(%d,%d)-%d->",top.boy,top.girl,top.deep);
        start++;

        visited_girl[top.girl]=1;
        for(j=0; j<m; j++) {
            printf("(%d,%d)=%d&&%d&&%d~",top.boy+1,j,
                   is_pairs[top.boy+1][j],!visited[top.boy+1][j],!visited_girl[j]);
            if (is_pairs[top.boy+1][j] && !visited[top.boy+1][j] && !visited_girl[j]) {
                struct pairs new_pair;
                new_pair.boy=top.boy+1;
                new_pair.girl=j;
                new_pair.deep=top.deep+1;
                queue[end].boy=new_pair.boy;
                queue[end].girl=new_pair.girl;
                queue[end].deep=new_pair.deep;
                visited[queue[end].boy][queue[end].girl]=1;
                end++;
                printf("(%d,%d)-%d\n",new_pair.boy,new_pair.girl,new_pair.deep);
            }
        }
        visited_girl[top.girl]=0;
        printf("\n");
    }
    */
    return 0;
}
