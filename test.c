#include "stdio.h"
#include "header/random_data.h"
#include "header/sort.h"
#include "header/binaryTree.h"
#include "header/queue.h"

#define LENGTH 100000
/**
 * 2018-11-9
 */
 void binaryTree(){
    TreeNode *treeNode=NULL;
    for (int i = 1; i <= 10; ++i) {
        treeNode = insertBinaryTree(treeNode,i);
    }
    inOrder(treeNode);
    levelOrder(treeNode);
 }
int main(){
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