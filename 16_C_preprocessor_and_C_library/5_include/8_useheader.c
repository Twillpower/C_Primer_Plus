// useheader.c -- 使用 names_st 结构
#include <stdio.h> 
#include "6_names_st.h" // 记住要链接 names_st.c

int main(int argc, char const *argv[])
{
    names candidate; 
    get_names(&candidate); 
    printf("Let's welcome "); 
    show_names(&candidate); 
    printf(" to this program!\n");

    return 0;
}
