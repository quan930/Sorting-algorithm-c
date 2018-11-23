#include <time.h>
#include "stdio.h"
#include <stdlib.h>
/**
 * 归并
 * @param tArr 临时数组
 * @param lArr 左数组
 * @param lLe 左数组长度
 * @param rArr 右数组
 * @param rLe 右数组长度
 */
void __merge(int *tArr,int *lArr,int lLe,int *rArr,int rLe){
    int lArrPos=0;//临时数组位置
    int rArrPos = 0;//左数组位置
    int tArrPos = 0;//右数组位置
    while ((lArrPos < lLe) && (rArrPos < rLe)){//归并
        if (lArr[lArrPos] < rArr[rArrPos]){
            tArr[tArrPos] = lArr[lArrPos];
            lArrPos++;
        } else{
            tArr[tArrPos] = rArr[rArrPos];
            rArrPos++;
        }
        tArrPos++;
    }
    while (lArrPos<lLe){//剩余数组归并
        tArr[tArrPos] = lArr[lArrPos];
        lArrPos++;
        tArrPos++;
    }
    while (rArrPos<rLe){//剩余数组归并
        tArr[tArrPos] = rArr[rArrPos];
        rArrPos++;
        tArrPos++;
    }
    for (int i = 0; i < lLe+rLe; ++i) {//copy
        lArr[i]= tArr[i];
    }
}
/**
 * 归并排序
 * @param array 数组
 * @param length 数组长度
 */
void _merge_sort(int *array,int length){
    int * temp;
    temp = malloc(length* sizeof(int));
    for (int i = 1; i <= length;i+=i) {//i 子数组大小
        for (int j = 0; j < length-i; j+=2*i) {//j 子数组索引
            __merge(temp,array+j,i,array+j+i,length<j+2*i?length-j-i:i);//左---索引:j,长度:i    右---索引:j+i,长度:(length<j+2*i?length-j-i:i)//需要验证是否越界
        }
//        for (int j = 0; j < length; ++j) {
//            if (j%(2*i)==0&&j!=0)
//                printf("|");
//            else
//                printf(" ");
//            printf("%d\t",array[j]);
//        }
//        printf("\n");
    }
    free(temp);
}

/**
 * 测试归并排序时间
 * @param array 数组
 * @param length 数组长度
 * @return 测试时间（秒）
 */
double merge_sort(int *array,int length){
    clock_t start,finish;
    double time;
    start = clock();
    _merge_sort(array,length);
    finish = clock();
    time = (double)(finish - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < length; ++i) {
//        printf("%d\n",array[i]);
//    }
    return time;
}