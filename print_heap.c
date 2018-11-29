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