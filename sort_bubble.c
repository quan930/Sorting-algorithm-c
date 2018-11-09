#include "stdio.h"
int main(){
    /**
     * 冒泡排序
     */
    int array[] = {12,11,14,10,20,7};//6
    int length = sizeof(array)/ sizeof(int);
    int temp;
    for (int i = 0; i < length-1; ++i) {
        for (int j = 0; j < length-i-1; ++j) {
            if (array[j]>array[j+1]){
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    for (int i = 0; i < length; ++i) {
        printf("%d\t",array[i]);
    }
}