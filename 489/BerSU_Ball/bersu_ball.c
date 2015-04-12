#include<stdio.h>
#define MAX_N 100
#define MAX_M 100
int main() {
    int n;
    scanf("%d",&n);

    int i,j;
    int a[MAX_N];
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    int m;
    scanf("%d",&m);
    int b[MAX_M];
    for(i=0; i<m; i++) {
        scanf("%d",&b[i]);
    }
    struct pairs {
        int boy;
        int girl;
        int deep;
    };
    struct pairs queue[2*MAX_M*MAX_N];
    int start=0;
    int end=0;
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
    return 0;
}
