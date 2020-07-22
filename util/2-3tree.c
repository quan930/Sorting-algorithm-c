//
// Created by 全 on 2020/7/20.
// 打印方法存在 异常可能性 可能会破坏2-3树的结构 连续打印树结构会出现异常 仅仅打印一次用于观察树结构没有影响
//
#include "../header/2-3tree.h"
#include "stdlib.h"
#include "stdio.h"
#include "../header/queue.h"
#include "math.h"
# include <string.h>

/**
 * 排序
 * @param array
 * @param length
 */
void _sort(int *array,int length){
    int temp;
    int position;
    for (int i = 0; i < length-1; ++i) {
        temp = array[i];
        position = i;
        for (int j = i+1; j < length; ++j) {
            if (array[j]<temp){
                temp = array[j];
                position = j;
            }
        }
        if (position!=i){
            array[position] = array[i];
            array[i] = temp;
        }
    }
}

/**
 * 检查节点
 * @param twoThreeTree 需要检查的节点
 * @return 根节点 返回 NULL 根没有变化
 */
two_three_tree* _check_tree(two_three_tree *twoThreeTree){
    two_three_tree *root=NULL;
    /**
     * 根节点
     */
    if (twoThreeTree->parent==NULL){
        root = calloc(1, sizeof(two_three_tree));
        root->len=1;
        root->keys[0]=twoThreeTree->keys[1];
        root->left=twoThreeTree;
        root->left->len=1;
        root->right=calloc(1, sizeof(two_three_tree));
        root->right->len=1;
        root->right->keys[0]=twoThreeTree->keys[2];
        root->right->parent=root;
        root->right->left=twoThreeTree->temp;
        root->right->right=twoThreeTree->right;
        if (root->right->left!=NULL){
            root->right->left->parent=root->right;
        }
        if (root->right->right!=NULL){
            root->right->right->parent=root->right;
        }

        root->left->parent=root;
        root->left->right=twoThreeTree->middle;
        root->left->middle=NULL;
        root->left->temp=NULL;
        return root;
    }
    /**
     * 父节点为2节点
     */
    if (twoThreeTree->parent->len==1){
        two_three_tree *treeNode = calloc(1, sizeof(two_three_tree));
        if (twoThreeTree->keys[1]<twoThreeTree->parent->keys[0]){
            //左侧插入
            twoThreeTree->parent->keys[1]=twoThreeTree->keys[1];
            twoThreeTree->parent->len++;
            _sort(twoThreeTree->parent->keys,2);
            twoThreeTree->parent->middle=treeNode;
            twoThreeTree->parent->middle->keys[0]=twoThreeTree->keys[2];
            twoThreeTree->parent->middle->len=1;
            twoThreeTree->parent->middle->left=twoThreeTree->temp;
            twoThreeTree->parent->middle->right=twoThreeTree->right;
            twoThreeTree->parent->middle->parent=twoThreeTree->parent;

            if (treeNode->left!=NULL){
                treeNode->left->parent=treeNode;
            }
            if (treeNode->right!=NULL){
                treeNode->right->parent=treeNode;
            }

            twoThreeTree->parent->left->right=twoThreeTree->middle;
            twoThreeTree->parent->left->middle=NULL;
            twoThreeTree->parent->left->temp=NULL;
            twoThreeTree->parent->left->len=1;
        } else{
            //右侧插入
            twoThreeTree->parent->keys[1]=twoThreeTree->keys[1];
            twoThreeTree->parent->len++;
            _sort(twoThreeTree->parent->keys,2);

            twoThreeTree->parent->middle=treeNode;
            twoThreeTree->parent->middle->keys[0]=twoThreeTree->keys[0];
            twoThreeTree->parent->middle->len=1;
            twoThreeTree->parent->middle->left=twoThreeTree->left;
            twoThreeTree->parent->middle->right=twoThreeTree->middle;
            twoThreeTree->parent->middle->parent=twoThreeTree->parent;

            if (treeNode->left!=NULL){
                treeNode->left->parent=treeNode;
            }
            if (treeNode->right!=NULL){
                treeNode->right->parent=treeNode;
            }

            twoThreeTree->parent->right->keys[0]=twoThreeTree->keys[2];
            twoThreeTree->parent->right->left=twoThreeTree->temp;
            twoThreeTree->parent->right->middle=NULL;
            twoThreeTree->parent->right->temp=NULL;
            twoThreeTree->parent->right->len=1;
        }
        return root;
    }
    //父节点为3节点
    if (twoThreeTree->parent->len==2){
        two_three_tree *treeNode = calloc(1, sizeof(two_three_tree));
        if (twoThreeTree->keys[1]>twoThreeTree->parent->keys[0] && twoThreeTree->keys[1]<twoThreeTree->parent->keys[1]){
            //中间
            twoThreeTree->parent->keys[2]=twoThreeTree->keys[1];
            twoThreeTree->parent->len++;
            _sort(twoThreeTree->parent->keys,3);

            twoThreeTree->parent->temp=treeNode;
            twoThreeTree->parent->temp->keys[0]=twoThreeTree->keys[2];
            twoThreeTree->parent->temp->left=twoThreeTree->temp;
            twoThreeTree->parent->temp->right=twoThreeTree->right;
            twoThreeTree->parent->temp->len=1;
//        twoThreeTree->parent->temp->parent=twoThreeTree->parent;
            treeNode->parent=twoThreeTree->parent;
            if (treeNode->left!=NULL){
                treeNode->left->parent=treeNode;
            }
            if (treeNode->right!=NULL){
                treeNode->right->parent=treeNode;
            }

            twoThreeTree->parent->middle->right=twoThreeTree->middle;
            twoThreeTree->parent->middle->temp=NULL;
            twoThreeTree->parent->middle->middle=NULL;
            twoThreeTree->parent->middle->len=1;
            root = _check_tree(twoThreeTree->parent);
        } else if(twoThreeTree->keys[1]<twoThreeTree->parent->keys[0]){
            //在左侧插入
            twoThreeTree->parent->keys[2]=twoThreeTree->keys[1];
            twoThreeTree->parent->len++;
            _sort(twoThreeTree->parent->keys,3);

            twoThreeTree->parent->temp=twoThreeTree->parent->middle;
            twoThreeTree->parent->temp->parent=twoThreeTree->parent;

            twoThreeTree->parent->middle=treeNode;
            twoThreeTree->parent->middle->keys[0]=twoThreeTree->keys[2];
            twoThreeTree->parent->middle->left=twoThreeTree->temp;
            twoThreeTree->parent->middle->right=twoThreeTree->right;
            twoThreeTree->parent->middle->len=1;
            twoThreeTree->parent->middle->parent=twoThreeTree->parent;
            if (treeNode->left!=NULL){
                treeNode->left->parent=treeNode;
            }
            if (treeNode->right!=NULL){
                treeNode->right->parent=treeNode;
            }

            twoThreeTree->parent->left->right=twoThreeTree->middle;
            twoThreeTree->parent->left->temp=NULL;
            twoThreeTree->parent->left->middle=NULL;
            twoThreeTree->parent->left->len=1;

            root = _check_tree(twoThreeTree->parent);
        } else{
            //右侧
            twoThreeTree->parent->keys[2]=twoThreeTree->keys[1];
            twoThreeTree->parent->len++;
            _sort(twoThreeTree->parent->keys,3);

            twoThreeTree->parent->temp=treeNode;
            twoThreeTree->parent->temp->keys[0]=twoThreeTree->keys[0];
            twoThreeTree->parent->temp->left=twoThreeTree->left;
            twoThreeTree->parent->temp->right=twoThreeTree->middle;
            twoThreeTree->parent->temp->len=1;
            twoThreeTree->parent->temp->parent=twoThreeTree->parent;
            if (treeNode->left!=NULL){
                treeNode->left->parent=treeNode;
            }
            if (treeNode->right!=NULL){
                treeNode->right->parent=treeNode;
            }

            twoThreeTree->parent->right->keys[0]=twoThreeTree->keys[2];
            twoThreeTree->parent->right->left=twoThreeTree->temp;
            twoThreeTree->parent->right->temp=NULL;
            twoThreeTree->parent->right->middle=NULL;
            twoThreeTree->parent->right->len=1;
            root = _check_tree(twoThreeTree->parent);
        }
    }
    return root;
}

