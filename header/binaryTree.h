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
TreeNode* insertBinaryTree(TreeNode *,int);
void inOrder(TreeNode *);
void levelOrder(TreeNode *);
#endif //DEMO2_BINARYTREE_H
