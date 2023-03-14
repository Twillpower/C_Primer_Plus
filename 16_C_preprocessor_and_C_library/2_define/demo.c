#include <stdio.h>

#define LIMIT 20

int main(int argc, char const *argv[])
{
    // 披着常量外衣的变量，只能使用在可以使用变量的地方
    const int LIM = 50;

    static int data1[LIMIT];
    // 使用static要将data2里的元素都初始化为0，即数组data2是一个确定大小且被初始化的对象
    // 使用静态变量要使用确定的值(常量)
    // static int data2[LIM];
    // 非静态变量，只在运行到此处时才会分配空间，所以可使用变量
    int data3[LIM];

    const int LIM2 = 2 * LIMIT;
    const int LIM3 = 2 * LIM;

    return 0;
}
