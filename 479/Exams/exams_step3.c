//approaching正在进行！
//不减的天数！
/*interface*/
/*interface implementation*/
/*client*/
struct exam {
    int a;
    int b;
};
#define MAX 1000000000+1
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
void print_int(int *a,int n) {
    int i;
    for(i=0; i<n; i++) {
        printf(" %d",a[i]);
    }
    printf("\n");
}
void sort(struct exam * a,int length) ;
void mergeSort(struct exam * a, struct exam * tmp, int left, int right) ;
void merge(struct exam * a, struct exam * tmp, int left, int right, int rightEnd ) ;
void sort(struct exam* a,int length) {
    struct exam *tmp = malloc(sizeof(struct exam)*length);
    if(tmp==NULL) {
        printf("没有分配到足够的内存\n");
    }
    mergeSort(a, tmp,  0, length - 1);
}

void mergeSort(struct exam *a, struct exam * tmp, int left, int right) {
    //printf("mergeSort(%d,%d)\n",left, right);
    if( left < right ) {
        int center = (left + right) / 2;
        mergeSort(a, tmp, left, center);
        mergeSort(a, tmp, center + 1, right);
        merge(a, tmp, left, center + 1, right);
    }
}

void merge(struct exam * a, struct exam * tmp, int left, int right, int rightEnd ) {
    //这一部分代码还没有看懂，但是先用！
    int leftEnd = right - 1;
    int k = left;
    int num = rightEnd - left + 1;

    while(left <= leftEnd && right <= rightEnd) {
        if(a[left].a<a[right].a) {
            tmp[k].a = a[left].a;
            tmp[k].b = a[left].b;
            k++;
            left++;
        } else if(a[left].a==a[right].a) {
            if(a[left].b<=a[right].b) {
                tmp[k].a = a[left].a;
                tmp[k].b = a[left].b;
                k++;
                left++;
            } else {
                tmp[k].a = a[right].a;
                tmp[k].b = a[right].b;
                k++;
                right++;
            }
        } else {
            tmp[k].a = a[right].a;
            tmp[k].b = a[right].b;
            k++;
            right++;
        }
    }
    // Copy rest of first half
    while(left <= leftEnd) {
        tmp[k].a = a[left].a;
        tmp[k].b = a[left].b;
        k++;
        left++;
    }
    // Copy rest of right half
    while(right <= rightEnd) {
        tmp[k].a = a[right].a;
        tmp[k].b = a[right].b;
        k++;
        right++;
    }

    // Copy tmp back
    int i;
    for(i = 0; i < num; i++, rightEnd--) {
        a[rightEnd].a = tmp[rightEnd].a;
        a[rightEnd].b = tmp[rightEnd].b;
    }
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
    //print(time,n);
    sort(time,n);
    //print(time,n);
    int choose[N];
    for(i=0; i<n; i++) {
        choose[i]=MAX;
    }
    if(time[0].a>time[0].b) {
        choose[0]=time[0].b;
    } else {
        choose[0]=time[0].a;
    }
    int which=0;
    for(i=0; i<n-1; i++) {
	    which=0;
        if(time[i].a<=time[i+1].a) {
		which=1;
            if(time[i+1].a<=choose[i+1]) {
                choose[i]=time[i].a;
                choose[i+1]=time[i+1].a;
            }
        }
        if(time[i].b<=time[i+1].b) {
		which=2;
            if(time[i+1].b<=choose[i+1]) {
                choose[i]=time[i].b;
                choose[i+1]=time[i+1].b;
            }
        }
        if(time[i].a<=time[i+1].b) {
		which=3;
            if(time[i+1].b<=choose[i+1]) {
                choose[i]=time[i].a;
                choose[i+1]=time[i+1].b;
            }
        }
        if(time[i].b<=time[i+1].a) {
		which=4;
            if(time[i+1].a<choose[i+1]) {
                choose[i]=time[i].b;
                choose[i+1]=time[i+1].a;
            }
        }
	if(which==0) break;
    }
    //print_int(choose,n) ;
    if(which==0 && n!=1) {
    printf("%d\n",time[n-1].a);
    } else {
    printf("%d\n",choose[n-1]);
    }


    return 0;
}
