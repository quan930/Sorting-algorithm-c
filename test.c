#include "stdio.h"
#include "random_data.c"
#include "select_sort.c"
#include "bubble_sort.c"
#include "insert_sort.c"
#include "shell_sort.c"
#include "merge_sort.c"

int main(){
    int length = 30;
    int array[length];
    printf("length:%d\n",length);
    printf("冒泡排序:%f秒\n",bubble_sort(random_data(array,length),length));
    printf("选择排序:%f秒\n",select_sort(random_data(array,length),length));
    printf("插入排序:%f秒\n",insert_sort(random_data(array,length),length));
    printf("希尔排序:%f秒\n",shell_sort(random_data(array,length),length));
    printf("归并排序:%f秒\n",merge_sort(random_data(array,length),length));
}