//离结果已经很近了！
//就是上一个必须利用下一个的成果！
//最好的办法还是在前一个计算结果的基础上加一下，减一下，这样工作量才不会太大，我觉得重新统计一下工作量还是很大！
//应该先改变后统计！
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
    //printf("%s\n",s);
    //print(dot_s,n);
    int res=0;
    int j=n-1;
    //这个统计出了问题？
    while(j>=0) {
        //printf("while(%d>=0)\n",j);
        if(dot_s[j]>1) {
            res+=(dot_s[j]-1);
            j-=dot_s[j];
        } else {
            j--;
        }
    }
    //printf("first res = %d\n",res);


    for(i=0; i<m; i++) {
        int where;
        char which;
        scanf("%d %c",&where,&which);
//print(dot_s,n);
        //printf("%d %c\n",where,which);
        //做出一个更新！
        int cur=where-1;
        if(which=='.' && dot_s[cur]==0) {
            //当前位置不是.
            if(cur-1>=0 && cur+1<n) {
                if(dot_s[cur-1]==0 && dot_s[cur+1]==0) {
                    //res不变！
                } else if(dot_s[cur-1]==0 && dot_s[cur+1]>0) {
                    res+=1;
                } else if(dot_s[cur-1]>0 && dot_s[cur+1]==0) {
                    res+=1;
                } else if(dot_s[cur-1]>0 && dot_s[cur+1]>0) {
                    res+=2;
                } else {
                    //res不变！
                }
            } else if(cur-1<0 && cur+1<n) {
                if(dot_s[cur+1]==0) {
                    //res不变
                } else {
                    res+=1;
                }

            } else if(cur-1>=0 && cur+1<n) {
                if(dot_s[cur-1]==0) {
                    //res不变
                } else {
                    res+=1;
                }
            } else if(cur-1<0 && cur+1>=n) {
                //不用处理了！
            }
        } else if(which!='.' && dot_s[cur]>0) {
            //当前位置是.
            //h........h
            //cur在点号的两头都是减一，在中间要减二！
            if(dot_s[cur]==1) {
                //h.h的情况
                if (cur+1>=n) {
                    //res 不变！
                    //h.的情况
                } else if (dot_s[cur+1]==0) {
                    //res 不变！
                    //h..
                } else if(dot_s[cur+1]>0) {
                    res-=1;
                }
            } else if(dot_s[cur]>1) {
                //h..h的情况
                if (cur+1>=n) {
                    res-=1;
                    //h..的情况
                } else if (dot_s[cur+1]==0) {
                    res-=1;
                    //h...h的情况
                } else if(dot_s[cur+1]>0) {
                    res-=2;
                }
            }
        } else {
            //res不变！
        }
        printf("%d\n",res);
        if(which=='.') {
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


//print(dot_s,n);
    }
    return 0;
}
