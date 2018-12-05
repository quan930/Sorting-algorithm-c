#include "stdio.h"
#include "time.h"
#include <stdlib.h>

/**
 * 计数排序
 * @param array 数组
 * @param length 长度
 * @param range 数组范围 0～range
 *  作为一种线性时间复杂度的排序，计数排序要求输入的数据必须是有确定范围的整数。
 */
void _counting_sort(int *array,int length,int range){
    int *count;//计数数组
    count = calloc(range,sizeof(int));
    for (int i = 0; i < length; ++i) {
//        printf("%d\t",array[i]);
        count[array[i]]++;
    }
//    printf("\n数量:");
//    for (int i = 0; i < range; ++i) {
//        printf("%d\t",count[i]);
//    }
    for (int i = 1; i < range; ++i) {//计算位置 please
        count[i]=count[i]+count[i-1];
    }
//    printf("\n位置:");
//    for (int i = 0; i < range; ++i) {
//        printf("%d\t",count[i]);
//    }
//    printf("\n");
    int *temp;//排序临时数组
    temp = malloc(length* sizeof(int));
    for (int i = 0; i < length; ++i) {
        temp[count[array[i]]-1] = array[i];
        count[array[i]]--;
    }
    free(count);
    for (int i = 0; i < length; ++i) {//写入原数组
        array[i] = temp[length-i-1];
    }
    free(temp);
}
 /**
  * 测试计数排序时间
  * @param array 数组
  * @param length 数组长度
  * @param range 数组范围 0～range
  * @return 测试时间（秒）
  */
double counting_sort(int *array,int length,int range){
    clock_t start,finish;
    double time;
    start = clock();
    _counting_sort(array,length,range);
    finish = clock();
    time = (double)(finish - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < length; ++i) {
//        printf("%d\n",array[i]);
//    }
    return time;
}