//
// Created by 全 on 2020/7/20.
//

#ifndef DEMO2_2_3TREE_H
#define DEMO2_2_3TREE_H

typedef struct two_three_tree two_three_tree;
struct two_three_tree{
    int keys[3];
    int len;
    two_three_tree *left;
    two_three_tree *middle;
    two_three_tree *right;
    two_three_tree *temp;
    two_three_tree *parent;
    //left mid temp right
};
//2-3树插入
two_three_tree * two_three_tree_insert(two_three_tree *,int );
//2-3树查询
void two_three_tree_find(two_three_tree *,int ,int *);
//打印2-3树
void print23tree(two_three_tree *);
//释放2-3树
void free23tree(two_three_tree *);
#endif //DEMO2_2_3TREE_H
