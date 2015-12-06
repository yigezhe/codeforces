//提示可以用sort，我想到了解决办法
/*interface*/
void print(int *,int );
void sort(int *,int);
void bubble_sort(int *,int);
/*interface implementation*/
#include<stdio.h>
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
    for(i=0; i<n; i++) {
        scanf("%d",&t[i]);
    }
    print(t,n);
    sort(t,n);
    print(t,n);
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
        }else {
		printf("%d %d %d\n",find1,find2,find3);
	}
    }
    return 0;
}
