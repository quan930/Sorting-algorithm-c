//
// Created by daquan on 2019/1/17.
//
#include <stdio.h>
#include <stdlib.h>
#include "../header/binaryTree.h"
#include "../header/queue.h"

/**
 * 插入节点
 * @param treeNode
 * @param vaule
 * @return
 */
TreeNode* binarytree_insert(TreeNode *treeNode,int vaule){
    if (treeNode==NULL){
        treeNode = calloc(1,sizeof(TreeNode));
        treeNode->value=vaule;
        return treeNode;
    }
    if (vaule>treeNode->value){
        treeNode->right = binarytree_insert(treeNode->right,vaule);
    }
    if (vaule<treeNode->value){
        treeNode->left = binarytree_insert(treeNode->left,vaule);
    }
    return treeNode;
}


/**
 * 查询指定值
 * @param treeNode
 * @param vaule
 * @param bool
 */
void binarytree_find(TreeNode *treeNode,int vaule,int *bool){
    if (treeNode==NULL){
//        printf("\t为null\t");
        *bool=-1;
        return;
    }
    if (treeNode->value==vaule){
//        printf("\t找到%d\t",vaule);
        *bool=vaule;
        return;
    }
    if (treeNode->value>vaule){
//        printf("\t%d往左\t",vaule);
        binarytree_find(treeNode->left,vaule,bool);
    }
    if (treeNode->value<vaule){
//        printf("\t%d往右\t",vaule);
        binarytree_find(treeNode->right,vaule,bool);
    }
}

/**
 * 获得二叉树的深度
 * @param T 二叉树指针
 * @return 深度
 */
int get_tree_depth(TreeNode *T)
{
    int leftHeight, rightHeight, maxHeight;
    if (T != NULL) {
        leftHeight = get_tree_depth(T->left);
        rightHeight = get_tree_depth(T->right);
        maxHeight = leftHeight>rightHeight?leftHeight:rightHeight;
        return maxHeight+1;
    } else {
        return 0;
    }
}

/**
 * 中序遍历二叉树
 * @param treeNode
 */
void inOrder(TreeNode *treeNode){
    if (treeNode->left!=NULL){
        inOrder(treeNode->left);
    }
    printf("%d\t",treeNode->value);
    if (treeNode->right!=NULL){
        inOrder(treeNode->right);
    }
}

/**
 * 层序遍历二叉树
 * @param treeNode
 */
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

/**
 * 完全打印二叉树 空节点 -1代替
 * @param treeNode 跟节点
 */
void printtree_complete(TreeNode *treeNode){
    int indexlevel=1;//当前层数
    int count=1;//当前层节点
    int temp=0;//下一行
    int depth = get_tree_depth(treeNode);//树深度
    Queue *queue = NULL;//队列
    Value value;//值 储存树节点
    value.TreeNode = treeNode;
    queue = enqueue(queue,value);
    TreeNode *node;
    TreeNode treeNodeTemp;
    treeNodeTemp.value=-1;
    int *prindex = calloc(1<<(depth-1),sizeof(TreeNode));//记录竖线位置
    int ter1=0;
    int ter2=0;
    while (isEmpty(queue)&&indexlevel<=depth){
        ter1=0;
        ter1+=ter2;
        ter2=0;
        node = queue->first->value.TreeNode;
        for (int i = 1; i < 1<<(depth-indexlevel); ++i) {
            printf("   ");
            ter1+=3;
        }
        prindex[(1<<(indexlevel))-count*2]=ter1;
        ter1=0;
        for (int i = 1; i < 1<<(depth-indexlevel); ++i) {
            printf("---");
            ter1+=3;
        }
//        node->value!=-1?printf("%6d",node->value):printf("      ");
        printf(" (%5d) ",node->value);
        for (int i = 1; i < 1<<(depth-indexlevel); ++i) {
            printf("---");
            ter1+=3;
        }
        for (int i = 0; i < 1<<(depth-indexlevel); ++i) {
            printf("   ");
            ter2+=3;
        }
        ter1+=7;
        prindex[(1<<(indexlevel))-count*2+1]=ter1;
        count--;
        if (node->value==-1){
            value.TreeNode = &treeNodeTemp;
            queue = enqueue(queue,value);
            value.TreeNode = &treeNodeTemp;
            queue = enqueue(queue,value);
            temp++;
            temp++;
        } else{
            if (node->left!=NULL){
                value.TreeNode = node->left;
                queue = enqueue(queue,value);
            } else{
                value.TreeNode = &treeNodeTemp;
                queue = enqueue(queue,value);
            }
            temp++;
            if (node->right!=NULL){
                value.TreeNode = node->right;
                queue = enqueue(queue,value);
            } else{
                value.TreeNode = &treeNodeTemp;
                queue = enqueue(queue,value);
            }
            temp++;
        }
        if (count==0){
            ter1=0;
            ter2=0;
            printf("\n");
            for (int i = 0; i < 1<<(depth-1); ++i) {
                if (prindex[i]==0){ break;}
                for (int j = 0; j < prindex[i]; ++j) {
                    printf(" ");
                }
                printf("|");
            }
            printf("\n");
            count=temp;
            temp=0;
            indexlevel++;
        }
        queue = dequeue(queue);
    }
}

