//
// Created by 全 on 2020/7/26.
//

#ifndef DEMO2_B_PLUSTREE_H
#define DEMO2_B_PLUSTREE_H

#define M 3//b +树的阶
/*
 * 数据 相当于一条记录
 */
typedef struct value value;
struct value {
    int value;
};
typedef struct b_plus_tree b_plus_tree;
struct b_plus_tree {
    int keys[M];
    void *values[M];
    b_plus_tree *child[M];
    b_plus_tree *parent;
    int len;
};
 //b+树 插入
b_plus_tree * b_plus_tree_insert(b_plus_tree * bPlusTree,int key,value val);
//根据 k 返回V
value b_plus_tree_find(b_plus_tree *,int key);
//打印b+树
void print_bplustree(b_plus_tree *);
//释放b+树
void free_bplustree(b_plus_tree *);



#endif //DEMO2_B_PLUSTREE_H
