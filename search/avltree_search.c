//
// Created by 全 on 2020/7/25.
//

#include "../header/avlTree.h"
#include "time.h"
#include "stdio.h"

/**
 * avl 树装配
 * @param testarr 测试数组
 * @param testlen 测试数组长度
 * @param avlTree avl树根结点
 * @return 二叉树根结点
 */
avl_tree* _avltree_search_assemble(int *testarr, int testlen , avl_tree *avlTree){
    for (int i = 0; i < testlen; ++i) {
//        printf("插入值为:%d\n",testarr[i]);
        avlTree = avl_tree_insert(avlTree,testarr[i]);
//        print_avltree(avlTree);
    }
    return avlTree;
}

/**
 * avl 树装配
 * @param testarr 测试数组
 * @param testlen 测试数组长度
 * @param avlTree avl树根结点
 * @param time avl树装配时间(秒)
 * @return 二叉树根结点
 */
avl_tree* avltree_search_assemble(int *testarr, int testlen , avl_tree *avlTree, double *time){
    clock_t start,finish;
    start = clock();

    avl_tree *p = _avltree_search_assemble(testarr,testlen,avlTree);

    finish = clock();
    *time = (double)(finish - start) / CLOCKS_PER_SEC;
    return p;
}

/**
 * avl树 查询
 * @param testarr 测试数组
 * @param testlen 测试数组长度
 * @param avlTree avl树根结点
 */
void _avltree_search(int *testarr, int testlen , avl_tree *avlTree){
    if (avlTree==NULL){
        return;
    }
    int bool=0;
    for (int i = 0; i < testlen; ++i) {
//        printf("查询%d\n",testarr[i]);
        avl_tree_find(avlTree,testarr[i],&bool);
        if (bool==-1||bool!=testarr[i])
            printf("查询失败\n");
    }
}

/**
 * avl树 查询
 * @param testarr 测试数组
 * @param testlen 测试数组长度
 * @param avlTree avl树根结点
 * @return avl树查询时间(秒)
 */
double avltree_search(int *testarr, int testlen ,avl_tree * avlTree){
    clock_t start,finish;double time;
    start = clock();

    _avltree_search(testarr,testlen,avlTree);

    finish = clock();
    free_avltree(avlTree);//释放
    time = (double)(finish - start) / CLOCKS_PER_SEC;
    return time;
}