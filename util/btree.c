//
// Created by 全 on 2020/7/28.
//

#include "../header/btree.h"
#include "stdlib.h"
#include "stdio.h"
#include "../header/queue.h"

/**
 * 查询需要插入位置的结点结点位置
 * @param bTree
 * @param value
 * @return
 */
b_tree* _find_btree_location(b_tree *bTree,int value){
    //为叶结点
    if (bTree==NULL){
        return NULL;
    }
    if(bTree->child[0]==NULL){
        for (int i = 0; i < bTree->len; ++i) {
            if (bTree->keys[i]==value){
                return NULL;
            }
        }
        return bTree;
    }
    if (bTree->keys[0]>value){
        //小于最小值
        return _find_btree_location(bTree->child[0],value);
    } else if (bTree->keys[bTree->len-1]<value){
        //大于最大值
        return _find_btree_location(bTree->child[bTree->len],value);
    } else{
        for (int i = 0; i < bTree->len; ++i) {
            if (bTree->keys[i]==value){
                return NULL;
            }
            if (bTree->keys[i]>value){
                return _find_btree_location(bTree->child[i],value);
            }
        }
    }
    return NULL;
}

/**
 * 排序b树 key
 * @param array
 * @param length 数组长度
 * @return 末位的值插入后 所在的索引
 */
int _b_sort(int *array,int length){
    int m=array[length-1];//新插入的值
    for (int i = 0; i < length; ++i) {
        if (m<array[i]){
            for (int j = length-1; j > i; --j) {
                array[j]=array[j-1];
            }
            array[i]=m;
            return i;
        }
    }
    return length-1;
}

/**
 * 检查节点 并不完美 阶数M小于5会出现问题
 * @param treeNode 需要检查的节点
 * @return 根节点 返回 NULL 根没有变化
 */
b_tree* _btree_fixup(b_tree *treeNode){
    //根结点处理情况
    if (treeNode->parent==NULL){//根结点分裂
        int midValue=treeNode->keys[M/2];
        treeNode->parent=calloc(1, sizeof(b_tree));
        b_tree *root = treeNode->parent;
        root->keys[0]=midValue;
        root->child[0]=treeNode;
        root->child[1]=calloc(1, sizeof(b_tree));
        root->child[1]->parent=root;
        root->len=1;
        root->child[1]->len=0;
        for (int i = M/2+1,k=0; i <= M-1; ++i,k++) {
            root->child[1]->keys[k]=treeNode->keys[i];
            root->child[1]->child[k]=treeNode->child[i];
            if (root->child[1]->child[k]!=NULL){
                root->child[1]->child[k]->parent=root->child[1];
            }
            root->child[1]->len++;
        }
        root->child[1]->child[root->child[1]->len]=treeNode->child[M];
        if (root->child[1]->child[root->child[1]->len]!=NULL){
            root->child[1]->child[root->child[1]->len]->parent=root->child[1];
        }
        treeNode->child[treeNode->len]=NULL;
        for (int i = M/2; i <= M-1; ++i) {
            treeNode->keys[i]=0;
            treeNode->child[i+1]=NULL;
            treeNode->len--;
        }
        return root;
    }
    /**
     * 非根结点处理
     */
    //取中间值
    int midValue=treeNode->keys[M/2];

    treeNode->parent->keys[treeNode->parent->len]=midValue;
    treeNode->parent->len++;
    int m = _b_sort(treeNode->parent->keys,treeNode->parent->len);

    //移动父结点的孩子
    if (m<treeNode->parent->len){
//        printf("移动\t");
        for (int i = treeNode->parent->len; i >= m+2; --i) {
            treeNode->parent->child[i]=treeNode->parent->child[i-1];
        }
    }
    treeNode->parent->child[m+1]=calloc(1, sizeof(b_tree));
    treeNode->parent->child[m+1]->len=0;
    treeNode->parent->child[m+1]->parent=treeNode->parent;
    //分裂
    /**
     * 孙子处理
     * 右兄弟结点处理
     */
    for (int i = M/2+1,k=0; i <= M-1; ++i,k++) {
//        printf("拷贝%d\t",treeNode->keys[i]);
        treeNode->parent->child[m+1]->len+=1;
        treeNode->parent->child[m+1]->keys[k]=treeNode->keys[i];
        treeNode->parent->child[m+1]->child[k]=treeNode->child[i];
        if (treeNode->parent->child[m+1]->child[k]!=NULL){
//            printf("拷贝孙结点%d:",treeNode->parent->child[m+1]->child[k]->keys[0]);
            treeNode->parent->child[m+1]->child[k]->parent=treeNode->parent->child[m+1];
        }
    }
    treeNode->parent->child[m+1]->child[treeNode->parent->child[m+1]->len]=treeNode->child[M];
    if (treeNode->parent->child[m+1]->child[treeNode->parent->child[m+1]->len]!=NULL){
//        printf("拷贝孙结点%d:",treeNode->parent->child[m+1]->child[treeNode->parent->child[m+1]->len]->keys[0]);
        treeNode->parent->child[m+1]->child[treeNode->parent->child[m+1]->len]->parent=treeNode->parent->child[m+1];
    }
    /**
     * 自身处理
     */
    for (int i = M/2; i < M; ++i) {
        treeNode->keys[i]=0;
        treeNode->child[i+1]=NULL;
        treeNode->len--;
    }
    /**
     * 判断父结点是否为超过结点
     */
     if (treeNode->parent->len>M-1){
         return _btree_fixup(treeNode->parent);
     }
     return NULL;
}

