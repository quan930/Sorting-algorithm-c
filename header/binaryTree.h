//
// Created by daquan on 2019/1/17.
//

#ifndef DEMO2_BINARYTREE_H
#define DEMO2_BINARYTREE_H
typedef struct TreeNode TreeNode;
struct TreeNode{
    int value;
    TreeNode *left;
    TreeNode *right;
};
//二叉树插入
TreeNode* binarytree_insert(TreeNode *,int );
//二叉树查询
void binarytree_find(TreeNode *,int ,int *);
//打印二叉搜索树 空节点不打印 限制值小于100000
void printtree(TreeNode *);
//完全打印二叉树 空节点 -1代替
void printtree_complete(TreeNode *);
//中顺遍历二叉树
void inOrder(TreeNode *);
//层序遍历二叉树
void levelOrder(TreeNode *);
//释放
void freetree(TreeNode *);
#endif //DEMO2_BINARYTREE_H
