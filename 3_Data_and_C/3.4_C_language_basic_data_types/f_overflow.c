#include <stdio.h>

int main(void)
{
    // float类型必须至少能表示6位有效数字，且取值范围至少是10-37～10+37
    float toobig = 3.4E38 * 100.0f;
    // 浮点数上溢，赋一个表示无穷大的特定值，而且printf()显示该值为inf或infinity
    printf("%e\n", toobig);

    return 0;
}