#include "stdio.h"
void fun();
void fun1();
void xuanzhe();
int main(){
//    int array[] = {13,10,18,16,100,11,15};
//    int length = sizeof(array)/ sizeof(int);
//    int temp;
//    for (int i = 0; i < length-1; ++i) {
//        for (int j = 0; j < length-1-i; ++j) {
//            if (array[j]>array[j+1]){
//                temp = array[j];
//                array[j] = array[j+1];
//                array[j+1] = temp;
//            }
//        }
//    }
//    for (int i = 0; i < length; ++i) {
//        printf("%d\t",array[i]);
//    }

    int array[] = {13,10,15,13,16};
    const int length = 5;
    for (int i = 0; i < length; ++i) {
        printf("%d\t",array[i]);
    }
    printf("\n\n");
//    int array1[length];
//    for (int i = 0; i < length; ++i) {
//        array1[i] = array[i];
//    }
//    for (int i = 0; i < length; ++i) {
//        printf("%d\t",array1[i]);
//    }
    int temp;
    for (int i = 0; i < length/2; ++i) {
        temp = array[i];
        array[i] = array[length-i-1];
        array[length-i-1] = temp;
    }
    for (int i = 0; i < length; ++i) {
        printf("%d\t",array[i]);
    }
}


void xuanzhe(){
    int array[] = {13,10,18,16,100,11,15};
    int length = sizeof(array)/ sizeof(int);
    int temp;
    int place;
    for (int i = 0; i < length; ++i) {
        temp = array[i];
        place = i;
        for (int j = i; j < length; ++j) {
            if (array[j]>temp){
                temp = array[j];
                place = j;
            }
        }
        array[place] = array[i];
        array[i] = temp;
    }
    for (int i = 0; i < length; ++i) {
        printf("%d\t",array[i]);
    }
}


void fun(){
    int array[] = {12,13,14,15,16,17,18};
    int length = sizeof(array)/ sizeof(int);
    int temp;
    for (int i = 0; i < length/2; ++i) {
        temp = array[i];
        array[i] = array[length-i-1];
        array[length-i-1] = temp;
    }
    for (int j = 0; j < length; ++j) {
        printf("%d,",array[j]);
    }
}

void fun1(){
    int array[] = {13,10,18,16,100,11,15};
    int length = sizeof(array)/ sizeof(int);
    int temp;
    for (int i = 0; i < length; ++i) {
        for (int j = i; j < length; ++j) {
            if (array[j]>array[i]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    for (int i = 0; i < length; ++i) {
        printf("%d\t",array[i]);
    }
}