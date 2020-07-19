#include "stdio.h"
#include "header/random_data.h"
#include "header/sort.h"
#include "header/search.h"
#include <limits.h>

//#define LENGTH 100000
#define LENGTH 1000000
/**
 * 2018-11-9
 */
int main1(){
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
    printf("length:%d\trange:0~%d\n",LENGTH,range);
    int *testarr = random_data(array,LENGTH,range);
    //二叉搜索树
    TreeNode *treeNode = NULL;
    treeNode = binarytree_search_assemble(testarr,LENGTH,treeNode,&time);
    printf("二叉树装配时间:\t%f秒\n",time);
    printf("二叉树查询时间:\t%f秒\n",binarytree_search(testarr,LENGTH,treeNode));
}