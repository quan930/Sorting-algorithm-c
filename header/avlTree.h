//
// Created by 全 on 2020/7/25.
//

#ifndef DEMO2_AVLTREE_H
#define DEMO2_AVLTREE_H
typedef struct avl_tree avl_tree;
struct avl_tree{
    int key;
    avl_tree *left;
    avl_tree *right;
    avl_tree *parent;
    int height;//高度
//    char bf;//平衡因子  二叉树上结点的 左子树深度-右子树深度
};
//avl树插入
avl_tree * avl_tree_insert(avl_tree *,int );
//avl树查询
void avl_tree_find(avl_tree *,int ,int *);
//打印avl树
void print_avltree(avl_tree *);
//释放avl树
void free_avltree(avl_tree *);
#endif //DEMO2_AVLTREE_H
