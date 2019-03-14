//
// Created by daquan on 2019/3/14.
// 层序遍历二叉树
//
#include "stdio.h"
#include "../header/binaryTree.h"
int main(){
    TreeNode *treeNode=NULL;
    for (int i = 1; i <= 10; ++i) {
        treeNode = insertBinaryTree(treeNode,i);
    }
    printf("右序便利:");
    inOrder(treeNode);
    printf("\n层序便利:");
    levelOrder(treeNode);
}
