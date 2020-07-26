//
// Created by 全 on 2020/7/25.
//
#include "../header/avlTree.h"
#include "stdlib.h"
#include "stdio.h"
#include "../header/queue.h"
#include "../header/coloredfont.h"

/**
 * 获得当前树的高度
 * @param N 树的根结点
 * @return 树的高度
 */
int height(avl_tree *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

/**
 * 返回最大值
 * @param a
 * @param b
 * @return
 */
int max(int a, int b)
{
    return (a > b)? a : b;
}

/**
 * 获得平衡因子
 * @param N
 * @return
 */
int getBF(avl_tree *N){
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

/**
 * 右旋
 * @param treeX x节点
 * @param treeY y节点
 * @return 返回x点
 */
avl_tree* _avl_rotate_right(avl_tree *treeX,avl_tree *treeY){
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

    // 更新高度
    treeY->height = max(height(treeY->left), height(treeY->right))+1;
    treeX->height = max(height(treeX->left), height(treeX->right))+1;

    return treeX;
}

/**
 * 左旋
 * @param treeX x节点
 * @param treeY y节点
 * @return 返回Y点
 */
avl_tree* _avl_rotate_left(avl_tree *treeX,avl_tree *treeY){
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

    // 更新高度
    treeX->height = max(height(treeX->left), height(treeX->right))+1;
    treeY->height = max(height(treeY->left), height(treeY->right))+1;
    return treeY;
}

/**
 * avl 树修正
 * @param treeNode 需要修正的结点
 * @param root 根结点
 * @return 根结点
 */
avl_tree* _avltree_fixup(avl_tree *treeNode,avl_tree *root){
    while (treeNode!=NULL){
        //平衡因子绝对值小于1
        if (getBF(treeNode)<=1){
            if (treeNode->parent==NULL){
                return root;
            }
//            printf("平衡因子为:%d\n",getBF(treeNode->parent));
            if (getBF(treeNode->parent)==0){
//                printf("平衡\n");
                return root;
            }
            treeNode->parent->height+=1;
            treeNode = treeNode->parent;
//            continue;
        }
        //情况1
        //z的平衡因子为+2 z的左孩子平衡因子为-1
        if (getBF(treeNode)==2&&getBF(treeNode->left)==-1){
//            printf("情况1\n");
            treeNode = _avl_rotate_left(treeNode->left,treeNode->left->right)->parent;
            //进入情况2
//            printf("进入情况2\n");
        }
        //情况2
        //z的平衡因子为+2，z的左孩子平衡因子为+1(或为+2)
        if (getBF(treeNode)==2&&(getBF(treeNode->left)==1||getBF(treeNode->left)==2)){
//            printf("情况2\n");
            treeNode = _avl_rotate_right(treeNode->left,treeNode);
            if (treeNode->parent==NULL){
                return treeNode;
            }
            return root;
        }
        //情况3
        //z的平衡因子为-2，z的右孩子平衡因子为+1
        if (getBF(treeNode)==-2 && getBF(treeNode->right)==1){
//            printf("情况3\n");
            treeNode = _avl_rotate_right(treeNode->right->left,treeNode->right)->parent;
            //进入情况4
        }
        //情况4
        //z的平衡因子为-2，z的右孩子平衡因子为-1(或为-2)
        if(getBF(treeNode)==-2 && (getBF(treeNode->right)==-1||getBF(treeNode->right)==-2)){
//            printf("情况4\n");
            treeNode = _avl_rotate_left(treeNode,treeNode->right);
            if (treeNode->parent==NULL){
                return treeNode;
            }
            return root;
        }
    }

    return root;
}

/**
 * 插入结点
 * @param avlTree 根节点
 * @param value 需要插入的值
 * @return 插入的节点 重复数据返回NULL
 */
avl_tree* _avl_tree_insert_node(avl_tree *avlTree,int value){
    avl_tree *treeNode = NULL;
    if (avlTree->key==value){
        return treeNode;
    }
    if (value>avlTree->key){
        if (avlTree->right==NULL){
            treeNode=calloc(1, sizeof(avl_tree));
            treeNode->key=value;
            treeNode->height=1;
            //父子 相连
            treeNode->parent=avlTree;
            avlTree->right=treeNode;
            return treeNode;
        }
        treeNode = _avl_tree_insert_node(avlTree->right,value);
    } else{
        if (avlTree->left==NULL){
            treeNode=calloc(1, sizeof(avl_tree));
            treeNode->key=value;
            treeNode->height=1;
            //父子 相连
            treeNode->parent=avlTree;
            avlTree->left=treeNode;
            return treeNode;
        }
        treeNode = _avl_tree_insert_node(avlTree->left,value);
    }
    return treeNode;
}

/**
 * avl树 插入
 * @param avlTree 根结点
 * @param value 插入的值
 * @return 根结点
 */
avl_tree * avl_tree_insert(avl_tree * avlTree,int value){
    if (avlTree==NULL){
        avlTree=calloc(1, sizeof(avl_tree));
        avlTree->key=value;
        avlTree->height=1;
        return avlTree;
    }
    avl_tree * treeNode = _avl_tree_insert_node(avlTree,value);
    if (treeNode == NULL){
        //重复数据
        return avlTree;
    }
    //修正树结构
//    printf("开始修正\n");
    avl_tree *p =  _avltree_fixup(treeNode,avlTree);
//    printf("结束修正\n");
    return p;
}



/**
 * 打印avl 树
 * @param avlTree 根结点
 */
void print_avltree(avl_tree* avlTree){
    int indexlevel=1;//当前层数
    int count=1;//当前层节点
    int temp=0;//下一行
    int depth=avlTree->height;
    Queue *queue = NULL;//队列
    Value value;//值 储存树节点
    value.node = avlTree;
    queue = enqueue(queue,value);
    avl_tree *node;
    avl_tree treeNodeTemp={.key=-1};
    int *prindex = calloc(1<<(depth-1),sizeof(avl_tree));//记录竖线位置
    int *prbool = calloc(1<<(depth-1),sizeof(avl_tree));//记录是否有竖线
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
        if (node->key!=-1){
            printf("(");
            print_colors_font(REDS,"%2d",2,getBF(node));
            printf("%5d)",node->key);
        } else{
            printf("         ");
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
}

/**
 * 查询指定值
 * @param avlTree avl树跟节点
 * @param value
 * @param bool 成功返回value 否则为-1
 */
void avl_tree_find(avl_tree * avlTree,int value,int *bool){
    if (avlTree==NULL){
        *bool=-1;
//        printf("\t为null\t");
        return;
    }
    if (avlTree->key==value){
        *bool=value;
//        printf("\t找到%d\t",value);
        return;
    }
    if (avlTree->key>value){
        avl_tree_find(avlTree->left,value,bool);
//        printf("\t%d往左\t",value);
    }
    if (avlTree->key<value){
        avl_tree_find(avlTree->right,value,bool);
//        printf("\t%d往右\t",value);
    }
}

/**
 * 释放avl 树
 * @param avlTree avl根结点
 */
void free_avltree(avl_tree *avlTree){
    if (avlTree!=NULL){
        free_avltree(avlTree->left);
        free_avltree(avlTree->right);
        free(avlTree);
    }
}