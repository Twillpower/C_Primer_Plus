#include <stdio.h>

int main(void)
{
    //（从缓冲区把数据发送到屏幕或文件被 称为刷新缓冲区）
    // 当缓冲区满，遇到换行符或需要输入或程序运行结束时，把缓冲区中的内容发送到屏幕
    //此处上述条件均为满足，不输出Hello World!
    printf("Hello World!");
    while(1);

    return 0;
}