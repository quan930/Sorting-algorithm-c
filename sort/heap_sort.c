#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "../header/heap.h"
/**
 * 堆排序
 * @param array 数组
 * @param length 长度
 * 分配临时空间，不分配也可
 */
void _heap_sort(int *array,int length){
    int *temp;
    temp = (int *)malloc(sizeof(int)*(length+1));//分配临时数组内存空间length+1 0为null
//    for (int i = 0; i < length; ++i) {
//        printf("%d\t",array[i]);
//    }
//    printf("\n");
    for (int i = 1; i <= length ; ++i) {//插入堆
//        printf("===================\ninsert:%d\n",array[i-1]);
        insert_head(temp,i,array[i-1]);
//        print_heap(temp,i);
    }
    for (int i = length; i > 0 ; --i) {//取出堆
//        printf("--------------------\ndelete:%d\n",temp[1]);
        array[length-i] = delete_head(temp,i);
//        print_heap(temp,i-1);
    }
    free(temp);//释放
//    for (int i = 0; i < length; ++i) {
//        printf("%d\t",array[i]);
//    }
//    printf("\n");
}
/**
 * 测试堆排序时间
 * @param array 数组
 * @param length 数组长度
 * @return 排序时间(秒)
 */
double heap_sort(int *array,int length){
    clock_t start,finish;
    double time;
    start = clock();
    _heap_sort(array,length);
    finish = clock();
    time = (double)(finish - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < length; ++i) {
//        printf("%d\n",array[i]);
//    }
    return time;
}