//approaching正在进行！
//不减的天数！
/*interface*/
/*interface implementation*/
/*client*/
struct exam {
    int a;
    int b;
};
#include<stdio.h>
#define N 5000+1
#include<stdlib.h>
void print(struct exam *a,int n) {
    int i;
    for(i=0; i<n; i++) {
        printf(" (%d,%d)",a[i].a,a[i].b);
    }
    printf("\n");
}

// Function to Merge Arrays L and R into A.
// lefCount = number of elements in L
// rightCount = number of elements in R.
void Merge(struct exam *A,struct exam *L,int leftCount,struct exam *R,int rightCount) {
    int i,j,k;

    // i - to mark the index of left aubarray (L)
    // j - to mark the index of right sub-raay (R)
    // k - to mark the index of merged subarray (A)
    i = 0;
    j = 0;
    k =0;

    while(i<leftCount && j< rightCount) {
        if(L[i].a  < R[j].a) {
		A[k].a = L[i].a;
		A[k].b = L[i].b;
		k++;
		i++;
	} else {
		A[k++] = R[j++];
		A[k++] = R[j++];
	}
    }
    while(i < leftCount) A[k++] = L[i++];
    while(j < rightCount) A[k++] = R[j++];
}

// Recursive function to sort an array of integers.
void sort(int *A,int n) {
    int mid,i, *L, *R;
    if(n < 2) return; // base condition. If the array has less than two element, do nothing.

    mid = n/2;  // find the mid index.

    // create left and right subarrays
    // mid elements (from index 0 till mid-1) should be part of left sub-array
    // and (n-mid) elements (from mid to n-1) will be part of right sub-array
    L = (int*)malloc(mid*sizeof(int));
    R = (int*)malloc((n- mid)*sizeof(int));

    for(i = 0; i<mid; i++) L[i] = A[i]; // creating left subarray
    for(i = mid; i<n; i++) R[i-mid] = A[i]; // creating right subarray

    sort(L,mid);  // sorting the left subarray
    sort(R,n-mid);  // sorting the right subarray
    Merge(A,L,mid,R,n-mid);  // Merging L and R into A as sorted list.
    free(L);
    free(R);
}
int main() {
    //先看一个初步的想法，就是先按ai排序
    //再看bi是不是有序，有序就选bi，无序就选ai
    int n;
    scanf("%d",&n);
    struct exam time[N];
    int i;
    for(i=0; i<n; i++) {
        scanf("%d%d",&(time[i].a), &(time[i].b));
    }
    print(time,n);
    sort(time,n);
    print(time,n);
    int which=1;
    for(i=0; i<n-1; i++) {
        if(time[i].b > time[i+1].b) {
            which=0;
            break;
        }
    }
    if(which==1) {
        printf("%d\n",time[n-1].a);
    } else {
        printf("%d\n",time[n-1].b);
    }

    return 0;
}
