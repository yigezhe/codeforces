//submit ok!
//把题意理解了，一起共同参加k次，而不是总共达到k次！
//想法三是，进行配对。
//0成长为3，需要3次比赛，则5不行，4不行，3不行，2可以。
//先从大到小排序，然后从第一个队员开始，从后往前找可以和他配对的队友！
/*interface*/
#include<stdio.h>
void sort(int *,int);
void insertion_sort(int *,int);
void print(int *,int);
/*interface implementation*/
void sort(int *data,int length) {
    insertion_sort(data,length);
}
void insertion_sort(int *data,int length) {
    //感觉作者写的有点复杂了！
    int i;
    for (i = 0; i < length; i++) {
        int j = i;
        //在i左边的比i大的元素
        //i=1,不会进入while循环！
        while (j > 0 && data[i] < data[j - 1])
            j--;
        int tmp = data[i];
        int k;
        //把比i大的元素都向右统一移动一位！
        for (k = i; k > j; k--)
            data[k] = data[k - 1];
        //把i放在比他大的最左边的那个元素的位置上！
        data[j] = tmp;
    }
}
void print(int *data,int length) {
    int i;
    for(i=0; i<length; i++) {
        printf(" %d",data[i]);
    }
    printf("\n");
}
/*client*/
#include<stdio.h>
#define N 2000
int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    int i;
    int y[N];
    for(i=0; i<n; i++) {
        scanf("%d",&y[i]);
    }
    //print(y,n);
    sort(y,n);
    //print(y,n);

    int team=0;
    //state纪录一个成员是不是已经参加了一个team！
    //0表示没有参加，1表示已经参加！
    int state[N];
    for(i=0; i<n; i++) {
        state[i]=0;
    }
    for(i=0; i<n; i++) {
        //print(state,n);
        //从in8分析还是要至少参加一次比赛，344的分配是通不过的。
        //244，234的分配是可以的！
	//第一个寻找队友的人，参加k次也不能超过5！
        if(state[i]==0 && y[i]+k<=5) {
            //从后往前找两个队友！
            int find3=0;
            int j1;
            for(j1=n-1; j1>=0; j1--) {
                if(state[j1]==0 && (k+y[j1])<=5) {
                    find3=1;
                    break;
                }
            }
            int find2=0;
            int j2;
            for(j2=j1-1; j2>=0; j2--) {
                if(state[j2]==0 && (k+y[j2])<=5) {
                    find2=1;
                    break;
                }
            }
            if(find3 && find2 && j2-1>=i) {
                team++;
                state[j1]=1;
                state[j2]=1;
                state[i]=1;
            }
        } else {
            break;
        }
    }
    printf("%d\n",team);

    return 0;
}
