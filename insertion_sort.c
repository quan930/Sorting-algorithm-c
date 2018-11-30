#include <time.h>
#include "stdio.h"

/**
 * 插入排序
 * @param array 数组
 * @param length 长度
 */
void _insertion_sort(int *array,int length){
    int position = -1;
    int temp;
    for (int i = 1; i < length; ++i) {
        position=i;
        temp = array[position];
        while (position>0){
            if (temp<array[position-1]){
                array[position] = array[position-1];
                position --;
            } else{
                break;
            }
        }
        if (position!=i){
            array[position] = temp;
        }
//        for (int j = 0; j <= i; ++j) {
//            printf("%d\t",array[j]);
//        }
//        printf("\n");
    }
}
/**
 * 测试插入排序时间
 * @param array 数组
 * @param length 长度
 * @return 插入排序时间(秒)
 */
double insertion_sort(int *array,int length){
    clock_t start,finish;
    double time;
    start = clock();
    _insertion_sort(array,length);
    finish = clock();
    time = (double)(finish - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < length; ++i) {
//        printf("%d\n",array[i]);
//    }
    return time;
}