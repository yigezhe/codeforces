/*Test: #59, time: 3000 ms., memory: 1552 KB, exit code: -1, checker exit code: 0, verdict: TIME_LIMIT_EXCEEDED
Input
100000
1 1 1 1 1 1 1 1 1 
我需要更好的sort！
*/
//办法一就是先sort一下，可以在不改变现有代码的情况下，获得正确结果！
#include<stdio.h>
#include<stdio.h>
#define MAX_N 100000
//我的想法是还是用bfs处理！
int main() {
    int n;
    scanf("%d",&n);
    int i,j;
    int s[MAX_N];
    for(i=0; i<n; i++) {
        scanf("%d",&s[i]);
    }
    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(s[i]<s[j]) {
                int tmp=s[i];
                s[i]=s[j];
                s[j]=tmp;
            }
        }
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
            //printf("%d->",i);
            taxis++;
            queue[end]=i;
            visited[queue[end]]=1;
            end++;
            int sum=4;
            while(start<end) {
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
                        //printf("j=%d,sum=%d ",j,sum);
                        queue[end]=j;
                        visited[queue[end]]=1;
                        sum=sum-s[j];
                        end++;
                    }
                }
            }
            //printf("\n----------\n");
        }
    }
    printf("%d\n",taxis);
    return 0;
}
