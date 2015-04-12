/*Test: #59, time: 3000 ms., memory: 1552 KB, exit code: -1, checker exit code: 0, verdict: TIME_LIMIT_EXCEEDED
Input
100000
1 1 1 1 1 1 1 1 1 
我需要更好的sort！
*/
//进入办法二，不用sort！
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
                /*
                        for(j=start; j<end; j++) {
                            printf(" %d",queue[j]);
                        }
                        printf("\n");
                */
                int top=queue[start];
                start++;
                sum=sum-s[top];
		int max_sj=0;
		int max_j=0;
                for(j=0; j<n; j++) {
                    if(!visited[j] && s[j]<=sum) {
                        //printf("j=%d,sum=%d ",j,sum);
			    if(s[j]>max_sj) {
				    max_j=j;
				    max_sj=s[j];
			    }
                    }
                }
		if (max_sj==0) {
//说明没有找到就退出！
			break;
		} else {
			// 把最大的放入！
                        printf("max j=%d,sum=%d ",max_j,sum);
                        queue[end]=max_j;
                        visited[queue[end]]=1;
                        sum=sum-s[max_j];
                        end++;
		}

            }
            printf("\n----------\n");
        }
    }
    printf("%d\n",taxis);
    return 0;
}
