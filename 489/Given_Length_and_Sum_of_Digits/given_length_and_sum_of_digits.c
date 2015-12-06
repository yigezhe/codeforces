//整数的长度是m，整个整数各个数字之和是s
//想法一，用一个bfs来求解最小整数。
//用另一个bfs求解最大整数！
/*interface*/
#include<stdio.h>
#define M 100+1

//使用linkedlist来实现一个队列
#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* head = NULL;
struct node* tail = NULL;
void push(int data) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
    if (head==NULL) {
        tail=new_node;
        head=new_node;
    } else {
        tail->next=new_node;
        tail=new_node;
    }
}
void pop() {
    if(head != NULL) {
        struct node* tmp_head;
        tmp_head = head;
        head= tmp_head->next;
        if (tmp_head==tail) tail=NULL;
        free(tmp_head);
    } else {
        fprintf(stderr,"对空的队列无法pop！\n");
    }
}
int front() {
    return head->data;
}
int empty() {
    return head==NULL;
}
int size() {
    struct node* current = head;
    int count = 0;
    while(current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}
void clear() {
    struct node* current = head;
    struct node* tmp=head;
    while(tmp != NULL) {
        tmp=current->next;
        free(current);
        current=tmp;
    }
}
void print() {
    struct node* current = head;

    if(current != NULL) {
        printf("%d",current->data);
        current = current->next;
    }
    while(current != NULL) {
        printf(",%d",current->data);
        current = current->next;
    }
    printf("\n");
}
/*interface implementation*/
/*client*/
int bfs() {
    int i;
    for (i=0; i<10; i++) {
        push(i);
    }
    while (empty()) {
        int cur=front();
        pop();

    }

}
int main() {
    return 0;
}
