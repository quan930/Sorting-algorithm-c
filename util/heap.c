//
// Created by daquan on 2018/12/5.
//
#include "stdio.h"
/**
 * 计算堆的行数 打印堆 子方法
 * @param length 堆的长度
 * @return 返回堆的行数
 */
int find_lines(int length){
    int i=1;
    int lines = 0;
    while (i<=length){
        i=i*2;
        lines++;
    }
    return lines;
}
/**
 * 计算堆的某行间隔
 * @param line 堆的行数
 * @param lines 堆的总行数
 * @return 间隔大小
 */
int find_interval(int line,int lines){
    int m=0;
    for (int i = lines; i >= line ; --i) {
        m=m*2+1;
    }
    return m;
}
/**
 * 打印堆
 * @param array 数组
 * @param length 堆长度/数组长度-1  注:索引0为null
 */
void print_heap(int *array,int length){
    int lines = find_lines(length);
    int line = 1;
    for (int i = 1; i <= length; i=2*i) {
        int interval = find_interval(line,lines);
        for (int j = 0; j < interval/2; ++j) {
            printf(" ");
        }
        for (int j = 0; j < i&&i+j<=length; ++j) {
            printf("%d",array[i+j]);
            for (int k = 0; k < interval; ++k) {
                printf(" ");
            }
        }
        printf("\n");
        line++;
    }
}
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