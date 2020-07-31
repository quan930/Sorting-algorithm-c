#include "stdio.h"
#include "header/random_data.h"
#include "header/sort.h"
#include "header/search.h"
#include "header/2-3tree.h"
#include "header/btree.h"
//#include <limits.h>

//#define LENGTH 100000
#define LENGTH 1000000
#define LENGTH2 10000

/**
 * 2018-11-9
 */
int sort(){
    int array[LENGTH];
    int range=10000;
    printf("length:%d\trange:0~%d\n",LENGTH,range);
    printf("--------------比较排序--------------------\n");
    printf("冒泡排序:\t%f秒\n",bubble_sort(random_data(array,LENGTH,range),LENGTH));
    printf("选择排序:\t%f秒\n",selection_sort(random_data(array,LENGTH,range),LENGTH));
    printf("插入排序:\t%f秒\n",insertion_sort(random_data(array,LENGTH,range),LENGTH));
    printf("希尔排序:\t%f秒\n",shell_sort(random_data(array,LENGTH,range),LENGTH));
    printf("堆排序:\t%f秒\n",heap_sort(random_data(array,LENGTH,range),LENGTH));
    printf("归并排序:\t%f秒\n",merge_sort(random_data(array,LENGTH,range),LENGTH));
    printf("快速排序:\t%f秒\n",quick_sort(random_data(array,LENGTH,range),LENGTH));
    printf("--------------非比较排序--------------------\n");
    printf("计数排序:\t%f秒\n",counting_sort(random_data(array,LENGTH,range),LENGTH,range));
    printf("桶排序:\t%f秒\n",bucket_sort(random_data(array,LENGTH,range),LENGTH,range));
    return 0;
}

int main(){
    int array[LENGTH];
    int range=10000000;
    double time;
    int *testarr = random_data(array,LENGTH,range);
    printf("--------------随机插入--------------------\n");
    printf("length:%d\trange:0~%d\n",LENGTH,range);
    //二叉搜索树
    TreeNode *treeNode = NULL;
    treeNode = binarytree_search_assemble(testarr,LENGTH,treeNode,&time);
    printf("二叉树装配时间:\t%f秒\n",time);
    printf("二叉树查询时间:\t%f秒\n",binarytree_search(testarr,LENGTH,treeNode));
    //2-3树
    two_three_tree *twoThreeTree=NULL;
    twoThreeTree = twothreetree_search_assemble(testarr,LENGTH,twoThreeTree,&time);
    printf("2-3树装配时间:\t%f秒\n",time);
    printf("2-3树查询时间:\t%f秒\n",twothreetree_search(testarr,LENGTH,twoThreeTree));
    //红黑树
    red_black_tree *redBlackTree=NULL;
    redBlackTree = redblacktree_search_assemble(testarr,LENGTH,redBlackTree,&time);
    printf("红黑树装配时间:\t%f秒\n",time);
    printf("红黑树查询时间:\t%f秒\n",redblacktree_search(testarr,LENGTH,redBlackTree));
    //avl树
    avl_tree *avlTree=NULL;
    avlTree = avltree_search_assemble(testarr,LENGTH,avlTree,&time);
    printf("avl树装配时间:\t%f秒\n",time);
    printf("avl树查询时间:\t%f秒\n",avltree_search(testarr,LENGTH,avlTree));
    //b 树
    b_tree *bTree=NULL;
    bTree = btree_search_assemble(testarr,LENGTH,bTree,&time);
    printf(" b树 装配时间:\t%f秒\n",time);
    printf(" b树 查询时间:\t%f秒\n",btree_search(testarr,LENGTH,bTree));


    //排序 极端情况
    testarr = random_data(array,LENGTH2,range);
    merge_sort(random_data(array,LENGTH,range),LENGTH);
    printf("\n--------------顺序插入--------------------\n");
    printf("length:%d\trange:0~%d\n",LENGTH2,range);
    TreeNode *treeNode2 = NULL;
    treeNode2 = binarytree_search_assemble(testarr,LENGTH2,treeNode2,&time);
    printf("二叉树装配时间:\t%f秒\n",time);
    printf("二叉树查询时间:\t%f秒\n",binarytree_search(testarr,LENGTH2,treeNode2));
    //2-3树
    two_three_tree *twoThreeTree2=NULL;
    twoThreeTree2 = twothreetree_search_assemble(testarr,LENGTH2,twoThreeTree2,&time);
    printf("2-3树装配时间:\t%f秒\n",time);
    printf("2-3树查询时间:\t%f秒\n",twothreetree_search(testarr,LENGTH2,twoThreeTree2));
    //红黑树
    red_black_tree *redBlackTree2=NULL;
    redBlackTree2 = redblacktree_search_assemble(testarr,LENGTH2,redBlackTree2,&time);
    printf("红黑树装配时间:\t%f秒\n",time);
    printf("红黑树查询时间:\t%f秒\n",redblacktree_search(testarr,LENGTH2,redBlackTree2));
    //avl 树
    avl_tree *avlTree2=NULL;
    avlTree2 = avltree_search_assemble(testarr,LENGTH2,avlTree2,&time);
    printf("avl树装配时间:\t%f秒\n",time);
    printf("avl树查询时间:\t%f秒\n",avltree_search(testarr,LENGTH2,avlTree2));
    //b 树
    b_tree *bTree2=NULL;
    bTree2 = btree_search_assemble(testarr,LENGTH2,bTree2,&time);
    printf(" b树 装配时间:\t%f秒\n",time);
    printf(" b树 查询时间:\t%f秒\n",btree_search(testarr,LENGTH2,bTree2));
}
