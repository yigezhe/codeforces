//编译器要记录你上一次编译中的错误吗？
//就是先显示上一次未解决的错误，在显示新的错误，
//还有一点就是直接按照错误出现在哪一行，按行数从小到大排列！
//因为只有你解决了前面的错误，你才可以解决后面的错误！
//想法一，直接线性查找！
//就是超时了！
//改进思路是，先排序，后二分查找！
//n^2的时间消费，10^10的计算量！
//虽然消耗时间，但是先实现一下！
//想法三则是把三个数组都排序，然后从头往前依次找，找到不同项，就是我们需要的那个值！
/*interface*/
/*interface implementation*/
/*client*/
#include<stdio.h>
#define N 100000
int main() {
    int n;
    int a[N],b[N],c[N];
    int tmp_b[N];
    scanf("%d",&n);
    int i;
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    for(i=0; i<n-1; i++) {
        scanf("%d",&b[i]);
	tmp_b[i]=b[i];
    }
    for(i=0; i<n-2; i++) {
        scanf("%d",&c[i]);
    }
    int j;
    int find;
    for(i=0; i<n; i++) {
        find=0;
        for(j=0; j<n-1; j++) {
            if(i!=j && a[i]==tmp_b[j]) {
                find=1;
		tmp_b[j]=0;
                break;
            }
        }
        if(find) continue;
        else {
		find=a[i];
		break;
	}
    }
    printf("%d\n",find);
    for(i=0; i<n-1; i++) {
        find=0;
	//3 7 5 4 3
	//4 3 7 5
	//上下都出现3,我需要找出多余的3！
        for(j=0; j<n-2; j++) {
            if(i!=j && b[i]==c[j]) {
		    c[j]=0;
                find=1;
                break;
            }
        }
        if(find) continue;
        else {
		find=b[i];
		break;
	}
    }
    printf("%d\n",find);

    return 0;
}
