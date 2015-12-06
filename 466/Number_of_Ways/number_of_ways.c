
/*interface*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
/*interface implementation*/
/*client*/
int main() {
    int n;
    //1<=n<=500000
    scanf("%d",&n);
    int *a=malloc(n*sizeof(int));
    if(a==NULL) {
        printf("n 没有分配到内存\n");
    }
    int i;
    long long sum=0;
    //|ai|<=10^9
    //这样sum的最大值是5*10^5*10^9=5*10^14
    //所以sum应该是一个long long！
    //
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    //printf("sum = %lld\n",sum);
    long long ways=0;
    if(n>=3) {
        if(sum%3==0) {
            //全是零的情况，我没有处理过！
            if(sum==0) {
                int all_zeros=1;
                for(i=0; i<n; i++) {
                    if(a[i]!=0) {
                        all_zeros=0;
                        break;
                    }
                }
                if(all_zeros) {
		    //printf("n >= 3, sum %% 3 == 0, sum == 0, all zeros, ways = %lld\n",ways);
                    //c(n-1,2)
                    ways=(n-1)*(n-2)/2;
                } else {
                    int start_i=0;
                    for(i=0; i<n; i++) {
                        if(a[i]!=0) {
                            start_i=i;
                            break;
                        }
                    }
                    int zero_start=0;
                    for(i=0; i<start_i; i++) {
                        if(a[i]==0) {
                            zero_start++;
                        }
                    }
                    int end_i=0;
                    for(i=n-1; i>=0; i--) {
                        if(a[i]!=0) {
                            end_i=i;
                            break;
                        }
                    }
                    int zero_end=0;
                    for(i=end_i; i<n; i++) {
                        if(a[i]==0) {
                            zero_end++;
                        }
                    }
                    ways=(zero_start+zero_end)*(zero_start+zero_end-1)/2;
                }
            } else {
                int part_sum=0;
                //这里要判断能不能形成sum/3这个和！
                int zero_start=0;
                int part1=-1;
		int find1=0;
                for(i=0; i<n; i++) {
                    part_sum+=a[i];
                    if(part_sum==sum/3) {
                        //printf("i=%d\n",i);
			find1=1;
                        part1=i;
                        i++;
                        while(i<n && a[i]==0) {
                            i++;
                            zero_start++;
                        }
			break;
                    }
                }
                part_sum=0;
                int part3=0;
                int zero_end=0;
		int find3=0;
                for(i=n-1; i>=0; i--) {
                    part_sum+=a[i];
                    if(part_sum==sum/3) {
			    find3=1;
                        part3=i;
                        //printf("i=%d\n",i);
                        i--;
                        while(i>=0 && a[i]==0) {
                            i--;
                            zero_end++;
                        }
			break;
                    }
                }
                if(find1 && find3 && part3-part1>=1)
                    ways=(zero_start+1)*(zero_end+1);
                else ways=0;
            }
        } else {
            ways=0;
        }
    } else {
        ways=0;
    //printf("n < 3, ways = %lld\n",ways);
    }
    printf("%lld\n",ways);

    free(a);
    return 0;
}
