/*这里的代码对
  5
  1 2 4 3 2
  得到的结果是4
  最优的结果是3
 */
#include<stdio.h>
#include<stdio.h>
#define MAX_N 100000
//我的想法是还是用bfs处理！
int main() {
    int n;
    scanf("%d",&n);
    int i;
    int s[MAX_N];
    for(i=0; i<n; i++) {
        scanf("%d",&s[i]);
    }
    int visited[MAX_N];
    for(i=0; i<MAX_N; i++) {
        visited[i]=0;
    }

    int queue[2*MAX_N];
    int start=0;
    int end=0;
    int taxis=0;
    for(i=0; i<n; i++) {
        if (!visited[i]) {
            printf("%d->",i);
            taxis++;
            queue[end]=i;
            visited[queue[end]]=1;
            end++;
            int sum=4;
            while(start<end) {
                int j;
                /*
                        for(j=start; j<end; j++) {
                            printf(" %d",queue[j]);
                        }
                        printf("\n");
                */
                int top=queue[start];
                start++;
                sum=sum-s[top];
                for(j=0; j<n; j++) {
                    if(!visited[j] && s[j]<=sum) {
                        printf("j=%d,sum=%d ",j,sum);
                        queue[end]=j;
                        visited[queue[end]]=1;
                        sum=sum-s[j];
                        end++;
                    }
                }
            }
            printf("\n----------\n");
        }
    }
    printf("%d\n",taxis);
    return 0;
}
