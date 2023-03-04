/* append.c -- 把文件附加到另一个文件末尾 */

/* int setvbuf(FILE * restrict fp, char * restrict buf, int mode, size_t size);

 * setvbuf()函数创建了一个供标准I/O函数替换使用的缓冲区

 * 在打开文件后且未对流进行其他操作之前，调用该函数。

 * 指针fp识别待处理的流，buf 指向待使用的存储区。如果buf的值不是NULL，则必须创建一个缓冲区
 * 如果把 NULL作为buf的值，该函数会为自己分配一个缓冲区。
 * 
 * 变量size告诉setvbuf() 数组的大小
 * 
 * _IOFBF表示完全缓冲（在缓冲区满时刷新）；
 * _IOLBF表示行缓冲（在 缓冲区满时或写入一个换行符时）；
 * _IONBF表示无缓冲。如果操作成功， 函数返回0，否则返回一个非零值
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFSIZE 4096
#define SLEN 81

void append(FILE *source, FILE *dest);
char *s_gets(char *st, int n);

int main(int argc, char const *argv[])
{
    FILE *fa, *fs;  //fa 指向目标文件，fs 指向源文件
    int files = 0;   //附加的文件数量
    char file_app[SLEN];    //目标文件名
    char file_src[SLEN]; //源文件名
    int ch;

    puts("Enter name of destination file:");
    s_gets(file_app, SLEN); // get目标文件名
    if((fa = fopen(file_app, "a+")) == NULL)  // 追加模式打开文件
    {
        fprintf(stderr, "Can't open %s\n", file_app);
        exit(EXIT_FAILURE);
    }
    // 为流fa(目标文件)自动分配一个指定大小的全缓冲，缓冲区大小为BUFSIZE
    if(setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }
    puts("Enter name of first source file (empty line to quit):");
    // get源文件名
    while (s_gets(file_src, SLEN) && file_src[0] != '\0') //读取成功且不为空
    {
        if(strcmp(file_src, file_app) == 0)  //若目标文件名和源文件名一样
            fputs("Can't append file to itself\n", stderr);
        else if ((fs = fopen(file_src, "r")) == NULL) // 否则如果打开源文件名为空
        {
            fprintf(stderr, "Can't open %s\n", file_src);
        }
        else
        {
            // 为流fs(源文件)自动分配一个指定大小的全缓冲，缓冲区大小为BUFSIZE
            if(setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
            {
                fputs("Can't create input buffer\n", stderr);
                continue;
            }
            append(fs, fa); /* 将源文件的内容追加到目标文件后面 */
            
            /* 当上一次输入调用检测到文件结尾时，feof()函数返回一个非零值，否则返回0。
             * 当读或写出现错误，ferror()函数返回一个非零值，否则返回0。 */
            if(ferror(fs) != 0)
                fprintf(stderr, "Error in reading file %s.\n", file_src);
            if(ferror(fa) != 0)
                fprintf(stderr, "Error in writing file %s.\n", file_app);

            fclose(fs);
            files++;  //附加的文件数量 + 1
            printf("File %s appended.\n", file_src);
            puts("Next file (empty line to quit):");
        } 
    }
    printf("Done appending.%d files appended.\n", files);
    rewind(fa);  // 令fa指向文件头
    printf("%s contents:\n", file_app);
    // 从fa中获取一个字符，
    while ((ch = getc(fa)) != EOF)
    {
        putchar(ch);    //若没到结尾则输出该字符
    }
    puts("\nDone displaying.");
    fclose(fa);

    return 0;
}

/* size_t fwrite(const void * restrict ptr, size_t size, size_t nmemb,FILE * restrictfp);
 * write()函数把二进制数据写入文件。
 * size_t是根据标准C类型定义的类型，它是sizeof运算符返回的类型，通常是unsigned int，
 * 但是实现可以选择使用其他类型。指针ptr是待写入数据块的地址。
 * size表示待写入数据块的大小（以字节为单位），nmemb表示待写入数据块的数量
 * fp指定待写入的文件
 * 
 * fwrite()函数返回成功写入项的数量。正常情况下，该返回值就是nmemb，
 * 但如果出现写入错误，返回值会比nmemb小
 * 
 * ize_t fread(void * restrict ptr, size_t size, size_t nmemb,FILE * restrict fp);
 * fread()函数接受的参数和fwrite()函数相同
 * ptr是待读取文件数据在内存中的地址，fp指定待读取的文件
 * 
 * fread()函数返回成功读取项的数量。正常情况下，该返回值就是nmemb，
 * 但如果出现读取错误或读到文件结尾，该返回值就会比nmemb小
*/
/* 将source的内容追加到dest后面 */
void append(FILE *source, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE];  //只分配一次
    // 从source中读取sizeof(char) * BUFSIZE大小的数据存放到temp中
    while ((bytes = fread(temp, sizeof(char), BUFSIZE, source)) > 0)
    {
        // 将temp中的sizeof(char) * bytes大小的数据写入到dest中
        fwrite(temp, sizeof(char), bytes, dest);
    }
    
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    // st: 输入存放位置；n: 输入字符读取长度；
    ret_val = fgets(st, n, stdin);
    if (ret_val)    // 若输入读取成功
    {
        find = strchr(st, '\n');    // 查找换行符
        if(find)        // 如果地址不是NULL，
            *find = '\0';       //将\n替换为\0
        else
            while (getchar() != '\n')   //如果字符串中出现空字符，就丢弃该输入行的其余字符
            {
                continue;
            }      
    }
    return ret_val;
}