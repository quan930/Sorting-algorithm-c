#include "stdio.h"
#include "time.h"
/**
 * 冒泡排序
 * @param array 数组
 * @param length 长度
 */
void _bubble_sort(int *array,int length){
    int temp;
    for (int i = 0; i < length-1; ++i) {
        for (int j = 0; j < length-i-1; ++j) {
            if (array[j]>array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
//        for (int j = 0; j <= length; ++j) {
//            printf("%d\t",array[j]);
//        }
//        printf("\n");
    }
}
 /**
  * 测试冒泡排序时间
  * @param array 数组
  * @param length 长度
  * @return 冒泡排序时间(秒)
  */
double bubble_sort(int *array,int length){
    clock_t start,finish;
    double time;
    start = clock();
    _bubble_sort(array,length);
    finish = clock();
    time = (double)(finish - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < length; ++i) {
//        printf("%d\n",array[i]);
//    }
    return time;
}