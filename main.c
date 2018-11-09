#include <stdio.h>
int sum = 0;
void fun(int line,int row){
    //杨辉三角形
    if (row==1||row==line)
    {
        sum++;
    }else{
        fun(line-1,row);
        fun(line-1,row-1);
    }
}

int main() {
    int count = 10;
    for (int i = 1; i <= count; ++i) {
        for (int j = 0; j <= count-i; ++j)
        {
            printf("   ");
        }
        for (int j = 1; j <= i; ++j) {
            sum = 0;
            fun(i,j);
            printf("%-6d",sum);
        }
        printf("\n");
    }
    return 0;
}