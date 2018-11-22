//
// Created by daquan on 2018/11/22.
//
#include "stdio.h"

int main(){
    printf("hello world\n");
    int array1[]={2,3,6,8};
    int array2[]={1,4,5,7};
    int array[8];
    int length1 = sizeof(array1)/ sizeof(int);
    int length2 = sizeof(array2)/ sizeof(int);
    int *p1 = array1;
    int *p2 = array2;
    int *p = array;

    int m = 0;
    int move1=0;
    int move2=0;

    while (m<8){
        m++;
        if (move1>=length1){
            *p = *p2;
            p2++;
            move2++;
            p++;
            continue;
        }
        if (move2>=length2){
            *p = *p1;
            p1++;
            move1++;
            p++;
            continue;
        }
        if (*p1<*p2){
            *p = *p1;
            p1++;
            move1++;
        } else{
            *p = *p2;
            p2++;
            move2++;
        }
        p++;
    }

    for (int i = 0; i < length1+length2; ++i) {
        printf("%d\n",array[i]);
    }
    return 0;
}