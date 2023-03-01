// C字符、字符串和I/O相关函数使用总结
#include <stdio.h>
#include <string.h>

// getchar putchar
void test_char_functions(void)
{
    char c;
    // 键盘回显
    printf("echo keyboard.\n");
    while((c = getchar()) != EOF)
    {
        putchar(c);
    }
    putchar('\n');
}

void test_string(void)
{
    char string[1000];

    printf("test string.\n");
    //标准
    scanf("%s", string);
    printf("%s.\n", string);

    //旧版字符串I/O,已被删除。获取一行，丢弃换行符
    //gets(string);
    //输出中会添加换行符
    //puts(string);

    //这两者之间有个回车在输入缓冲，去掉回车符
    getchar();

    //新版安全的,换行符会读入字符串
    fgets(string, 1000, stdin);
    //不会在输出添加换行符
    fputs(string, stdout);
    
    //字符串操作函数
    printf("s:%s. strlen:%u.\n", string, strlen(string));
}

int main(void)
{
    test_char_functions();
    test_string();

    return 0;
}