/**
 * 打印二叉搜索树 空节点不打印 限制值小于100000
 * @param treeNode 根节点
 */
void printtree(TreeNode *treeNode){
    int indexlevel=1;//当前层数
    int count=1;//当前层节点
    int temp=0;//下一行
    int depth = get_tree_depth(treeNode);//树深度
    Queue *queue = NULL;//队列
    Value value;//值 储存树节点
    value.TreeNode = treeNode;
    queue = enqueue(queue,value);
    TreeNode *node;
    TreeNode treeNodeTemp={.value=-1};
    int *prindex = calloc(1<<(depth-1),sizeof(TreeNode));//记录竖线位置
    int *prbool = calloc(1<<(depth-1),sizeof(TreeNode));//记录是否有竖线
    int ter1=0;
    int ter2=0;
    while (isEmpty(queue)&&indexlevel<=depth){
        ter1=0;
        ter1+=ter2;
        ter2=0;
        node = queue->first->value.TreeNode;
        for (int i = 1; i < 1<<(depth-indexlevel); ++i) {
            printf("   ");
            ter1+=3;
        }
        prindex[(1<<(indexlevel))-count*2]=ter1;
        prbool[(1<<(indexlevel))-count*2]=node->value!=-1?1:0;
        ter1=0;
        for (int i = 1; i < 1<<(depth-indexlevel); ++i) {
            node->value!=-1?printf("---"):printf("   ");
            ter1+=3;
        }
        node->value!=-1?printf(" (%5d) ",node->value):printf("         ");
        for (int i = 1; i < 1<<(depth-indexlevel); ++i) {
            node->value!=-1?printf("---"):printf("   ");
            ter1+=3;
        }
        for (int i = 0; i < 1<<(depth-indexlevel); ++i) {
            printf("   ");
            ter2+=3;
        }
        ter1+=7;
        prindex[(1<<(indexlevel))-count*2+1]=ter1;
        prbool[(1<<(indexlevel))-count*2+1]=node->value!=-1?1:0;
        count--;
        if (node->value==-1){//空节点
            value.TreeNode = &treeNodeTemp;
            queue = enqueue(queue,value);
            value.TreeNode = &treeNodeTemp;
            queue = enqueue(queue,value);
            temp+=2;
        } else{
            if (node->left!=NULL){//左节点
                value.TreeNode = node->left;
            } else{
                value.TreeNode = &treeNodeTemp;
            }
            queue = enqueue(queue,value);
            if (node->right!=NULL){//右节点
                value.TreeNode = node->right;
            } else{
                value.TreeNode = &treeNodeTemp;
            }
            queue = enqueue(queue,value);
            temp+=2;
        }
        if (count==0){
            ter2=0;
            printf("\n");
            for (int i = 0; i < 1<<(depth-1); ++i) {
                if (prindex[i]==0){ break;}
                for (int j = 0; j < prindex[i]; ++j) {
                    printf(" ");
                }
                prbool[i]==1?printf("|"):printf(" ");
            }
            printf("\n");
            count=temp;
            temp=0;
            indexlevel++;
        }
        queue = dequeue(queue);
    }
    free(prindex);
    free(prbool);
}

/**
 * 释放二叉树
 * @param treeNode
 */
void freetree(TreeNode *treeNode){
    if (treeNode!=NULL){
        freetree(treeNode->left);
        freetree(treeNode->right);
        free(treeNode);
    }
}