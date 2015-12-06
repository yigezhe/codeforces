//laptops，lap膝盖?
//distinct严格不同！
//n^2=10^10危险！
//用sort的话，先按价格从大到小排序！
//我必须用n^2一下复杂度的sort！
//这里尝试使用merge sort！
//在没有严格清晰理解merge sort的情况下，改变代码运用它成功了！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 100000+1
    struct laptop {
        int price;
        int quality;
    };

int min(int a,int b) {
    if(a>b) return b;
    else return a;
}
void BottomUpMerge(struct laptop A[], int iLeft, int iRight, int iEnd, struct laptop B[]) {
    int i0 = iLeft;
    int i1 = iRight;
    int j;

    /* While there are elements in the left or right runs */
    for (j = iLeft; j < iEnd; j++) {
        /* If left run head exists and is <= existing right run head */
        if (i0 < iRight && (i1 >= iEnd || A[i0].price <= A[i1].price)) {
            B[j].price = A[i0].price;
            B[j].quality = A[i0].quality;
            i0 = i0 + 1;
        } else {
            B[j].price = A[i1].price;
            B[j].quality = A[i1].quality;
            i1 = i1 + 1;
        }
    }
}
void print(struct laptop a[],int n) {
    int i;
    for(i = 0; i < n; i++)
        printf(" (%d,%d)",a[i].price,a[i].quality);
    printf("\n");
}

void CopyArray(struct laptop B[], struct laptop A[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        A[i].price = B[i].price;
        A[i].quality = B[i].quality;
    }
}

/* array A[] has the items to sort; array B[] is a work array */
void BottomUpSort(struct laptop A[], struct laptop B[], int n) {
    /* Each 1-element run in A is already "sorted". */
    /* Make successively longer sorted runs of length 2, 4, 8, 16... until whole array is sorted. */
    int width,i;
    for (width = 1; width < n; width = 2 * width) {
        /* Array A is full of runs of length width. */
        for (i = 0; i < n; i = i + 2 * width) {
            /* Merge two runs: A[i:i+width-1] and A[i+width:i+2*width-1] to B[] */
            /* or copy A[i:n-1] to B[] ( if(i+width >= n) ) */
            //这里没有使用递归！
            BottomUpMerge(A, i, min(i+width, n), min(i+2*width, n), B);
        }
        /* Now work array B is full of runs of length 2*width. */
        /* Copy array B to array A for next iteration. */
        /* A more efficient implementation would swap the roles of A and B */
        CopyArray(B, A, n);
        /* Now array A is full of runs of length 2*width. */
    }
}

int main() {
    int n;
    scanf("%d",&n);
    struct laptop ab[N];
    struct laptop tmp[N];
    int i;
    for(i=0; i<n; i++) {
        scanf("%d%d",&(ab[i].price),&(ab[i].quality));
    }
    //print(ab,n);
    BottomUpSort(ab, tmp, n);
    //print(ab,n);
    for(i=0; i<n-1; i++) {
        if(ab[i].quality>ab[i+1].quality) {
            printf("Happy Alex");
            return 0;
        }
    }
    printf("Poor Alex");
    return 0;
}
