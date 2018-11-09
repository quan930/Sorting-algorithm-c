#include "stdio.h"
void original(int[],int);
void optimize(int[],int);

int main(){
    /**
     * 插入排序
     */
    int array[] = {12,11,14,10,20,7,7,1};
    int length = sizeof(array)/ sizeof(int);
//    optimize(array,length);
    original(array,length);
}
void original(int array[],int length){
    int position = -1;
    int temp;
    for (int i = 1; i < length; ++i) {
        position=i;
        while (position>0){
            if (array[position]<array[position-1]){
                temp = array[position];
                array[position] = array[position-1];
                array[position-1] = temp;
                position --;
            } else{
                break;
            }
        }
//        for (int j = 0; j <= i; ++j) {
//            printf("%d\t",array[j]);
//        }
//        printf("\n");
    }
    for (int i = 0; i < length; ++i) {
        printf("%d\t",array[i]);
    }
}
void optimize(int array[],int length){
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
        for (int j = 0; j <= i; ++j) {
            printf("%d\t",array[j]);
        }
        printf("\n");
    }
    for (int i = 0; i < length; ++i) {
        printf("%d\t",array[i]);
    }
}