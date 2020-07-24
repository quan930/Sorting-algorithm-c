//
// Created by 全 on 2020/7/24.
//

#include "../header/redBlackTree.h"
#include "stdio.h"
#include "time.h"

/**
 * 红黑树查询
 * @param testarr 测试数组
 * @param testlen 测试数组长度
 * @param treeNode 红黑树根结点
 */
void _redblacktree_search(int *testarr, int testlen , red_black_tree *redBlackTree){
    if (redBlackTree==NULL){
        return;
    }
    int bool=0;
    for (int i = 0; i < testlen; ++i) {
//        printf("查询%d\n",testarr[i]);
        red_black_tree_find(redBlackTree,testarr[i],&bool);
        if (bool==-1||bool!=testarr[i])
            printf("查询失败\n");
    }
}

/**
 * 红黑树 查询
 * @param testarr 测试数组
 * @param testlen 测试数组长度
 * @param treeNode 红黑树根结点
 * @return 红黑树查询时间(秒)
 */
double redblacktree_search(int *testarr, int testlen , red_black_tree *redBlackTree){
    clock_t start,finish;double time;
    start = clock();

    _redblacktree_search(testarr,testlen,redBlackTree);

    finish = clock();
    free_rbtree(redBlackTree);//释放
    time = (double)(finish - start) / CLOCKS_PER_SEC;
    return time;
}

/**
 * 红黑树装配
 * @param testarr 测试数组
 * @param testlen 测试数组长度
 * @param redBlackTree 红黑树根结点
 * @return 红黑树根结点
 */
red_black_tree* _redblacktree_search_assemble(int *testarr, int testlen , red_black_tree *redBlackTree){
    for (int i = 0; i < testlen; ++i) {
        redBlackTree = red_black_tree_insert(redBlackTree,testarr[i]);
//        printf("插入值为:%d\n",testarr[i]);
//        print_rbtree(redBlackTree);
    }
    return redBlackTree;
}


/**
 * 红黑树装配
 * @param testarr 测试数组
 * @param testlen 测试数组长度
 * @param redBlackTree 红黑树根结点
 * @param time 红黑树装配时间
 * @return 红黑树根结点
 */
red_black_tree* redblacktree_search_assemble(int *testarr, int testlen , red_black_tree *redBlackTree, double *time){
    clock_t start,finish;
    start = clock();

    red_black_tree *p = _redblacktree_search_assemble(testarr,testlen,redBlackTree);

    finish = clock();
    *time = (double)(finish - start) / CLOCKS_PER_SEC;
    return p;
}