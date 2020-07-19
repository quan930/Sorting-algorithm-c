//
// Created by 全 on 2020/7/18.
// 二叉查找树
//
#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include "../header/binaryTree.h"


/**
 * 二叉树查询
 * @param testarr 测试数组
 * @param testlen 测试数组长度
 * @param treeNode 二叉树根结点
 */
void _binarytree_search(int *testarr, int testlen , TreeNode *treeNode){
    if (treeNode==NULL){
        return;
    }
    int bool=0;
    for (int i = 0; i < testlen; ++i) {
//        printf("查询%d\n",testarr[i]);
        binarytree_find(treeNode,testarr[i],&bool);
        if (bool==-1||bool!=testarr[i])
            printf("查询失败\n");
    }
}

/**
 * 二叉查找树 查询
 * @param testarr 测试数组
 * @param testlen 测试数组长度
 * @param treeNode 二叉树根结点
 * @return 二叉查找树查询时间(秒)
 */
double binarytree_search(int *testarr, int testlen , TreeNode *treeNode){
    clock_t start,finish;double time;
    start = clock();

    _binarytree_search(testarr,testlen,treeNode);

    finish = clock();
    freetree(treeNode);//释放
    time = (double)(finish - start) / CLOCKS_PER_SEC;
    return time;
}

/**
 * 二叉树装配
 * @param testarr 测试数组
 * @param testlen 测试数组长度
 * @param treeNode 二叉树根结点
 * @return 根节点
 */
TreeNode* _binarytree_search_assemble(int *testarr, int testlen ,TreeNode *treeNode){
    if (treeNode==NULL){
        treeNode = calloc(1,sizeof(TreeNode));
        treeNode->value=testarr[0];
    }
    for (int i = 0; i < testlen; ++i) {
        binarytree_insert(treeNode,testarr[i]);
//        printf("插入值为:%d\n",testarr[i]);
//        printtree(treeNode);
    }
//    printtree(treeNode);
    return treeNode;
}

 /**
  * 二叉查找树 装配
  * @param testarr 测试数组
  * @param testlen 测试数组长度
  * @param treeNode 二叉树根结点
  * @param time 二叉查找树装配时间(秒)
  * @return 二叉树根结点
  */
TreeNode * binarytree_search_assemble(int *testarr, int testlen , TreeNode *treeNode, double *time){
    clock_t start,finish;
    start = clock();

    TreeNode *p = _binarytree_search_assemble(testarr,testlen,treeNode);

    finish = clock();
    *time = (double)(finish - start) / CLOCKS_PER_SEC;
    return p;
}