//还是不成功，停止探索，先去学习其他问题，
//有时间再来看这个问题！我已经很成功了，加油何伟伟！
//程序的问题，出现了两个P的情况！
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
        //printf("\n%d - %d pos=%d\n",start,end,pos);
        //printf("\n%d - %d\n",find_start,find_end);
        if(find_start) {
            //先走到start
            //printf("\nfrom %d to %d\n",pos,start);
            for(i=pos; i<start; i++) {
                printf("R");
            }
	    pos=start;
            //printf("\n");
            if(!find_end) {
                //10
                if(start==0) {
                    while(a[start]>0) {
                        printf("RLP");
                        a[start]--;
                    }
		    pos=start;
                } else {
                    while(a[start]>0) {
                        printf("LRP");
                        a[start]--;
                    }
		    pos=start;
                }
		continue;
            }

            for(i=start; i<end; i++) {
                if(a[i]>0) {
                    printf("P");
                    a[i]--;
                }
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
            //回去的时候把连续的部分再处理一次。而不是空手而归！
            //我决定用少退一步的办法，解决不符合要求的移动的出现！
            //不然问题会更复杂一点，我需要区分两种情况！
            //这里还要看一下什么时候该退！
            //这里就是做一个小幅度的改动，大幅度的改进很容易破坏程序
            //让你重新组织程序结构！
            int need=0;
            for(i=end; i>back_to+1; i--) {
                need=1;
                printf("L");
                if(a[i-1]>0) {
                    printf("P");
                    a[i-1]--;
                }
            }
            if(need)printf("L");
            pos=back_to;//多退一位！
        } else {
            break;
        }
    }
//整个代码结构非常好！
    printf("\n");
    return 0;
}
