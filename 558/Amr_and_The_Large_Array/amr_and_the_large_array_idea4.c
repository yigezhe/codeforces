//好的问题，就是让我去找新的方法，我的代码库又扩大了！
/*interface*/
#include<stdio.h>
#include<stdlib.h>
/*interface implementation*/
struct node {
    int data;
    struct node * next;
};
/*client*/
int main() {
    int n;
    scanf("%d",&n);
    int *a=malloc(n*sizeof(int));
    if(a==NULL) {
        printf("a 没有分配到内存\n");
    }
    //printf("n=%d\n",n);
    int i;
    int max=0;
    //这算是做了两个工作！每一个代码最多做两个工作！
    for(i=0; i<n; i++) {
        scanf("%d",&a[i]);
        if(a[i]>max) max=a[i];
    }
    /*
    for(i=0; i<n; i++) {
        printf(" %d",a[i]);
    }
    printf("\nmax = %d\n",max);
    */

    //printf("max = %d\n",max);
    int *count=malloc((max+1)*sizeof(int));
    if(count==NULL) {
        printf("count 没有分配到内存\n");
    }

    for(i=0; i<=max; i++) {
        count[i]=0;
    }
    for(i=0; i<n; i++) {
        count[a[i]]++;
    }

    int unique=0;
    for(i=1; i<=max; i++) {
        if(count[i]>0) {
            unique++;
        }
    }
    int *element=malloc(unique*sizeof(int));
    if(element==NULL) {
        printf("element 没有分配到内存\n");
    }

    struct node **index=malloc(unique*sizeof(struct node *));
    if(index==NULL) {
        printf("index 没有分配到内存\n");
    }
    for(i=0; i<unique; i++) {
        index[i]=NULL;
    }
    int ne=0;
    for(i=1; i<=max; i++) {
        if(count[i]>0) {
            element[ne]=i;
            ne++;
        }
    }
    /*
    for(i=0; i<unique; i++) {
        printf(" %d",element[i]);
    }
    printf("\n");
    */



    for(i=0; i<=max; i++) {
        count[i]=0;
    }
    ne=0;
    int *first=malloc((max+1)*sizeof(int));
    if(first==NULL) {
        printf("first 没有分配到内存\n");
    }


    for(i=0; i<n; i++) {
        if(count[a[i]]==0) {
            struct node *new=malloc(sizeof(struct node));
            new->data=i;
            new->next=NULL;
            index[ne]=new;
            //printf("%d\n", index[ne]->data);
            first[a[i]]=ne;
            ne++;
        } else if(count[a[i]]>0) {
            struct node *new2=malloc(sizeof(struct node));
            new2->data=i;
            int pos=first[a[i]];
            //printf("%d at %d\n",a[i],pos);
            new2->next=index[pos];
            index[pos]=new2;
        }
        count[a[i]]++;
    }
    /*
    for(i=0; i<unique; i++) {
        //printf(" %d",index[i]->data);
        struct node *cur=index[i];
        while(cur!=NULL) {
            printf(" %d",cur->data);
            cur=cur->next;
        }
        printf("\n");
    }
    printf("\n");
    */
    int max_times=count[1];
    for(i=2; i<=max; i++) {
        if(count[i]>max_times) {
            max_times=count[i];
        }
    }
    int min_last=n-1,min_begin=0;
    for(i=0; i<unique; i++) {
        struct node *cur=index[i];
        int last=cur->data;
        while(cur->next!=NULL) {
            cur=cur->next;
        }
        int begin=cur->data;
        if(count[a[last]]==max_times) {
            if(last-begin<min_last-min_begin) {
                min_last=last;
                min_begin=begin;
            }
        }
    }
    printf("%d %d\n",min_begin+1,min_last+1);
    free(a);
    free(element);
    free(count);
    for(i=0; i<unique; i++) {
        struct node *cur=index[i]->next;
	//这是一种接力形式的释放内存的方法！
        while(cur!=NULL) {
            struct node *tmp=cur;
            cur=cur->next;
            free(tmp);
        }
        free(index[i]);
        index[i]=NULL;
    }
    free(index);
    return 0;
}
