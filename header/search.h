//
// Created by 全 on 2020/7/18.
//

#ifndef DEMO2_SEARCH_H
#define DEMO2_SEARCH_H

#include "binaryTree.h"
#include "2-3tree.h"
#include "redBlackTree.h"

TreeNode* binarytree_search_assemble(int *testarr, int testlen , TreeNode *treeNode, double *time);//2叉搜索树 装配
double binarytree_search(int *testarr, int testlen ,TreeNode *treeNode);//2叉搜索树 搜索
two_three_tree* twothreetree_search_assemble(int *,int,two_three_tree *,double *);//2-3树 装配
double twothreetree_search(int *, int  ,two_three_tree *);//2叉搜索树 搜索
red_black_tree* redblacktree_search_assemble(int *,int,red_black_tree *,double *);//红黑树 装配
double redblacktree_search(int *, int  ,red_black_tree *);//2叉搜索树 搜索
#endif //DEMO2_SEARCH_H
