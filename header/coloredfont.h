//
// Created by 全 on 2020/7/24.
//

#ifndef DEMO2_COLOREDFONT_H
#define DEMO2_COLOREDFONT_H
typedef enum colors_font{DARK_RED,REDS,DARK_GREEN,GREEN,DARK_YELLOW,YELLOW,DARK_BLUE,BLUE,DARK_PURPLE,PURPLE} colors_font;
//彩色字体输出
void print_colors_font(colors_font color ,char* fonts,int fontslen,int restric,...);
#endif //DEMO2_COLOREDFONT_H
