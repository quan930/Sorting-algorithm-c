//
// Created by 全 on 2020/7/24.
//

#ifndef DEMO2_REDBLACKTREE_H
#define DEMO2_REDBLACKTREE_H
typedef struct red_black_tree red_black_tree;
typedef enum colors{RED,BLACK} colors;
struct red_black_tree{
    int key;
    red_black_tree *left;
    red_black_tree *right;
    red_black_tree *parent;
    colors color;
};
//红黑树插入
red_black_tree * red_black_tree_insert(red_black_tree *,int );
//红黑树查询
void red_black_tree_find(red_black_tree *,int ,int *);
//打印红黑树
void print_rbtree(red_black_tree *);
//释放红黑树
void free_rbtree(red_black_tree *);
#endif //DEMO2_REDBLACKTREE_H
