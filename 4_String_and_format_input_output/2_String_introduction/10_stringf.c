/* stringf.c -- 字符串格式 */ 
#include <stdio.h> 
#define BLURB "Authentic imitation!"

int main(void) 
{ 
    // 具体说明查看readme.md
    printf("[%2s]\n", BLURB); 
    printf("[%24s]\n", BLURB); 
    printf("[%24.5s]\n", BLURB);  // .5: 有效位为5位
    printf("[%-24.5s]\n", BLURB); 

    return 0; 
}