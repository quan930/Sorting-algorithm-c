#include "stdio.h"
#include "time.h"
/**
 * 选择排序
 * @param array 数组
 * @param length 长度
 */
void _select_sort(int *array,int length){
    int temp;
    int position;
    for (int i = 0; i < length-1; ++i) {
        temp = array[i];
        position = i;
        for (int j = i+1; j < length; ++j) {
            if (array[j]<temp){
                temp = array[j];
                position = j;
            }
        }
        if (position!=i){
            array[position] = array[i];
            array[i] = temp;
        }
//        for (int j = 0; j <= length; ++j) {
//            printf("%d\t",array[j]);
//        }
//        printf("\n");
    }
}
 /**
  * 测试选择排序时间
  * @param array 数组
  * @param length 数组长度
  * @return 选择排序时间(秒)
  */
double select_sort(int *array,int length){
    clock_t start,finish;
    double time;
    start = clock();
    _select_sort(array,length);
    finish = clock();
    time = (double)(finish - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < length; ++i) {
//        printf("%d\n",array[i]);
//    }
    return time;
}