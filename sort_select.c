#include "stdio.h"
#include "time.h"
int main(){
    /**
     * 选择排序
     */
    clock_t start, finish;
    int array[] = {3,1,4,2,5,7,6,8,7,76,100,23,10,3};
    double total_time;
    int length = sizeof(array)/ sizeof(int);
    int temp;
    int position;
    start = clock();
    for (int i = 0; i < length-1; ++i) {
        temp = array[i];
        position = i;
        for (int j = i+1; j < length; ++j) {
            if (array[j]<temp){
                temp = array[j];
                position = j;
            }
        }
        if (position!=i){
            array[position] = array[i];
            array[i] = temp;
        }
    }
    finish = clock();
    total_time = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("%f\n",total_time);
    for (int i = 0; i < length; ++i) {
        printf("%d\t",array[i]);
    }
}