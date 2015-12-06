
/*interface*/
#include<stdio.h>
#include<stdlib.h>
/*interface implementation*/
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    int i;
    int *cards=malloc((n+1)*sizeof(int));
    int n_state=1000000;
    int ns=0;
    int **state=malloc(n_state*sizeof(int*));
    if(state==NULL) {
        printf("分配内存失败！\n");
    }
    for(i=0; i<n_state; i++) {
        state[i]=malloc((n+1)*sizeof(int));
        if(state[i]==NULL) {
            printf("分配内存失败！\n");
        }

    }
    if(cards==NULL) {
        printf("分配内存失败\n");
    }
    int k1;
    scanf("%d",&k1);
    //printf("k1=%d\n",k1);
    for(i=0; i<k1; i++) {
        scanf("%d",&cards[i]);
    }
    int k2;
    scanf("%d",&k2);
    for(i=0; i<k2; i++) {
        scanf("%d",&cards[i+k1]);
    }
    cards[n]=k1;//我这里用一个数组记录了所有的信息，cards[n]表达的就是第二个选手的起始牌的位置！

    int fights=0;
    while(1) {

	    /*
        printf("compare %d %d\n",cards[0],cards[cards[n]]);
        for(i=0; i<=n; i++) {
            printf(" %d",cards[i]);
        }
        printf("\n");
	*/

        if(cards[n]==0) {
            printf("%d %d\n",fights,2);
            break;
        } else if(cards[n]==n) {
            printf("%d %d\n",fights,1);
            break;
        } else {
            int j,k;
            int find=0;
            for(j=0; j<ns; j++) {
                int is_same=1;
                for(k=0; k<=n; k++) {
                    if(cards[k]!=state[j][k]) {
                        is_same=0;
                    }
                }
                if(is_same) {
                    find=1;
                    break;
                }
            }

            //find same state we will exit!
            if(find) {
                printf("-1\n");
                break;
            } else {
                //record state;
                for(k=0; k<=n; k++) {
                    state[ns][k]=cards[k];
                }
                ns++;
                if(ns>=n_state) {
                    printf("我申请的空间不够用了！\n");
                }
                //fight one time;
                if(cards[0]>cards[cards[n]]) {
                    //6543213
                    //5436214
                    int tmp1=cards[0];
                    for(k=0; k<cards[n]; k++) {
                        cards[k]=cards[k+1];
                    }
                    cards[cards[n]]=tmp1;
                    cards[n]=cards[n]+1;
                } else if(cards[0]<cards[cards[n]]) {
                    //1234563
                    //2356132
                    int tmp1=cards[0];
                    int tmp2=cards[cards[n]];
                    for(k=0; k<cards[n]-1; k++) {
                        cards[k]=cards[k+1];
                    }
                    //k+1=cards[n]-1
                    //k=cards[n]-2
                    //k<cards[n]-1
                    for(k=cards[n]-1; k<=n-2; k++) {
                        cards[k]=cards[k+2];
                    }
                    cards[n-2]=tmp1;
                    cards[n-1]=tmp2;
                    cards[n]=cards[n]-1;
                }
                fights++;
            }
        }
	/*
        printf("after fight is ....\n");

        for(i=0; i<=n; i++) {
            printf(" %d",cards[i]);
        }
        printf("\n");
	printf("----------\n");
	*/

    }
    free(cards);
    for(i=0; i<n_state; i++) {
        free(state[i]);
    }
    free(state);
    return 0;
}
