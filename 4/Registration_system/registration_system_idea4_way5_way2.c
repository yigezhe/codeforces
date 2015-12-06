////这个代码不成功！
//这个方法只能说是足够好，可以处理竞赛题目中的数据。
//但是更好的方法是建立冲突处理机制，这个方法是一个完备的方法！
//我用我的想法来建立hash！
//每一个名字都不是空的，就是至少有一个元素！
//每一个名字不超过32个元素。
//都是小写字母！97~122
//32个位置有27种选择，产生10^41次方的组合！
//先给出思路
//读入一个新的字符串，变为整数，用二分法查找其位置，
//然后插入
//整个代码完全体现我的想法，我看一下结果！
//换一个hash看一下结果！
/*interface*/
/*interface implementation*/
#include<stdio.h>
#include<string.h>
#define C 33+5
#define N 100001
long long hash_table[N];
int same_table[N];
int hash_table_length;
//这个hash也是成功的！
long long hash(char *name) {
    long long h=0;
        unsigned int highorder = h & 0xf8000000;    // extract high-order 5 bits from h
        // 0xf8000000 is the hexadecimal representation
        //   for the 32-bit number with the first five
        //   bits = 1 and the other bits = 0
        h = h << 5 ;                   // shift h left by 5 bits
        h = h ^ (highorder >> 27);     // move the highorder 5 bits to the low-order
        //   end and XOR into h
        //h = h ^ ki                    // XOR h and ki
    while(*name) {
        h = h ^ (*name);                    // XOR h and ki
        name++;
    }
    return h;
}
void search_and_add(char * name, char *result) {
    long long hash_number=hash(name);
    if(hash_table_length==0) {
        hash_table[hash_table_length]=hash_number;
        hash_table_length++;
        strcpy(result,"OK");
    } else {

        int head=0;
        //以我喜欢的方式编写！
        int tail=hash_table_length-1;
        int find=0;
        int mid;
        while(head<=tail) {
            mid=(head+tail)/2;
            //printf("***head=%d,mid=%d,tail=%d\n",head,mid,tail);
            if(hash_table[mid]==hash_number) {
                same_table[mid]++;
                find=1;
                break;
            } else if(hash_number>hash_table[mid]) {
                head=mid+1;
            } else if(hash_number<hash_table[mid]) {
                tail=mid-1;
            }
            //printf("head=%d,mid=%d,tail=%d\n",head,mid,tail);
        }
        if(!find) {
            //对hash_table数组的插入操作要与same_table数组同时操作
            //否则两者的关联性就丢失了！
            //二分查找中，如果从大到小排，那么你的head，tail选择就要改变！
            int j;
            for(j=0; j<hash_table_length; j++) {
                if(hash_number<hash_table[j]) break;
            }
            int insert_position=j;
            for(j=hash_table_length; j>insert_position; j--) {
                hash_table[j]=hash_table[j-1];
                same_table[j]=same_table[j-1];
            }
            hash_table[insert_position]=hash_number;
            same_table[insert_position]=0;
            hash_table_length++;
            strcpy(result,"OK");
        } else {
            strcpy(result,name);
            char digit[C];
            sprintf(digit,"%d",same_table[mid]);
            strcat(result,digit);
        }
    }

}
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    int i;
    hash_table_length=0;
    for(i=0; i<n; i++) {
        same_table[i]=0;
    }
    for(i=0; i<n; i++) {
        char name[C];
        scanf("%s",name);
        //printf("%s--%lld\n",name,hash(name));
        char result[C];
        search_and_add(name,result);
        /*
            int j;
            for(j=0; j<hash_table_length; j++) {
                printf(" (%lld,%d)",hash_table[j],same_table[j]);
            }
            printf("\n");
        */

        printf("%s\n",result);
    }

    return 0;
}
