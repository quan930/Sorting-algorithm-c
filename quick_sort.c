#include "stdio.h"
#include "time.h"
/**
 * 中位数 可优化
 */
int median( int a, int b, int c )
{
    int min = a, max =a;
    if( b < min )
        min = b;
    else
        max = b;
    if( c < min )
        min = c;
    else if( c > max )
        max = c;
    return a - min + b - max + c;//防止溢出
}
/**
 * 插入排序
 * @param array 数组
 * @param length 长度
 */
void q_insert_sort(int *array,int length){
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
 * 快速排序 如果length<15 插入排序
 * @param array 数组
 * @param length 长度
 * 0~lt:小于切分值
 * lt~pInt:等于切分值
 * gt~length-1:大于切分值
 */
void _quick_sort(int *array,int length){
    if (length<15){
        q_insert_sort(array,length);
        return;
    }
    int med = median(array[0],array[length/2],array[length-1]);
//    printf("\n三取样切分(值):%d\n",med);
    int *pInt = array;
    int lt=-1;
    int gt=length;
    int temp;
    for (int i = 0; i < length; ++i) {
        if (*pInt<med){
            temp = array[lt+1];
            array[lt+1] = *pInt;
            *pInt = temp;
            lt++;
            pInt++;
        } else if (*pInt==med){
            pInt++;
        } else{
            temp = array[gt-1];
            array[gt-1] = *pInt;
            *pInt = temp;
            gt--;
        }
    }
//    for (int i = 0; i < length; ++i) {
//        printf("%d\t",array[i]);
//    }
//    printf("\n左:%d\t\t右:%d\n",lt,gt);
    if (lt+1>=2){
        _quick_sort(&array[0],lt+1);
    }
    if ((length-gt)>=2){
       _quick_sort(&array[gt],length-gt);
    }
}
/**
 * 测试快速排序时间(三数中值分割法)(三向切分)
 * @param array 数组
 * @param length 数组长度
 * @return 快速排序时间(秒)
 */
double quick_sort(int *array,int length){
    clock_t start,finish;
    double time;
    start = clock();
    _quick_sort(array,length);
    finish = clock();
    time = (double)(finish - start) / CLOCKS_PER_SEC;
//    for (int i = 0; i < length; ++i) {
//        printf("%d\n",array[i]);
//    }
    return time;
}