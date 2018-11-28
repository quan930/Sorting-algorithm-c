#include "stdio.h"
#include "random_data.c"
#include "select_sort.c"
#include "bubble_sort.c"
#include "insert_sort.c"
#include "shell_sort.c"
#include "merge_sort.c"
#include "quick_sort.c"
#define LENGTH 1000000

int main(){
    int array[LENGTH];
    printf("length:%d\n",LENGTH);
    printf("冒泡排序:%f秒\n",bubble_sort(random_data(array,LENGTH),LENGTH));
    printf("选择排序:%f秒\n",select_sort(random_data(array,LENGTH),LENGTH));
    printf("插入排序:%f秒\n",insert_sort(random_data(array,LENGTH),LENGTH));
    printf("希尔排序:%f秒\n",shell_sort(random_data(array,LENGTH),LENGTH));
    printf("归并排序:%f秒\n",merge_sort(random_data(array,LENGTH),LENGTH));
    printf("快速排序:%f秒\n",quick_sort(random_data(array,LENGTH),LENGTH));
}