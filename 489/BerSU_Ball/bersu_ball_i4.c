//这里的想法是，如果一个舞者对被访问过了，那么那个女孩就不能再被访问了，我们可以把所有男孩对这个女孩都变为已经被访问过了！
//这个算法对测试用例子可以通过，我想看看上传后可以通过不！
//i4的想法是运用递归函数达到我想达到的！
#include<stdio.h>
#define MAX 100


int max_deep=0;
int is_pairs[MAX][MAX];
int visited_girl[MAX];
int n,m;
void dfs(int boy,int girl,int deep) {
	/*
	int i;
	for(i=0;i<=deep;i++) {
		printf(" ");
	}
	printf("dfs(%d,%d,%d)\n",boy,girl,deep);
	*/
    if (deep>max_deep) {
        max_deep=deep;
    }
    int j;
    for(j=0; j<m; j++) {
        if (is_pairs[boy+1][j] && !visited_girl[j]) {
            visited_girl[j]=1;
            dfs(boy+1,j,deep+1);
            visited_girl[j]=0;
        }
    }
}

int main() {
    scanf("%d",&n);

    int i,j;
    int a[MAX];
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    scanf("%d",&m);
    int b[MAX];
    for(i=0; i<m; i++) {
        scanf("%d",&b[i]);
    }
    for(j=0; j<MAX; j++) {
        visited_girl[j]=0;
    }

    //找到起始点
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
    for(i=0; i<n; i++) {
        for(j=0; j<m; j++) {
            if (is_pairs[i][j]) {
                // 再深度查找之前，所有的女孩都没有被访问过！
                int k;
                for(k=0; k<MAX; k++) {
                    visited_girl[k]=0;
                }
                visited_girl[j]=1;
                dfs(i,j,1);
            }
        }
    }

    printf("%d\n",max_deep);
    return 0;
}