/**
 * 查询需要出入数据的节点位置
 * @param twoThreeTree
 * @param value
 * @return 返回所在节点
 */
two_three_tree* _find_tree_location(two_three_tree *twoThreeTree,int value){
    if (twoThreeTree->len==1){
        if (twoThreeTree->keys[0]==value)
            return NULL;
    }
    if (twoThreeTree->len==2){
        if (twoThreeTree->keys[0]==value||twoThreeTree->keys[1]==value)
            return NULL;
    }

    two_three_tree *treeNode = NULL;
    if (twoThreeTree->left==NULL){
        return twoThreeTree;
    }
    if (twoThreeTree->len==1){
        if(value>twoThreeTree->keys[0]){
            treeNode = _find_tree_location(twoThreeTree->right,value);
        }else{
            treeNode = _find_tree_location(twoThreeTree->left,value);
        }
    }
    if (twoThreeTree->len==2){
        if(value>twoThreeTree->keys[1]){
            treeNode = _find_tree_location(twoThreeTree->right,value);
        } else if (value<twoThreeTree->keys[0]){
            treeNode =  _find_tree_location(twoThreeTree->left,value);
        } else{
            treeNode =  _find_tree_location(twoThreeTree->middle,value);
        }
    }
    return treeNode;
}

/**
 * 插入数据
 * @param twoThreeTree 根节点
 * @param value 插入的值
 * @return 根节点
 */