/**
 *
 * @param bTree
 * @param value
 * @return
 */
b_tree * b_tree_insert(b_tree *bTree,int value){
    //根结点为NULL
    if (bTree==NULL){
        bTree=calloc(1, sizeof(b_tree));
        bTree->keys[0]=value;
        bTree->len=1;
        return bTree;
    }
    /**
     * 查找位置
     */
    b_tree * treeNode = _find_btree_location(bTree, value);

    if (treeNode==NULL){
        return bTree;
    }
    /**
     * 增加数值 检查/修改节点
     */
    if (treeNode->len<=M-2){
        treeNode->keys[treeNode->len]=value;
        treeNode->len++;
        _b_sort(treeNode->keys,treeNode->len);
        return bTree;
    }
    /**
    * 检查更新树结构
    */
    treeNode->keys[treeNode->len]=value;
    treeNode->len++;
    _b_sort(treeNode->keys,treeNode->len);

    b_tree *temp = _btree_fixup(treeNode);
    return temp==NULL?bTree:temp;
}

/**
 * 获得深度
 * @param twoThreeTree
 * @return
 */
int _get_btree_depth(b_tree * bTree){
    int m=0;
    while (bTree!=NULL){
        m++;
        bTree=bTree->child[0];
    }
    return m;
}

/**
 * 中序遍历
 * @param bTree
 */
void printbtree_LDR(b_tree * bTree){
    for (int i = 0; i < bTree->len; ++i) {
        if (bTree->child[i]!=NULL){
            printbtree(bTree->child[i]);
        }
        printf("%d\t",bTree->keys[i]);
    }
    if (bTree->child[bTree->len]!=NULL){
        printbtree(bTree->child[bTree->len]);
    }
}

/**
 * 获得当前结点的叶子数
 * @param node 当前结点
 * @param count
 */
void _get_leaf_counts(b_tree *node,int *count){
    if (node->child[0]==NULL){
        * count+=1;
        return;
    }
    for (int i = 0; i <= node->len; ++i) {
        if (node->child[i]!=NULL){
            _get_leaf_counts(node->child[i],count);
        }
    }
}

/**
 * 打印b树
 * @param bTree
 */
void printbtree(b_tree * bTree){
    int indexlevel=1;//当前层数
    int count=1;//当前层节点
    int temp=0;//下一行数量
    int depth = _get_btree_depth(bTree);//树深度
    Queue *queue = NULL;//结点队列
    Value value;//值 储存树节点
    value.node = bTree;
    queue = enqueue(queue,value);
    b_tree *node;
    int lengthEveryOne=6*(M-1)+3*(M-2)+2;//单个结点的长度
    int count_leaf=0;//叶子数
    while (isEmpty(queue)&&indexlevel<=depth){
        node = queue->first->value.node;
        /**
         * 空格打印
         */
        if (node->child[0]!=NULL){
            _get_leaf_counts(node,&count_leaf);
        } else{
            count_leaf=0;
        }
//        printf("叶子数:%d\t",count_leaf);
        for (int i = 0; i < (count_leaf-1)*lengthEveryOne/2; ++i) {
            printf(" ");
        }
        /**
         * 打印结点
         */
        if (node->keys[0]!=-1){
            printf("(");
            for (int i = 0; i < node->len-1; ++i) {
                printf("%6d | ",node->keys[i]);
            }
            printf("%6d",node->keys[node->len-1]);
            for (int i = node->len; i < M-1; ++i) {
                printf("         ");
            }
            printf(")");
        }
        /**
         * 打印空格
         */
        for (int i = 0; i < (count_leaf-1)*lengthEveryOne/2; ++i) {
            printf(" ");
        }

        count--;

        //加入队列
        for (int i = 0; i < M; ++i) {
            if (node->child[i]!=NULL){
                value.node=node->child[i];
                queue = enqueue(queue,value);
                temp++;
            }
        }
        /**
         * 当前行已经输出完毕
         * 给结点增加 枝干
         */
        if (count==0){
            printf("\n");
            count=temp;
            temp=0;
            indexlevel++;
        }
        count_leaf=0;
        queue = dequeue(queue);
    }
}

/**
 * 查询指定值
 * @param bTree
 * @param vaule 需要查询的值
 * @param bool 失败-1 成功为查询值
 */
void b_tree_find(b_tree *bTree,int vaule,int *bool){
    if (bTree==NULL){
        *bool=-1;
        return;
    }
    for (int i = 0; i < bTree->len; ++i) {
        if (vaule<bTree->keys[i]){
//            printf("进入子结点\n");
            b_tree_find(bTree->child[i],vaule,bool);
            return;
        }
        if (vaule==bTree->keys[i]){
            *bool=vaule;
            return;
        }
    }
    b_tree_find(bTree->child[bTree->len],vaule,bool);
}

/**
 * b树 释放
 * @param bTree 根结点
 */
void freebtree(b_tree *bTree){
    if (bTree!=NULL){
        for (int i = 0; i < bTree->len; ++i) {
            freebtree(bTree->child[i]);
        }
        free(bTree);
    }
}