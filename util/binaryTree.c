//
// Created by daquan on 2019/1/17.
//
#include <stdio.h>
#include <stdlib.h>
#include "../header/binaryTree.h"
#include "../header/queue.h"
TreeNode* insertBinaryTree(TreeNode *treeNode,int value){
    if (treeNode==NULL){
        treeNode = calloc(1,sizeof(TreeNode));
        treeNode->value = value;
//        printf("加入%d\n",value);
        return treeNode;
    } else{
        if (treeNode->left==NULL){
//            printf("左%d\n",value);
            treeNode->left = insertBinaryTree(treeNode->left,value);
        } else if (treeNode->right==NULL){
//            printf("右%d\n",value);
            treeNode->right = insertBinaryTree(treeNode->right,value);
        } else if (treeNode->left->left==NULL||treeNode->left->right==NULL||(treeNode->right->left!=NULL&&treeNode->right->right!=NULL)){
//            printf("左节点%d\n",value);
            treeNode->left = insertBinaryTree(treeNode->left,value);
        } else{
//            printf("右节点%d\n",value);
            treeNode->right = insertBinaryTree(treeNode->right,value);
        }
    }
    return treeNode;
}
void inOrder(TreeNode *treeNode){
    if (treeNode->left!=NULL){
        inOrder(treeNode->left);
    }
    printf("%d\n",treeNode->value);
    if (treeNode->right!=NULL){
        inOrder(treeNode->right);
    }
}
void levelOrder(TreeNode *treeNode){
    Queue *queue = NULL;//队列
    Value value;//值 储存树节点
    value.TreeNode = treeNode;
    queue = enqueue(queue,value);
    while (isEmpty(queue)){
        TreeNode *node = queue->first->value.TreeNode;
        printf("%d\t",node->value);
        if (node->left!=NULL){
            value.TreeNode = node->left;
            queue = enqueue(queue,value);
        }
        if (node->right!=NULL){
            value.TreeNode = node->right;
            queue = enqueue(queue,value);
        }
        queue = dequeue(queue);
    }
}