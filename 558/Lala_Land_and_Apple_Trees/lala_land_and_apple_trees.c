//这里有两个方向，只需算出两个方向的值都算出来，然后比较就可以！
/*interface*/
/*interface implementation*/
/*client*/
//成功了，但是这里的问题还是有！
#include<stdio.h>
#define N 100+1

#include<stdio.h>
void swap(int *Aj, int *Aj1) {
    int originAj = (*Aj);
    *Aj = (*Aj1);
    *Aj1 = originAj;
}
void printarray(int array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void sort(int a[], int b[],int n,int direction) {
    int haveReverse = 0;
    int i, firstReversePlace = 0;
    for (i = 0; i < n - 1; i++) {
        int judge;
        if(direction==1) {
            judge=a[i] > a[i + 1];
        } else {
            judge=a[i] < a[i + 1];
        }
        if (judge) {
            if (haveReverse == 0) {
                firstReversePlace = i;
            }
            haveReverse = 1;
            //这里的优点是只有一处实际数据交换！
            int t = a[i];
            a[i] = a[i + 1];
            a[i + 1] = t;

            t = b[i];
            b[i] = b[i + 1];
            b[i + 1] = t;

            if (i > 0) {
                i -= 2;
            } else {
                i = 0;
            }
        } else {
            if (haveReverse == 1) {
                i = firstReversePlace;
                haveReverse = 0;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d",&n);
    int i;
    int positive_x[N],positive_a[N];
    int px=0;
    int reverse_x[N],reverse_a[N];
    int rx=0;

//这里的初始化避免了问题的产生，但是我的程序还是处理得不够细致，
//我可以不用初始化！
    for(i=0; i<N; i++) {
    positive_x[i]=0;
    positive_a[i]=0;
    reverse_x[i]=0;
    reverse_a[i]=0;
    }
    for(i=0; i<n; i++) {
        int x,a;
        scanf("%d%d",&x,&a);
        if(x>0) {
            positive_x[px]=x;
            positive_a[px]=a;
            px++;
        } else {
            reverse_x[rx]=x;
            reverse_a[rx]=a;
            rx++;
        }
    }
    //我需要排一个序！
    //分割成两个数组比较合适！
    sort(positive_x,positive_a,px,1);
    sort(reverse_x,reverse_a,rx,0);
    /*
    printarray(positive_x,px);
    printarray(reverse_x,rx);

    printarray(positive_a,px);
    printarray(reverse_a,rx);
    */
    int apple1=0;
    int direction=0;
    int j;
    i=0,j=0;
    while(1) {
        //printf("i=%d, j=%d\n",i,j);
        if(direction==0) {
            apple1+=positive_a[i];
            i++;
            if(i==px && j<rx) {
                apple1+=reverse_a[j];
                j++;
                break;
            }
            direction=!direction;

        } else {
            apple1+=reverse_a[j];
            j++;
            if(j==rx && i<px) {
                apple1+=positive_a[i];
                i++;
                break;
            }
            direction=!direction;
        }
        if(!(i<px && j<rx)) {
            break;
        }
    }
    int apple2=0;
    direction=1;
    i=0,j=0;
    while(1) {
        if(direction==0) {
            apple2+=positive_a[i];
            i++;
            if(i==px && j<rx) {
                apple2+=reverse_a[j];
                break;
            }
            direction=!direction;
        } else {
            apple2+=reverse_a[j];
            j++;
            if(j==rx && i<px) {
                apple2+=positive_a[i];
                break;
            }
            direction=!direction;
        }
        //这叫做后处理！
        if(!(i<px && j<rx)) {
            break;
        }
    }
    //printf("apple 1 = %d, apple 2 = %d\n",apple1,apple2);
    if(apple1>apple2) printf("%d\n",apple1);
    else printf("%d\n",apple2);

    return 0;
}
