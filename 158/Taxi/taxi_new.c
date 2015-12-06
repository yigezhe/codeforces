#include<stdio.h>
#define N 100000+5
int main() {
    int n;
    scanf("%d",&n);
    int s[N];
    int i,j;
    int count=0;
    for(i=0; i<n; i++) {
        scanf("%d",&s[i]);
    }

    for(i=0; i<n; i++) {
        for(j=i+1; j<n; j++) {
            if(s[j]>s[i]) {
                int tmp=s[i];
                s[i]=s[j];
                s[j]=tmp;
            }
        }
    }
    int find3=0;
    int find2=0;
    int find1=0;
    for(i=0; i<n; i++) {
        if(s[i]==4) {
            s[i]=0;
            count++;
        } else if(s[i]==3) {
            find3=1;
        } else if(s[i]==2) {
            find2=1;
        } else if(s[i]==1) {
            find1=1;
        }

    }
    //把所有的1，3对取消！
    if(find3 && find1) {
        for(i=0; i<n; i++) {
            for(j=i+1; j<n; j++) {
                if(s[i]!=0 && s[j]!=0) {
                    if(s[i]==3 && s[j]==1) {
                        s[i]=0;
                        s[j]=0;
                        count++;
                    }
                }
            }
        }
    }
    //剩下的3已经无法配对了！
    if(find3) {
        for(i=0; i<n; i++) {
            if(s[i]!=0 && s[i]==3) {
                s[i]=0;
                count++;
            }

        }
    }

    //把所有的2，2对取消！
    if(find2) {
        for(i=0; i<n; i++) {
            for(j=i+1; j<n; j++) {
                if(s[i]!=0 && s[j]!=0) {
                    if(s[i]==2 && s[j]==2) {
                        s[i]=0;
                        s[j]=0;
                        count++;
                    }
                }
            }
        }
    }
    //把所有的1,1，2对取消！
    int k;
    if(find2 && find1) {
        for(i=0; i<n; i++) {
            for(j=i+1; j<n; j++) {
                for(k=j+1; k<n; k++) {
                    if(s[i]!=0 && s[j]!=0 && s[k]!=0) {
                        if(s[i]==2 && s[j]==1 && s[k]==1) {
                            s[i]=0;
                            s[j]=0;
                            s[k]=0;
                            count++;
                        }
                    }
                }
            }
        }
    }

    //把2，1配对
    if(find2 && find1) {
        for(i=0; i<n; i++) {
            for(j=i+1; j<n; j++) {
                if(s[i]!=0 && s[j]!=0) {
                    if(s[i]==2 && s[j]==1) {
                        s[i]=0;
                        s[j]=0;
                        count++;
                    }
                }
            }
        }
    }

//剩下的2已经无法配对了！
    if(find2) {
        for(i=0; i<n; i++) {
            if(s[i]!=0 && s[i]==2) {
                s[i]=0;
                count++;
            }

        }
    }

        int times=0;
    if(find1) {
        for(i=0; i<n; i++) {
            if(s[i]==1) {
                times++;
            }
        }
    }
    count+=times/4;
    if(times%4!=0){
	    count++;
    }

    printf("%d\n",count);
    return 0;
}
