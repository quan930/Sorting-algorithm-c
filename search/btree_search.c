//
// Created by 全 on 2020/7/31.
//

#include "../header/btree.h"
#include "stdio.h"
#include "time.h"

b_tree* _btree_search_assemble(int *testarr, int testlen , b_tree *bTree){
    for (int i = 0; i < testlen; ++i) {
        bTree = b_tree_insert(bTree,testarr[i]);
//        printf("插入值为:%d\n",testarr[i]);
//        printbtree(bTree);
    }
    return bTree;
}

b_tree* btree_search_assemble(int *testarr, int testlen , b_tree *bTree, double *time){
    clock_t start,finish;
    start = clock();

    b_tree *p = _btree_search_assemble(testarr,testlen,bTree);

    finish = clock();
    *time = (double)(finish - start) / CLOCKS_PER_SEC;
    return p;
}


void _btree_search(int *testarr, int testlen , b_tree *bTree){
    if (bTree==NULL){
        return;
    }
    int bool=0;
    for (int i = 0; i < testlen; ++i) {
//        printf("查询%d\n",testarr[i]);
        b_tree_find(bTree,testarr[i],&bool);
        if (bool==-1||bool!=testarr[i])
            printf("查询失败:%d\n",testarr[i]);
    }
}

double btree_search(int *testarr, int testlen ,b_tree *bTree){
    clock_t start,finish;double time;
    start = clock();

    _btree_search(testarr,testlen,bTree);

    finish = clock();
    freebtree(bTree);//释放
    time = (double)(finish - start) / CLOCKS_PER_SEC;
    return time;
}