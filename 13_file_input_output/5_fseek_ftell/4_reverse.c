/* reverse.c -- 倒序显示文件的内容 */
/* fseek()的第1个参数是FILE指针，指向待查找的文件，fopen()应该已打开该文件。
 * seek()的第2个参数是偏移量（offset）。该参数表示从起始点开始要移动的距离（参见表13.3列出的起始点模式）。
 * 该参数必须是一个long类型的 值，可以为正（前移）、负（后移）或0（保持不动）
 * fseek()的第3个参数是模式，该参数确定起始点
 * 如果一切正常，fseek()的返回值为0；如果出现错误（如试图移动的距离超出文件的范围），其返回值为-1。
 * 
 * ftell()函数的返回类型是long，它返回的是当前的位置
 * ftell()通过返回距文件开始处的字节 数来确定文件的位置。
 * 文件的第1个字节到文件开始处的距离是0，以此类推。
*/
#include <stdio.h> 
#include <stdlib.h> 

#define CNTL_Z '\032'   /* DOS文本文件中的文件结尾标记 */
#define SLEN 81

int main(int argc, char const *argv[])
{
    char file[SLEN]; 
    char ch; 
    FILE *fp; 
    long count, last; 

    puts("Enter the name of the file to be processed:"); 
    scanf("%80s", file); 

    if ((fp = fopen(file, "rb")) == NULL)
    {   /* 只读模式 */
        printf("reverse can't open %s\n", file); 
        exit(EXIT_FAILURE);
    }

    fseek(fp, 0L, SEEK_END);  /* 定位到文件末尾 */
    last = ftell(fp);
    for (count = 1L; count <= last; count++)
    {
        fseek(fp, -count, SEEK_END);       /* 回退 */ 
        ch = getc(fp); 
        if (ch != CNTL_Z && ch != '\r') /* MS-DOS 文件 */ 
            putchar(ch);
    }

    putchar('\n'); 
    fclose(fp);

    return 0;
}
