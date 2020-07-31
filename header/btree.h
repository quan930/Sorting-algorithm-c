//
// Created by 全 on 2020/7/28.
//

#ifndef DEMO2_BTREE_H
#define DEMO2_BTREE_H
#define M 4//b 树的阶
typedef struct b_tree b_tree;
struct b_tree {
    int keys[M];
    b_tree *child[M+1];
    b_tree *parent;
    int len;
};
//b树插入
b_tree * b_tree_insert(b_tree *,int );
//b树查询
void b_tree_find(b_tree *,int ,int *);
//打印b树
void printbtree(b_tree *);
//释放b树
void freebtree(b_tree *);
#endif //DEMO2_BTREE_H
