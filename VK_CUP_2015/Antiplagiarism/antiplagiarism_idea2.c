#include<stdio.h>
#include<string.h>
#define N 100
#define M 100+5
int main() {
    int n;
    scanf("%d",&n);
    int i,j;
    char file_name[M][N];
    //获取文件名
    for(i=0; i<n; i++) {
        scanf("%s",file_name[i]);
    }
    for(i=0; i<n; i++) {
        printf("%s\n",file_name[i]);
    }
    //直接比较两个文件！
    int group[M][M];
    for(i=0; i<M; i++) {
        for(j=0; j<M; j++) {
            group[i][j]=-1;
        }
    }

    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            int is_diff=0;
	    FILE *ifp,*jfp;
	    char *mode="r";
	    ifp=fopen(file_name[i],mode);
	    if(ifp==NULL) {
		    fprintf(stderr,"无法打开文件i\n");
		    exit(1);
	    }
	    jfp=fopen(file_name[j],mode);
	    if(jfp==NULL) {
		    fprintf(stderr,"无法打开文件j\n");
		    exit(1);
	    }
	    int k=0;
	    while(k<100) {
		    char chi=fgetc(ifp);
		    char chj=fgetc(jfp);
		    if(chi!=chj) {
			    is_diff=1;
			    break;
		    }
	    }
	    fclose(ifp);
	    fclose(jfp);

            if(is_diff) {
                group[i][j]=0;
                group[j][i]=0;
            } else {
                group[i][j]=1;
                group[j][i]=1;
            }
        }
    }
    visited[M][M];
    for(i=0; i<n; i++) {
        for(j=0; j<n; j++) {
            visit[i][j]=0;
        }
    }
    while(1) {

        int find=-1;
        for(i=0; i<n; i++) {
            for(j=0; j<n; j++) {
                if(!visit[i][j]) {
                    find=i;
                }
            }
        }
        if (find==-1) {
            break;
        } else {

            int queue[2*M];
            int start=0;
            int end=0;
            queue[end]=find;
            visit[find]=1;
            end++;
	    int path[M];
            while(start<end) {
                int top=queue[start];
                start++;
                for(i=0; i<n; i++) {
                    if(group[i][top] && !visit[i]) {
                        queue[end]=i;
                        visit[i]=1;
			path[i]=top;
                        end++;
                    }
                }
            }
	    //统计路径长度，打印长度大于1的！
        }
    }
    //用图的办法找到其中相连的！
    return 0;
}
