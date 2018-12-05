#include "stdlib.h"
#include "stdio.h"
 /**
  * 生成随机数据 0~range
  * @param array 数组指针
  * @param length 数组长度
  * @param range 数据范围
  * @return 数组指针
  */
 int* random_data(int *array,int length,int range) {
    for (int i = 0; i < length; ++i) {
        *(array+i) = rand()%range;
    }
    return array;
}
int hello(){
     printf("as");
    return 1;
 }