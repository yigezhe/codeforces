//这里的company是一个团队，一个一起去吃饭的团队！
/*interface*/
#include<stdio.h>
#include<stdlib.h>
#define N 100000
typedef struct friend {
    int money;
    int friendship;
} Friend;
long long max(long long a,long long b) {
    if(a>b) return a;
    else return b;
}

void print(Friend *a,int n) {
    int i;
    for(i=0; i<n; i++) {
        printf(" (%d,%d)",a[i].money,a[i].friendship);
    }
    printf("\n");
}
void sort(Friend * a,int length) ;
void merge_sort(Friend *a, Friend * tmp, int left, int right) ;
void merge(Friend * a, Friend * tmp, int left, int right, int right_end ) ;
void sort(Friend* a,int length) {
    Friend *tmp = malloc(sizeof(Friend)*length);
    if(tmp==NULL) {
        printf("没有分配到足够的内存\n");
    }
    //有一个备用数组！就是存储空间增加了一倍，
    //应该选择不需要备用数组的归并排序！
    merge_sort(a, tmp,  0, length - 1);
}

void merge_sort(Friend *a, Friend * tmp, int left, int right) {
    if( left < right ) {
        int center = (left + right) / 2;
        merge_sort(a, tmp, left, center);
        merge_sort(a, tmp, center + 1, right);
        merge(a, tmp, left, center + 1, right);
    }
}

void merge(Friend * a, Friend * tmp, int left, int right, int right_end ) {
    //这一部分代码还没有看懂，但是先用！
    int left_end = right - 1;
    int k = left;
    int num = right_end - left + 1;

    while(left <= left_end && right <= right_end)
        if(a[left].money<=a[right].money) {
            tmp[k].money = a[left].money;
            tmp[k].friendship = a[left].friendship;
            k++;
            left++;
            //就是左边小就取左边的！
        } else {
            tmp[k].money = a[right].money;
            tmp[k].friendship = a[right].friendship;
            k++;
            right++;
            //右边小取右边！
        }
    //上面处理之后有两种情况
    //1.左边取完了，右边没有取完
    //1.右边取完了，左边没有取完
    //    // Copy rest of first half
    while(left <= left_end) {
        tmp[k].money = a[left].money;
        tmp[k].friendship = a[left].friendship;
        k++;
        left++;
    }
    // Copy rest of right half
    while(right <= right_end) {
        tmp[k].money = a[right].money;
        tmp[k].friendship = a[right].friendship;
        k++;
        right++;
    }

    // Copy tmp back
    int i;
    for(i = 0; i < num; i++, right_end--) {
        a[right_end].money = tmp[right_end].money;
        a[right_end].friendship = tmp[right_end].friendship;
    }
}
/*client*/
int main() {
    int n,d;
    scanf("%d%d",&n,&d);
    int i;

    Friend f[N];
    for(i=0; i<n; i++) {
        scanf("%d%d",&(f[i].money),&(f[i].friendship));
    }
    sort(f,n);
    //print(f,n);
    long long res=0;
    int start=0;
    int end=start;
    int poor=f[start].money+d;
    //printf("poor = %d\n",poor);
    for(i=start+1; i<n; i++) {
        if(f[i].money<poor) {
            end=i;
        } else {
            break;
        }
    }
    long long sum=0;
    for(i=start; i<=end; i++) {
        sum+=f[i].friendship;
    }
    res=sum;
    /*
    printf("%d %d\n",start,end);
    printf("res=%Ld\n",res);
    printf("sum=%Ld\n",sum);
    */
    while(start<n-1 && end<n-1) {
        int new_end;
        poor=f[start+1].money+d;
        for(i=end+1; i<n; i++) {
            if(f[i].money<poor) {
                new_end=i;
            } else {
                break;
            }
        }
        //printf("%d %d\n",start+1,new_end);
        sum-=f[start].friendship;
        //printf("sum=%Ld\n",sum);
        for(i=end+1; i<=new_end; i++) {
            sum+=f[i].friendship;
        }
        //printf("sum = %Ld\n",sum);
        res=max(sum,res);
        end=new_end;
        start=start+1;
    }
    printf("%lld\n",res);

    return 0;
}