two_three_tree* two_three_tree_insert(two_three_tree *twoThreeTree,int value){
    if (twoThreeTree==NULL){
        twoThreeTree=calloc(1, sizeof(two_three_tree));
        twoThreeTree->len=1;
        twoThreeTree->keys[0]=value;
        return twoThreeTree;
    }
    /**
     * 查找位置
     */
    two_three_tree * treeNode = _find_tree_location(twoThreeTree, value);

    if (treeNode==NULL){
        return twoThreeTree;
    }
    /**
     * 增加数值 检查/修改节点
     */
     if (treeNode->len==1){
         treeNode->keys[1]=value;
         treeNode->len++;
         _sort(treeNode->keys,2);
         return twoThreeTree;
     }
    treeNode->keys[2]=value;
    treeNode->len++;
    _sort(treeNode->keys,3);
    two_three_tree *temp = _check_tree(treeNode);
    return temp==NULL?twoThreeTree:temp;
}

/**
 * 获得深度
 * @param twoThreeTree
 * @return
 */
int _get_23tree_depth(two_three_tree * twoThreeTree){
    int m=0;
    while (twoThreeTree!=NULL){
        m++;
        twoThreeTree=twoThreeTree->left;
    }
    return m;
}

/**
 * 释放-1节点
 * @param twoThreeTree
 */
void free23tree_1(two_three_tree *twoThreeTree){
    if (twoThreeTree!=NULL){
        if (twoThreeTree->keys[0]==-1){
//            printf("释放\n");
            free23tree_1(twoThreeTree->left);
            free23tree_1(twoThreeTree->middle);
            free23tree_1(twoThreeTree->right);
            free(twoThreeTree);
        } else{
            if (twoThreeTree->len==1){
                free23tree_1(twoThreeTree->left);
                free23tree_1(twoThreeTree->right);
            }
            if (twoThreeTree->len==2){
                free23tree_1(twoThreeTree->left);
                free23tree_1(twoThreeTree->middle);
                free23tree_1(twoThreeTree->right);
            }
        }
    }
}

/**
 * 打印2-3 树
 * @param twoThreeTree
 */
