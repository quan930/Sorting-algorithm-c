#include "../header/coloredfont.h"
#include "stdio.h"
//
// Created by 全 on 2020/7/24.
// 彩色字
// print_colors_font(DARK_RED,"%3d--%-4d",9,12,11);
//

/**
 * 彩色字体输出
 * @param color 颜色
 * @param fonts 期望输出的格式
 * @param fontslen 格式化后的字符串长度
 * @param ... 字符串格式化参数可变长
 */
void print_colors_font(colors_font color ,char* fonts,int fontslen,int restric,...){
    char arr[fontslen];
    sprintf(arr,fonts,restric);
    switch (color){
        case DARK_RED:
            printf("\033[0;31m%s\033[0m",arr);
            break;
        case REDS:
            printf("\033[1;31m%s\033[0m",arr);
            break;
        case DARK_GREEN:
            printf("\033[0;32m%s\033[0m",arr);
            break;
        case GREEN:
            printf("\033[1;32m%s\033[0m",arr);
            break;
        case DARK_YELLOW:
            printf("\033[0;33m%s\033[0m",arr);
            break;
        case YELLOW:
            printf("\033[1;33m%s\033[0m",arr);
            break;
        case DARK_BLUE:
            printf("\033[0;34m%s\033[0m",arr);
            break;
        case BLUE:
            printf("\033[1;34m%s\033[0m",arr);
            break;
        case DARK_PURPLE:
            printf("\033[0;35m%s\033[0m",arr);
            break;
        case PURPLE:
            printf("\033[1;35m%s\033[0m",arr);
            break;
        default:
            printf("%s",arr);
            break;
    }
}