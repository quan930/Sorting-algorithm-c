//
// Created by daquan on 2019/3/14.
// 大数阶乘
//
#include "stdio.h"
#include "math.h"
#define n 50
int main(){
    int digits = (int)ceil(log10(2*M_PI*n)/2 + n*log10((n/M_E)));//求近似位数 向上取整
    int maxNum[digits];
    int currentDigit=1;//当前位数
    maxNum[currentDigit-1]=1;
    int temp;
    for (int i = 1; i <= n; ++i) {
        int num=0;
        for(int j=0;j<currentDigit;j++)
        {
            temp=maxNum[j]*i+num;//将一个数的每一位数都分别乘以i，
            maxNum[j]=temp%10;//将一个数的每一位数利用数组进行储存
            num=temp/10;
        }
        while(num)//判断退出循环后，num的值是否为0
        {
            maxNum[currentDigit]=num%10;//继续储存
            num=num/10;
            currentDigit++;
        }
    }
    for (int i = digits; i > 0 ; --i) {
        printf("%d",maxNum[i-1]);
    }
    return 0;
}
