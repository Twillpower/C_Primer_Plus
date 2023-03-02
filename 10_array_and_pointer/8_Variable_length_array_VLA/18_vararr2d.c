//vararr2d.c -- 使用变长数组的函数
#include <stdio.h>
#define ROWS 3
#define COLS 4

int sum2d(int rows, int cols, const int ar[rows][cols]);

int main(int argc, char const *argv[])
{
    int i, j;
    int rs = 3;
    int cs = 10;

    int junk[ROWS][COLS] = {
        {2, 4, 6, 8},
        { 3, 5, 7, 9 },
        { 12, 10, 8, 6 }
    };
    int morejunk[ROWS - 1][COLS + 2] = {
        { 20, 30, 40, 50, 60, 70 },
        { 5, 6, 7, 8, 9, 10 }
    };
    int varr[rs][cs];   // 变长数组（VLA）

    for(i = 0; i < rs; i++)
        for(j = 0; j < cs; j++)
            varr[i][j] = i*j+j;
    printf("3x5 array\n");
    printf("Sum of all elements = %d\n", sum2d(ROWS, COLS, junk));
    printf("2x6 array\n");
    printf("Sum of all elements = %d\n", sum2d(ROWS - 1, COLS + 2, morejunk));
    printf("3x10 VLA\n");
    printf("Sum of all elements = %d\n", sum2d(rs, cs, varr));

    return 0;
}

/* 带变长数组形参的函数
 * 变长数组中的“变”不是指可以修改已创建数组的大小。一旦创建了变长
 * 数组，它的大小则保持不变。这里的“变”指的是：在创建数组时，可以使用变量指定数组的维度。
 * 
 * 前两个形参（rows和cols）用作第3个形参二维数组ar的两个维度
 * 在形参列表中必须在声明ar之前先声明这两个形参
 * 
 * C99/C11标准规定，可以省略原型中的形参名，但是在这种情况下，必
 * 须用星号来代替省略的维度
 * int sum2d(int, int, int ar[*][*]); // ar是一个变长数组（VLA），省略了维度形参名
 *
 * 变长数组名实际上是一个指针。这说明带变长数 
 * 组形参的函数实际上是在原始数组中处理数组，因此可以修改传入的数组。
 * 
 * C99/C11 标准允许在声明变长数组时使用 const 变量。所以该数组的定
 * 义必须是声明在块中的自动存储类别数组。
 */
int sum2d(int rows, int cols, const int ar[rows][cols])
{
    int r;
    int c;
    int tot = 0;

    for (r = 0; r < rows; r++)
        for (c = 0; c < cols; c++)
            tot += ar[r][c];
    
    return tot;
}