#include "stdio.h"
#include "random_data.c"
#include "selection_sort.c"
#include "bubble_sort.c"
#include "insertion_sort.c"
#include "shell_sort.c"
#include "merge_sort.c"
#include "quick_sort.c"
#include "heap_sort.c"
#include "counting_sort.c"
#define LENGTH 100
/**
 * 11:9
 */
int main(){
    int array[LENGTH];
    int range=LENGTH;
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
}