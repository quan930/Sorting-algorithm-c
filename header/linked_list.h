//
// Created by daquan on 2018/12/4.
//

#ifndef DEMO2_LINKED_LIST_H
#define DEMO2_LINKED_LIST_H
typedef struct Node Node;
struct Node{
    int item;
    Node *next;
};
int descending_order(Node *a,Node *b);//降序
int ascending_order(Node *a,Node *b);//升序
Node* insert(Node *first,Node *node);
Node* order_insert(Node *first,Node *node,int(*order)(Node *,Node *));
void print_link(Node *first);
int copy(Node *first,int *array);
void free_linked(Node * first);
int copy_free(Node *first,int *array);

#endif //DEMO2_LINKED_LIST_H
