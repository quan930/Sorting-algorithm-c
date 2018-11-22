#include "stdlib.h"
#include "stdio.h"
/**
 * 生成随机数据
 * @param array 数组指针
 * @param length 数组长度
 * @return 数组指针
 */
int* random_data(int *array,int length){
    for (int i = 0; i < length; ++i) {
        *(array+i) = rand()%length;
    }
    return array;
}