void print23tree(two_three_tree * twoThreeTree){
    int indexlevel=1;//当前层数
    int count=1;//当前层节点
    int temp=0;//下一行数量
    int depth = _get_23tree_depth(twoThreeTree);//树深度
    Queue *queue = NULL;//队列
    Value value;//值 储存树节点
    value.node = twoThreeTree;
    queue = enqueue(queue,value);
    two_three_tree *node;
    two_three_tree *treeNodeTemp;//临时节点
    int *prindex = calloc((int)pow(3,depth-1)+1,sizeof(int));//记录竖线位置
    int ter1=0;
    int ter2=0;
    int space_length;//空格长度
    int horizontal_length;//横线长度
    while (isEmpty(queue)&&indexlevel<=depth){
        if ((depth-indexlevel)==0){
            space_length=0;
        } else{
            space_length = (int)pow(3,depth-indexlevel-1)*17/2;
        }
        horizontal_length = (int)pow(3,depth-indexlevel)*17-2*space_length-17;
        horizontal_length = horizontal_length/2;

        ter1=0;
        ter1+=ter2;
        ter2=0;
        node = queue->first->value.node;
        for (int i = 0; i < space_length; ++i) {
            printf(" ");
            ter1+=1;
        }
        prindex[(int)pow(3,indexlevel)-count*3+0]=ter1;
        ter1=0;
        for (int i = 0; i < horizontal_length; ++i) {
            node->keys[0]==-1?printf(" "):printf("-");
            ter1+=1;
        }

        if(node->len==1){//2节点
            printf("(    %6d     )",node->keys[0]);
            prindex[(int)pow(3,indexlevel)-count*3+1]=-1;
//            prindex[3*(indexlevel-1)+1]=-1;
        } else if(node->keys[0]==-1){
            printf("                 ");
            prindex[(int)pow(3,indexlevel)-count*3+1]=-2;
        }else{
            printf("(%6d | %-6d)",node->keys[0],node->keys[1]);
            ter1+=7;
            prindex[(int)pow(3,indexlevel)-count*3+1]=ter1;
//            prindex[3*(indexlevel-1)+1]=ter1;
            ter1=0;
        }

        for (int i = 0; i < horizontal_length; ++i) {
            node->keys[0]==-1?printf(" "):printf("-");
            ter1+=1;
        }
        for (int i = 0; i < space_length; ++i) {
            printf(" ");
            ter2+=1;
        }

        ter1 += node->len!=1&&node->keys[0]!=-1 ? 7:14;
        prindex[(int)pow(3,indexlevel)-count*3+2]=ter1;
        count--;

        if (count==0&&node->left==NULL){
            printf("\n");
            break;
        }
        if (node->len==1){
            value.node = node->left;
            queue = enqueue(queue,value);
            /**
             * 有错误
             */
            treeNodeTemp = calloc(1, sizeof(two_three_tree));
            value.node = treeNodeTemp;
            treeNodeTemp->len=2;
            treeNodeTemp->keys[0]=treeNodeTemp->keys[1]=-1;
            node->middle=treeNodeTemp;
            queue = enqueue(queue,value);

            value.node = node->right;
            queue = enqueue(queue,value);
            temp+=3;
        } else if (node->keys[0]==-1){
            treeNodeTemp = calloc(1, sizeof(two_three_tree));
            value.node = treeNodeTemp;
            treeNodeTemp->len=2;
            treeNodeTemp->keys[0]=treeNodeTemp->keys[1]=-1;
            node->left=treeNodeTemp;
            value.node = treeNodeTemp;
            queue = enqueue(queue,value);

            treeNodeTemp = calloc(1, sizeof(two_three_tree));
            value.node = treeNodeTemp;
            treeNodeTemp->len=2;
            treeNodeTemp->keys[0]=treeNodeTemp->keys[1]=-1;
            node->middle=treeNodeTemp;
            value.node = treeNodeTemp;
            queue = enqueue(queue,value);

            treeNodeTemp = calloc(1, sizeof(two_three_tree));
            value.node = treeNodeTemp;
            treeNodeTemp->len=2;
            treeNodeTemp->keys[0]=treeNodeTemp->keys[1]=-1;
            node->right=treeNodeTemp;
            value.node = treeNodeTemp;
            queue = enqueue(queue,value);

            temp+=3;
        }else{
            value.node = node->left;
            queue = enqueue(queue,value);
            value.node = node->middle;
            queue = enqueue(queue,value);
            value.node = node->right;
            queue = enqueue(queue,value);
            temp+=3;
        }

        if (count==0){
            ter1=0;
            ter2=0;
            printf("\n");
            for (int i = 0; i < pow(3,depth-1); ++i) {
                if (prindex[i]==0){ break;}
                if (prindex[i+1]==-2){
                    for (int j = 0; j < prindex[i]; ++j) {
                        printf(" ");
                    }
                    printf(" ");
                    for (int j = 0; j < prindex[i+2]; ++j) {
                        printf(" ");
                    }
                    printf("  ");
                    i+=2;
                    continue;
                }
                if (prindex[i]==-1){
//                    printf("|");
                    printf(" ");
                    continue;
                }
                for (int j = 0; j < prindex[i]; ++j) {
                    printf(" ");
                }
                printf("|");
            }
            printf("\n");
            count=temp;
            temp=0;
            indexlevel++;
            ter2=0;
            memset(prindex, 0, pow(3,depth-1));
        }
        queue = dequeue(queue);
    }
    //应该释放 但是有缺陷待解决
//    free23tree_1(twoThreeTree);
//    free(prindex);
//    printf("释放完成\n");
}

/**
 * 释放2-3树
 * @param twoThreeTree
 */
void free23tree(two_three_tree *twoThreeTree){
    if (twoThreeTree!=NULL){
        if (twoThreeTree->len==1){
            free23tree(twoThreeTree->left);
            free23tree(twoThreeTree->right);
        }
        if (twoThreeTree->len==2){
            free23tree(twoThreeTree->left);
            free23tree(twoThreeTree->middle);
            free23tree(twoThreeTree->right);
        }
        free(twoThreeTree);
    }
}

/**
 * 查询2-3树
 * @param twoThreeTree 2-3根节点
 * @param vaule 需要查询的值
 * @param bool 失败-1 成功为查询值
 */
void two_three_tree_find(two_three_tree *twoThreeTree,int vaule,int *bool){
    if (twoThreeTree==NULL){
        *bool=-1;
        return;
    }
    if (twoThreeTree->len==1){
        if (twoThreeTree->keys[0]==vaule){
            *bool=vaule;
            return;
        }
        if (twoThreeTree->keys[0]>vaule){
            two_three_tree_find(twoThreeTree->left,vaule,bool);
        } else{
            two_three_tree_find(twoThreeTree->right,vaule,bool);
        }
    } else{
        if (twoThreeTree->keys[0]==vaule||twoThreeTree->keys[1]==vaule){
            *bool=vaule;
            return;
        }
        if (twoThreeTree->keys[0]>vaule){
            two_three_tree_find(twoThreeTree->left,vaule,bool);
        } else if (twoThreeTree->keys[1]<vaule){
            two_three_tree_find(twoThreeTree->right,vaule,bool);
        } else{
            two_three_tree_find(twoThreeTree->middle,vaule,bool);
        }
    }
}
