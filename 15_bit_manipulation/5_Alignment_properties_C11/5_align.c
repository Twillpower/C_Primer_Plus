// align.c -- 使用 _Alignof 和 _Alignas （C11）
// 在程序中包含 stdalign.h 头文件后，就可以把 alignas 和 alignof 分别作为 _Alignas 和_Alignof的别名。
// 这样做可以与C++关键字匹配
#include <stdio.h>

int main(int argc, char const *argv[])
{
    double dx; 
    char ca; 
    char cx; 
    double dz; 
    char cb; 
    char _Alignas(double) cz; 

    printf("char alignment: %zd\n", _Alignof(char)); 
    printf("double alignment: %zd\n", _Alignof(double)); 
    printf("&dx: %p\n", &dx); 
    printf("&ca: %p\n", &ca); 
    printf("&cx: %p\n", &cx);
    printf("&dz: %p\n", &dz); 
    printf("&cb: %p\n", &cb); 
    printf("&cz: %p\n", &cz);

    return 0;
}
