#include <stdio.h>

/* _Generic是C11的关键字。_Generic后面的圆括号中包含多个用逗号分隔
    的项。第1个项是一个表达式，后面的每个项都由一个类型、一个冒号和一 个值组成，
    如float: 1。第1个项的类型匹配哪个标签，整个表达式的值是该 标签后面的值。
    例如，假设上面表达式中x是int类型的变量，x的类型匹配 int:标签，那么整个表达式的值就是0
*/

#define MYTYPE(X) _Generic((X),\
int: "int",\
float : "float",\
double: "double",\
default: "other"\
)

int main(int argc, char const *argv[])
{
    int d = 5; 

    printf("%s\n", MYTYPE(d));  // d 是int类型
    printf("%s\n", MYTYPE(2.0*d));  // 2.0 * d 是double类型
    printf("%s\n", MYTYPE(3L));  // 3L 是long类型
    printf("%s\n", MYTYPE(&d)); // &d 的类型是 int *

    return 0;
}
