#include "stdio.h"
#include "stdlib.h"
typedef struct Node Node;
struct Node{
    int item;
    Node *next;
};
/**
 * 降序
 * @param a a元素
 * @param b b元素
 * @return a>b 返回1 否则返回0
 */
int descending_order(Node *a,Node *b){//降序
    if (a==NULL){
        return 0;
    }
    return a->item > b->item;
}
/**
 * 升序
 * @param a a元素
 * @param b b元素
 * @return a<b 返回1 否则返回0
 */
int ascending_order(Node *a,Node *b){//升序
    if (a==NULL){
        return 0;
    }
    return a->item < b->item;
}
/**
 * 末位插入元素
 * @param first 头节点
 * @param node 当前节点
 * @return 头节点
 */
Node* insert(Node *first,Node *node){
    if (first==NULL){
        first = node;
        return first;
    }
    Node *myNode;
    myNode = first;
    while (1){
        if (myNode->next==NULL){
            myNode->next=node;
            break;
        } else{
            myNode = myNode->next;
        }
    }
    return first;
}
/**
 * 按排序规则插入元素
 * @param first 头节点
 * @param node 当前节点
 * @param order 排序规则
 * @return 头节点
 */
Node* order_insert(Node *first,Node *node,int(*order)(Node *,Node *)){
    if (first==NULL){//判断头是否为null
        first = node;
        return first;
    }
    if (!order(first,node)){//表头变换
        node->next=first;
        first = node;
        return first;
    }
    Node *myNode;
    Node *before;
    before = first;
    myNode = first->next;
    while (1){
        if (!order(myNode,node)){
            node->next=myNode;
            before->next = node;
            break;
        } else if (myNode->next==NULL){
            myNode->next=node;
            break;
        } else{
            myNode = myNode->next;
            before = before->next;
        }
    }
    return first;
}
/**
 * 打印链表
 * @param first 头节点
 */
void print_link(Node *first){
    if (first==NULL){
        return;
    }
    Node *myNode;
    myNode = first;
    while (1){
        printf("%d~",myNode->item);
        if (myNode->next==NULL){
            break;
        } else{
            myNode = myNode->next;
        }
    }
}
/**
 * 将链表内数据拷贝到数组
 * @param first 头节点
 * @param array 数组
 * @return 拷贝数据的数量
 */
int copy(Node *first,int *array){
    if (first==NULL){
        return 0;
    }
    Node *myNode;
    myNode = first;
    int count = 0;
    while (1){
        *array=myNode->item;
        array++;
        count++;
        if (myNode->next==NULL){
            break;
        } else{
            myNode = myNode->next;
        }
    }
    return count;
}
/**
 * 释放链表
 * @param first 头节点
 */
void free_linked(Node * first) //释放链表
{
    Node * p;
    while(first != NULL)
    {
        p = first;
        first = first->next;
        free(p);
    }
}