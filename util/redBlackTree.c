#include "../header/redBlackTree.h"
#include "stdlib.h"
#include "stdio.h"
#include "../header/queue.h"
#include "../header/coloredfont.h"

//
// Created by 全 on 2020/7/24.
// 实现旋转插入操作 参照已经整理好的博客 如下
// https://www.jianshu.com/p/b468a454b159
//

/**
 * 释放-1节点
 * @param redBlackTree
 */
void _free_rbtree_1(red_black_tree *redBlackTree){
    if (redBlackTree!=NULL){
        if (redBlackTree->key==-1){
            _free_rbtree_1(redBlackTree->left);
            _free_rbtree_1(redBlackTree->right);
            free(redBlackTree);
//            printf("释放\n");
        } else{
            _free_rbtree_1(redBlackTree->left);
            _free_rbtree_1(redBlackTree->right);
        }
    }
}


/**
 * 释放红黑树
 * @param redBlackTree
 */
void free_rbtree(red_black_tree *redBlackTree){
    if (redBlackTree!=NULL){
        free_rbtree(redBlackTree->left);
        free_rbtree(redBlackTree->right);
        free(redBlackTree);
    }
}

/**
 * 获得红黑树的深度
 * @param T 二叉树指针
 * @return 深度
 */
int _get_rbtree_depth(red_black_tree *T)
{
    int leftHeight, rightHeight, maxHeight;
    if (T != NULL) {
        leftHeight = _get_rbtree_depth(T->left);
        rightHeight = _get_rbtree_depth(T->right);
        maxHeight = leftHeight>rightHeight?leftHeight:rightHeight;
        return maxHeight+1;
    } else {
        return 0;
    }
}
/**
 * 打印红黑树
 * @param redBlackTree
 */
