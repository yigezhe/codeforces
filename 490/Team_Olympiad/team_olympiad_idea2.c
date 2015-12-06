//提示可以用sort，我想到了解决办法
//不用sort也可以！
/*interface*/
void print(int *,int );
void sort(int *,int);
void bubble_sort(int *,int);
int min(int ,int ,int );

/*interface implementation*/
#include<stdio.h>
int min(int a,int b,int c) {
    if(a<b) {
        if(a<c) {
            //a<b,a<c
            return a;
        } else {
            //a<b,a>=c
            return c;
        }
    } else {
        //a>=b
        if(c<b) {
            //a>=b,c<b
            return c;
        } else {
            //a>=b,c>=b
            return b;
        }
    }
}
void sort(int *data,int length) {
    bubble_sort(data,length);
}
void bubble_sort(int *data,int length) {
    int i,j;
    //最终把最小的放在第一位！
    for (i = 0; i < length; i++)
        //保证最后一位是最大的！
        for (j = 0; j < length-1; j++)
            if (data[j] > data[j + 1]) {
                int tmp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = tmp;
            }
}
void print(int *a,int n) {
    int i;
    for(i=0; i<n; i++) {
        printf(" %d",a[i]);
    }
    printf("\n");
}
/*client*/
#include<stdio.h>
#include<stdlib.h>
#define N 5000
int main() {
    int n;
    scanf("%d",&n);
    int t[N];
    int i;
    int count1=0;
    int count2=0;
    int count3=0;
    for(i=0; i<n; i++) {
        scanf("%d",&t[i]);
        if(t[i]==1) count1++;
        else if(t[i]==2) count2++;
        else if(t[i]==3) count3++;
    }
    int w=min(count1,count2,count3);
    printf("%d\n",w);
    //print(t,n);
    //sort(t,n);
    //print(t,n);
    while(1) {
        int find1=0;

        i=0;
        while(i<n) {
            if(t[i]==1) {
                find1=i+1;
                t[i]=0;
                break;
            }
            i++;
        }
        int find2=0;

        i=0;
        while(i<n) {
            if(t[i]==2) {
                find2=i+1;
                t[i]=0;
                break;
            }
            i++;
        }
        int find3=0;
        i=0;
        while(i<n) {
            if(t[i]==3) {
                find3=i+1;
                t[i]=0;
                break;
            }
            i++;
        }
        if(!(find1&&find2&&find3)) {
            break;
        } else {
            printf("%d %d %d\n",find1,find2,find3);
        }
    }
    return 0;
}
