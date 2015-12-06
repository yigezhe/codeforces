//andreid 是不是写错了，应该是andrewid
//想法二，就是去模拟整个操作过程，内存上是允许的2*10^5就是200KiB
//而且消的方式多种多样，我可以先采用从头消！
//实现想法二的目的就是考查自己的能力！
//确实实现过程中状况百出，这个训练是必须的！
//这个算法的最坏时间应该是n^2这样整个问题就是4*10^10的问题，一秒解决有问题！
//11111111111100000000000
//找N/2，进行N/2次改变
//下一次就是N-2/2次，改变N-2/2次！
//N,N-2,N-4,N-6,...,2,N-2*N/2
//N/2*N-2*(N/2)(N/2-1)/2
//N^2/2-(N^2/4-N/2)
//就是N^2级别的算法！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 200000+1
int n;
char string[N];
int operation() {
    int i,j;
    for(i=0; i<n-1; i++) {
        if(string[i]!=string[i+1]) {
            break;
        }
    }
    for(j=i; j<n-2; j++) {
        string[j]=string[j+2];
    }

    //都走了一遍，什么都没有改变！
    if(i==n-1) {
        return 0;
    } else {
        n=n-2;
	//剩下的数量太少，已经无法改变就提前结束！
        if(n<2) return 0;
        else return 1;
    }
}
void print(char a[],int size) {
    int i;
    for(i=0; i<size; i++) {
        printf("%c",a[i]);
    }
    printf("\n");
}
int main() {
    scanf("%d",&n);
    scanf("%s",string);
    while(1) {
        //print(string,n);
        int res=operation();
        //print(string,n);
        //printf("----------\n");

        if(res==0) break;
    }
    printf("%d\n",n);
    return 0;
}
