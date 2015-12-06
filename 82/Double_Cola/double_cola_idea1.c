#include<stdio.h>
#include<string.h>
//#include<math.h>
#define N 1000000000+5
int main() {
    int n;
    scanf("%d",&n);
    //1<=n<=10^9,n没有超过int的范围！
    //printf("%f\n",pow(2,31));
    char name[5][8];
    strcpy(name[0],"Sheldon");
    strcpy(name[1],"Leonard");
    strcpy(name[2],"Penny");
    strcpy(name[3],"Rajesh");
    strcpy(name[4],"Howard");
    printf("here\n");
    //把0，1，2，3，4放入队列而不是把这些名字放入队列，把名字放入队列太费时间！
    char queue[N];
    int end=0;
    queue[end]=0;
    end++;
    queue[end]=1;
    end++;
    queue[end]=2;
    end++;
    queue[end]=3;
    end++;
    queue[end]=4;
    end++;
    int i;
    for(i=0; i<n; i++) {
        int top=queue[0];
        if(i==n-1) {
            printf("%s\n",name[top]);
            return 0;
        }
        int j;
        for(j=0; j<end-1; j++) {
            queue[j]=queue[j+1];
        }
        end--;
        queue[end]=i;
        end++;
        queue[end]=i;
        end++;
    }

    return 0;
}
