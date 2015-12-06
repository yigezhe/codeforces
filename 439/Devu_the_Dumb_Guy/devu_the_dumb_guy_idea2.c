//dumb笨！
//n节课，每一章花费x小时
//第i节课，有ci章！
//先排序后学习！
//我必须选择最快的排序算法！
/*interface*/
#include<stdio.h>
#define N 100000+1

void print(int *,int);
void sort(long long *,int);
void mergeSort(long long *,int ,int ,int );
void partition(long long *,int ,int );

void sort(long long * merge,int n) {
    partition(merge,0,n-1);
}
void partition(long long *arr,int low,int high) {
//对这个代码，我还没有一个很详细的了解，
//但是我觉得我还是先用，等到我专门学习排序时，我再仔细研究它！
    int mid;

    if(low<high) {
        mid=(low+high)/2;
        partition(arr,low,mid);
        partition(arr,mid+1,high);
        mergeSort(arr,low,mid,high);
    }
}

void mergeSort(long long  *arr,int low,int mid,int high) {

    long long i,m,k,l,temp[N];

    l=low;
    i=low;
    m=mid+1;

    while((l<=mid)&&(m<=high)) {

        if(arr[l]<=arr[m]) {
            temp[i]=arr[l];
            l++;
        } else {
            temp[i]=arr[m];
            m++;
        }
        i++;
    }

    if(l>mid) {
        for(k=m; k<=high; k++) {
            temp[i]=arr[k];
            i++;
        }
    } else {
        for(k=l; k<=mid; k++) {
            temp[i]=arr[k];
            i++;
        }
    }

    for(k=low; k<=high; k++) {
        arr[k]=temp[k];
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
int main() {
    int n;
    long long x;
    scanf("%d%lld",&n,&x);
    long long time=0;
    long long c[N];
    int i;
    for(i=0; i<n; i++) {
        scanf("%lld",&c[i]);
    }
    sort(c,n);

    for(i=0; i<n; i++) {
        if(x>1) {
            //保证与time相加的数字都是long long型！
            time+=c[i]*x;
            x--;
        } else if(x==1) {
            time+=c[i]*x;
        }
    }
    printf("%lld\n",time);
    return 0;
}
