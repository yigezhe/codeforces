//就是上一个必须利用下一个的成果！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 300000+1
int n,m;

void print(int *a,int size) {
    int i;
    for(i=0; i<size; i++) {
        printf("%d",a[i]);
    }
    printf("\n");

}
int main() {
    scanf("%d%d",&n,&m);
    char s[N];
    scanf("%s",s);
    //做一次统计处理！
    int dot_s[N];
    int dot=0;
    int i;
    //这个问题最好都线性处理，也就是选择n个时间可以完成的来处理！
    for(i=0; i<n; i++) {
        if(s[i]=='.') {
            dot++;
            dot_s[i]=dot;
        } else {
            dot=0;
        }
    }
    /*
    printf("%s\n",s);
    print(dot_s,n);
    */

    for(i=0; i<m; i++) {
        int where;
        char which;
        scanf("%d %c",&where,&which);
        //printf("%d %c\n",where,which);
        if(which=='.') {
            int cur=where-1;
            //当前位置不是.
            if(dot_s[cur]==0) {
                if(cur-1>=0 && dot_s[cur-1]>0) {
                    dot_s[cur]=dot_s[cur-1]+1;
                    if(cur+1<n && dot_s[cur+1]>0) {
                        int more=cur+1;
                        while(more<n && dot_s[more]>0) {
                            dot_s[more]+=dot_s[cur];
                            more++;
                        }
                    }
                } else {
                    dot_s[cur]=1;
                    if(cur+1<n && dot_s[cur+1]>0) {
                        int more=cur+1;
                        while(more<n && dot_s[more]>0) {
                            dot_s[more]+=dot_s[cur];
                            more++;
                        }
                    }

                }
            }
        } else {
            int cur=where-1;
            if(dot_s[cur]>0) {
                int more=cur+1;
                while(more<n && dot_s[more]>0) {
                    //printf("more = %d, dot_s[more]=%d\n",more,dot_s[more]);
                    dot_s[more]-=dot_s[cur];
                    more++;
                }
            }
            dot_s[cur]=0;
        }
	/*
        s[where-1]=which;
        printf("%s\n",s);
        print(dot_s,n);
	*/
        int res=0;
        int j=n-1;
        while(j>=0) {
		//printf("while(%d>=0)\n",j);
            if(dot_s[j]>0) {
                res+=(dot_s[j]-1);
                j-=dot_s[j];
            } else {
                j--;
            }
        }
        printf("%d\n",res);
    }
    return 0;
}
