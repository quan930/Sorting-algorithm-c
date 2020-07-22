#include "../header/2-3tree.h"
#include "stdio.h"
#include "time.h"

//
// Created by 全 on 2020/7/21.
//

/**
 * 2-3树 装配
 * @param testarr 测试数组
 * @param testlen 测试数组长度
 * @param twoThreeTree 3树根结点
 * @return 2-3树根结点
 */
two_three_tree * _twothreetree_search_assemble(int *testarr, int testlen , two_three_tree *twoThreeTree){
    for (int i = 0; i < testlen; ++i) {
        twoThreeTree = two_three_tree_insert(twoThreeTree,testarr[i]);
//        printf("插入值为:%d\n",testarr[i]);
//        print23tree(twoThreeTree);
    }
//    print23tree(twoThreeTree);
    return twoThreeTree;
}

/**
 * 2-3树 装配
 * @param testarr 测试数组
 * @param testlen 测试数组长度
 * @param twoThreeTree 2-3树根结点
 * @param time 2-3树装配时间
 * @return 2-3树根结点
 */
two_three_tree* twothreetree_search_assemble(int *testarr, int testlen , two_three_tree *twoThreeTree, double *time){
    clock_t start,finish;
    start = clock();

    two_three_tree *p = _twothreetree_search_assemble(testarr,testlen,twoThreeTree);

    finish = clock();
    *time = (double)(finish - start) / CLOCKS_PER_SEC;
    return p;
}

/**
 * 2-3树查询
 * @param testarr 测试数组
 * @param testlen 测试数组长度
 * @param twoThreeTree 2-3树根结点
 */
void _twothreetree_search(int *testarr, int testlen , two_three_tree *twoThreeTree){
    if (twoThreeTree==NULL){
        return;
    }
    int bool=0;
    for (int i = 0; i < testlen; ++i) {
//        printf("查询%d\n",testarr[i]);
        two_three_tree_find(twoThreeTree,testarr[i],&bool);
        if (bool==-1||bool!=testarr[i])
            printf("查询失败\n");
    }
}

/**
 * 2-3树查询
 * @param testarr 测试数组
 * @param testlen 测试数组长度
 * @param twoThreeTree 2-3树根结点
 * @return 二叉查找树查询时间(秒)
 */
double twothreetree_search(int *testarr, int testlen ,two_three_tree *twoThreeTree){
    clock_t start,finish;double time;
    start = clock();

    _twothreetree_search(testarr,testlen,twoThreeTree);

    finish = clock();
    free23tree(twoThreeTree);//释放
    time = (double)(finish - start) / CLOCKS_PER_SEC;
    return time;
}