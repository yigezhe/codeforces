#include <stdio.h>

int main() {
    int n, k, a, a2, r = 0;

    scanf("%d%d", &n, &k);

    //分析他人的代码也是从自己的角度去获取新的认识与思考，这些认识或许作者本人都不知道，这些分析也可以推动自己的成长！
    //第一部分处理： k == n 或者 在任何位置出现a<=0的情况
    //把前k个数处理一下
    int i;
    for(i = 0; i < k; i++) {
        scanf("%d", &a);
        //这里就是把前k个大于零的整数直接通过！
        if(a <= 0)
            break;
    }

    r = i;//这里r可能等于k,前面没有零,第k位也不是零！
    //可能小于k,第k位是零，或者更前面的是零！

    //第二部分处理： k < n 并且前k个数中没有出现a<=0的情况
    //第k位后面还有数字！

    //把剩下的n-k个数处理一下
    //k<n,作者不想处理k＝n的情况，因为前面的for循环已经可以给出答案了
    //同时作者也不想处理a<=0的情况，一旦出现a<=0后面的情况就不用处理了！
    int j = 0;
    if(k < n && a > 0) {
        //能进入if我觉得i肯定等于k
        //为了证明这个观点 用下面的代码测试！if(i==k) printf("yes i == k\n");
        do {
            //看来作者把a还保留着！
            //int res=scanf("%d", &a2);//第一次得到的是a[k]！
            scanf("%d", &a2);//第一次得到的是a[k]！
	    //这个读取有风险，可能什么都没有读到！
	    //if(res!=1) { printf("can't read\n"); } else { printf("res=%d,a2==%d\n",res,a2); }
            j++;//这里统计的是读取了一个元素！
        } while(a2 == a && i + j < n);
        //这里a保存的就是第k个元素！a[k-1]

        //后面就写得不好！
        if(a2 != a)
            r = i +j -1;//因为j是提前加一的，如果a2不符合要求我们就要把这个加一取消掉
        else
            r = i + j;//如果a2符合要求，那么我们就不用取消那个加一，正好确定那个元素就是我们需要的！
    }
    printf("%d\n", r);

    return 0;
}