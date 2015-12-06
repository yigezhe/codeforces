/*interface*/
#include<stdio.h>
#define N 300+1
/*interface implementation*/
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    int a[N];
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    int start;
    int end;
    int find_start;
    int find_end;
    int pos=0;

    while(1) {
        find_start=0;
        start=0;
        for(i=start; i<n; i++) {
            if(a[i]>0) {
                start=i;
                find_start=1;
                break;
            }
        }
        find_end=0;
        for(i=start+1; i<n; i++) {
            if(a[i]>0) {
                end=i;
                find_end=1;
            } else {
                break;
            }
        }
        //先处理一下就回来！
        //printf("\n%d - %d\n",start,end);
        //printf("\n%d - %d\n",find_start,find_end);
        if(find_start) {
            if(find_end) {
                //先走到start
		//printf("\nfrom %d to %d\n",pos,start);
                for(i=pos; i<start; i++) {
                    printf("R");
                }
		//printf("\n");
                for(i=start; i<end; i++) {
                    printf("P");
                    a[i]--;
                    printf("R");
                }
                printf("P");//有p就有减！
                a[end]--;
                //不要回到开头，而是回到第一个有元素的地方！
                int back_to;
                for(i=start; i<=end; i++) {
                    if(a[i]>0) {
                        back_to=i;
			break;
                    }
                }
		//printf("\nback to %d\n",back_to);
                for(i=end; i>back_to; i--) {
                    printf("L");
                }
                pos=back_to;
            } else {
                //先走到start
                if(start!=0) {
                    for(i=pos; i<start; i++) {
                        printf("R");
                    }
                }

                //这里要处理三种情况
                if(start==0) {
                    //10
                    while(a[start]>0) {
                        a[start]--;
                        printf("RLP");
                    }
                    pos=start;

                } else if(start==n-1) {
                    //01
                    while(a[start]>0) {
                        a[start]--;
                        printf("LRP");
                    }
                    pos=start;
                } else {
                    //010

                    while(a[start]>0) {
                        a[start]--;
                        printf("RLP");
                    }
                    pos=start;

                }
            }
        } else {
            break;
        }
    }
    //整个代码结构非常好！
    printf("\n");
    return 0;
}
