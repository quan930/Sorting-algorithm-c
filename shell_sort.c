#include <time.h>
#include "stdio.h"
/**
 *
 * @param array 数组
 * @param length 数组长度
 * @param start 开始位置
 * @param increment 增量
 */
void _shell_insert_sort(int * array,int length,int start,int increment) {
    int position = -1;
    int temp;
    for (int i = start+increment; i < length; i=i+increment) {
        position=i;
        temp = array[position];
        while (position>start){
            if (temp<array[position-increment]){
                array[position] = array[position-increment];
                position = position-increment;
            } else{
                break;
            }
        }
        if (position!=i){
            array[position] = temp;
        }
    }
//    printf("增量:%-7d---",increment);
//    for (int j = 0; j < length; ++j) {
//        printf("%d\t",array[j]);
//    }
//    printf("\n");
}
/**
 * 希尔排序
 * @param array 数组
 * @param length 数组长度
 */
void _shell_sort(int * array,int length){
    int increment_max = 0;
    //计算最大增量 h=3*b+1
    for (int i = 1; i < length; i=3*i+1) {
        increment_max = i;
    }
    //分别对每个分组进行直接插入排序
    for (int i = increment_max; i >= 1 ; i=i/3) {//将数组变为i有序
        for (int j = 0; (j<length-i)&&(j<i); ++j) {
            _shell_insert_sort(array,length,j,i);//插入排序
        }
    }
}
/**
 * 测试希尔排序时间
 * @param array 数组
 * @param length 数组长度
 * @return 希尔排序时间(秒)
 */
double shell_sort(int *array,int length){
    clock_t start,finish;
    double time;
    start = clock();
    _shell_sort(array,length);
    finish = clock();
    time = (double)(finish - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < length; ++i) {
//        printf("%d\n",array[i]);
//    }
    return time;
}