void print_rbtree(red_black_tree * redBlackTree){
    int indexlevel=1;//当前层数
    int count=1;//当前层节点
    int temp=0;//下一行
    int depth = _get_rbtree_depth(redBlackTree);//树深度
    Queue *queue = NULL;//队列
    Value value;//值 储存树节点
    value.node = redBlackTree;
    queue = enqueue(queue,value);
    red_black_tree *node;
    red_black_tree treeNodeTemp={.key=-1};
    int *prindex = calloc(1<<(depth-1),sizeof(red_black_tree));//记录竖线位置
    int *prbool = calloc(1<<(depth-1),sizeof(red_black_tree));//记录是否有竖线
    int ter1=0;
    int ter2=0;
    while (isEmpty(queue)&&indexlevel<=depth){
        ter1=0;
        ter1+=ter2;
        ter2=0;
        node = queue->first->value.node;
        for (int i = 1; i < 1<<(depth-indexlevel); ++i) {
            printf("   ");
            ter1+=3;
        }
        prindex[(1<<(indexlevel))-count*2]=ter1;
        prbool[(1<<(indexlevel))-count*2]=node->key!=-1?1:0;
        ter1=0;
        for (int i = 1; i < 1<<(depth-indexlevel); ++i) {
            node->key!=-1?printf("---"):printf("   ");
            ter1+=3;
        }
        if (node->color==RED && node->key!=-1){
            print_colors_font(REDS,"( %5d )",9,node->key);
        } else{
            node->key!=-1?printf("( %5d )",node->key):printf("         ");
        }
        for (int i = 1; i < 1<<(depth-indexlevel); ++i) {
            node->key!=-1?printf("---"):printf("   ");
            ter1+=3;
        }
        for (int i = 0; i < 1<<(depth-indexlevel); ++i) {
            printf("   ");
            ter2+=3;
        }
        ter1+=7;
        prindex[(1<<(indexlevel))-count*2+1]=ter1;
        prbool[(1<<(indexlevel))-count*2+1]=node->key!=-1?1:0;
        count--;
        if (node->key==-1){//空节点
            value.node = &treeNodeTemp;
            queue = enqueue(queue,value);
            value.node = &treeNodeTemp;
            queue = enqueue(queue,value);
            temp+=2;
        } else{
            if (node->left!=NULL){//左节点
                value.node = node->left;
            } else{
                value.node = &treeNodeTemp;
            }
            queue = enqueue(queue,value);
            if (node->right!=NULL){//右节点
                value.node = node->right;
            } else{
                value.node = &treeNodeTemp;
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
    _free_rbtree_1(redBlackTree);
}

 /**
  * 插入红节点
  * @param redBlackTree 根节点
  * @param value 需要插入的值
  * @return 插入的红色节点 重复数据返回NULL
  */
red_black_tree *  _red_black_tree_insert_rednode(red_black_tree * redBlackTree,int value){
    red_black_tree *treeNode = NULL;
    if (redBlackTree->key==value){
        return treeNode;
    }
    if (value>redBlackTree->key){
        if (redBlackTree->right==NULL){
            treeNode=calloc(1, sizeof(red_black_tree));
            treeNode->key=value;
            treeNode->color=RED;
            //父子 相连
            treeNode->parent=redBlackTree;
            redBlackTree->right=treeNode;
            return treeNode;
        }
        treeNode = _red_black_tree_insert_rednode(redBlackTree->right,value);
    } else{
        if (redBlackTree->left==NULL){
            treeNode=calloc(1, sizeof(red_black_tree));
            treeNode->key=value;
            treeNode->color=RED;
            //父子 相连
            treeNode->parent=redBlackTree;
            redBlackTree->left=treeNode;
            return treeNode;
        }
        treeNode = _red_black_tree_insert_rednode(redBlackTree->left,value);
    }
    return treeNode;
}


 /**
  * 右旋
  * @param treeX x节点
  * @param treeY y节点
  * @return 返回x点
  */
red_black_tree* _rotate_right(red_black_tree *treeX,red_black_tree *treeY){
    treeY->left = treeX->right;
    if (treeX->right!=NULL){
        treeY->left->parent=treeY;
    }

    treeX->parent=treeY->parent;
    if (treeX->parent!=NULL){
        if (treeX->parent->key>treeX->key){
            treeX->parent->left=treeX;
        } else{
            treeX->parent->right=treeX;
        }
    }

    treeX->right=treeY;
    treeY->parent=treeX;

    return treeX;
}

/**
 * 左旋
 * @param treeX x节点
 * @param treeY y节点
 * @return 返回Y点
 */
red_black_tree* _rotate_left(red_black_tree *treeX,red_black_tree *treeY){
    treeX->right = treeY->left;
    if (treeY->left!=NULL){
        treeX->right->parent=treeX;
    }
    treeY->parent=treeX->parent;
    if (treeX->parent!=NULL){
        if (treeY->parent->key>treeY->key){
            treeY->parent->left=treeY;
        } else{
            treeY->parent->right=treeY;
        }
    }
    treeY->left=treeX;
    treeX->parent=treeY;
    return treeY;
}

/**
 * 红黑树修正
 * @param treeNode 需要检查的节点
 * @param root 根节点
 * @return 返回根节点
 */
red_black_tree * _rbtree_fixup(red_black_tree * treeNode,red_black_tree *root){
    if (treeNode->parent->color==BLACK){
        return root;
    }
    while (treeNode->parent->color==RED){
        //情况1 叔结点和父结点 同为红
        if (treeNode->parent->parent->right!=NULL&&treeNode->parent->parent->left!=NULL){
            if (treeNode->parent->parent->left->color==RED&&treeNode->parent->parent->right->color==RED){
                treeNode->parent->parent->left->color=BLACK;
                treeNode->parent->parent->right->color=BLACK;
                treeNode->parent->parent->color=RED;
                treeNode = treeNode->parent->parent;
                if (treeNode->parent==NULL){
                    break;
                }
                continue;
            }
        }
        //情况2 情况3 父结点是爷结点的左孩子
        if(treeNode->parent->key<treeNode->parent->parent->key){
            //情况2 treeNode的叔结点是黑色，且treeNode是一个右孩子 旋转后变为情况3
            if (treeNode->key>treeNode->parent->key){
//                printf("左旋转2\n");
                treeNode = _rotate_left(treeNode->parent,treeNode)->left;
            }
            //情况3 treeNode的叔结点是黑色，且treeNode是一个左孩子
            if (treeNode->key<treeNode->parent->key){
                treeNode->parent->color=BLACK;
                treeNode->parent->parent->color=RED;
//                printf("右旋转3\n");
                treeNode = _rotate_right(treeNode->parent,treeNode->parent->parent);
                if (treeNode->parent==NULL){
                    return treeNode;
                }
                break;
            }
        }
        //情况4 情况5 父结点是爷结点的右孩子
        if (treeNode->parent->key>treeNode->parent->parent->key){
            //情况4 treeNode的叔结点是黑色，且treeNode是一个左孩子 旋转后变为情况5
            if (treeNode->key<treeNode->parent->key){
//                printf("右旋转4\n");
                treeNode = _rotate_right(treeNode,treeNode->parent)->right;
            }
            //情况5 treeNode的叔结点是黑色，且treeNode是一个右孩子
            if (treeNode->key>treeNode->parent->key){
                treeNode->parent->color=BLACK;
                treeNode->parent->parent->color=RED;
//                printf("左旋转5\n");
                treeNode = _rotate_left(treeNode->parent->parent,treeNode->parent);
                if (treeNode->parent==NULL){
                    return treeNode;
                }
                break;
            }
        }
    }
    root->color=BLACK;
    return root;
}

/**
 * 红黑树插入
 * @param redBlackTree 根节点
 * @param value 插入的值
 * @return 根节点
 */
red_black_tree * red_black_tree_insert(red_black_tree * redBlackTree,int value){
    if (redBlackTree==NULL){
        redBlackTree=calloc(1, sizeof(red_black_tree));
        redBlackTree->key=value;
        redBlackTree->color=BLACK;
        return redBlackTree;
    }
    red_black_tree * treeNode = _red_black_tree_insert_rednode(redBlackTree,value);
//    printf("插入红结点\n");
    if (treeNode == NULL){
        //重复数据
        return redBlackTree;
    }
    //修正树结构
    return _rbtree_fixup(treeNode,redBlackTree);
}

/**
 * 查询指定值
 * @param redBlackTree 红黑树跟节点
 * @param value
 * @param bool 成功返回value 否值为-1
 */
void red_black_tree_find(red_black_tree *redBlackTree,int value,int *bool){
    if (redBlackTree==NULL){
        *bool=-1;
//        printf("\t为null\t");
        return;
    }
    if (redBlackTree->key==value){
        *bool=value;
//        printf("\t找到%d\t",value);
        return;
    }
    if (redBlackTree->key>value){
        red_black_tree_find(redBlackTree->left,value,bool);
//        printf("\t%d往左\t",value);
    }
    if (redBlackTree->key<value){
        red_black_tree_find(redBlackTree->right,value,bool);
//        printf("\t%d往右\t",value);
    }
}
