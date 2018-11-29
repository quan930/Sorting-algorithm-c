#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "print_heap.c"
/**
 * 向堆插入元素
 * @param array 数组
 * @param length 加入元素后:堆的长度/数组长度-1  注:索引0为null
 * @param value 插入元素的值
 */
void insert_head(int *array,int length,int value){
    array[length] = value;
    int position = length;
    int temp;
//    printf("===================\n");
//    printf("insert:%d\n",value);
    temp = array[position];
    while (position>1){
        if (temp>array[position/2]){
            array[position] = array[position/2];
            position=position/2;
        } else{
            break;
        }
    }
    if (position!=length){
        array[position] = temp;
    }
//    print_heap(array,length);
}
/**
 * 从堆删除元素(最大)
 * @param array 数组
 * @param length 删除元素前:堆的长度/数组长度-1  注:索引0为null
 * @return 删除的最大元素
 */
int delete_head(int *array,int length){
    int max = array[1];
    array[1] = array[length];
    int position = 1;
    int temp;
//    printf("--------------------\n");
//    printf("delete:%d\n",max);
    while (position*2<=length){
        if (position*2+1<=length){//判断是否有右节点
            if (array[position]<array[position*2]){//小于左后裔，需比较左右后裔，取大节点
                if (array[position*2+1]>array[position*2]){
                    temp = array[position];
                    array[position] = array[position*2+1];
                    array[position*2+1] = temp;
                    position=position*2+1;
                } else{
                    temp = array[position];
                    array[position] = array[position*2];
                    array[position*2] = temp;
                    position = position*2;
                }
                continue;
            }
            if (array[position]<array[position*2+1]){//小于右后裔
                temp = array[position];
                array[position] = array[position*2+1];
                array[position*2+1] = temp;
                position=position*2+1;
                continue;
            }
        }
        if (array[position]<array[position*2]){//无右后裔，比较左后裔
            temp = array[position];
            array[position] = array[position*2];
            array[position*2] = temp;
            position = position*2;
            continue;
        }
        break;
    }
//    print_heap(array,length-1);
    return max;
}
/**
 * 堆排序
 * @param array 数组
 * @param length 长度
 */
void _heap_sort(int *array,int length){
    int *temp;
    temp = (int *)malloc(sizeof(int)*(length+1));//分配临时数组内存空间length+1 0为null
//    for (int i = 0; i < length; ++i) {
//        printf("%d\t",array[i]);
//    }
//    printf("\n");
    for (int i = 1; i <= length ; ++i) {//插入堆
        insert_head(temp,i,array[i-1]);
    }
    for (int i = length; i > 0 ; --i) {//取出堆
        array[length-i] = delete_head(temp,i);
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