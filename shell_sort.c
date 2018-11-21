#include "stdio.h"
void insert_sort(int array[],int length,int start,int increment)
{
    /**
     *  array 数组
     *  length 数组长度
     *  start 开始位置
     *  increment 增量
     */
    int position = -1;
    int temp;
//    printf("\n插入排序前:");
//    for (int j = 0; j < length; ++j) printf("%d\t",array[j]);
    for (int i = start+increment; i < length; i=i+increment) {
        position=i;
        temp = array[position];
//        printf("\n位置:%2d值:%3d",position,temp);
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
//        printf("-----插入排序:");
//        for (int j = 0; j < length; ++j) {
//            printf("%d\t",array[j]);
//        }
    }
}

int main(){
    int array[] = {3,1,4,2,5,7,6,8,7,2,5,76,100,23,10,3,1};
    int length = sizeof(array)/ sizeof(int);
    int increment_max = 0;
    /**
     * 计算最大增量 h=3*b+1
     */
    for (int i = 1; i < length; i=3*i+1) {
        increment_max = i;
    }
    /**
     * 分别对每个分组进行直接插入排序
     */
    for (int i = increment_max; i >= 1 ; i=i/3) {
        for (int j = 0; (j<length-i)&&(j<i); ++j) {
            insert_sort(array,length,j,i);//插入排序
        }
    }
    for (int i = 0; i < length; ++i) {
        printf("%d\t",array[i]);
    }
    return 0;
}