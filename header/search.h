//
// Created by 全 on 2020/7/18.
//

#ifndef DEMO2_SEARCH_H
#define DEMO2_SEARCH_H

#include "binaryTree.h"
#include "2-3tree.h"
#include "redBlackTree.h"
#include "avlTree.h"
#include "btree.h"

TreeNode* binarytree_search_assemble(int *testarr, int testlen , TreeNode *treeNode, double *time);//2叉搜索树 装配
double binarytree_search(int *testarr, int testlen ,TreeNode *treeNode);//2叉搜索树 搜索
two_three_tree* twothreetree_search_assemble(int *,int,two_three_tree *,double *);//2-3树 装配
double twothreetree_search(int *, int  ,two_three_tree *);//2-3树 搜索
red_black_tree* redblacktree_search_assemble(int *,int,red_black_tree *,double *);//红黑树 装配
double redblacktree_search(int *, int  ,red_black_tree *);//红黑树 搜索
avl_tree* avltree_search_assemble(int *,int,avl_tree *,double *);//avl树 装配
double avltree_search(int *, int  ,avl_tree *);//avl树 搜索

b_tree* btree_search_assemble(int *,int,b_tree *,double *);//b树 装配
double btree_search(int *, int  ,b_tree *);//b树 搜索

#endif //DEMO2_SEARCH_H
