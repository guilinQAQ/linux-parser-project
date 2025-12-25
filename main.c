#include "parser.h"
#include <stdio.h>

// 新增：统计字符串行数（按换行符分割）
void count_lines(char* str) {
    int lines = 1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n') {
            lines++;
        }
    }
    printf("字符串行数：%d\n", lines);
}

int main() {
    char str[] = "Linux;Shell;Git;GCC;Makefile\nDocker;Nginx;PHP;MariaDB\nLVM;NFS;DHCP;DNS";
    const char delimiter[] = ";";
    int count = 0;
    char** parts = str_split(str, delimiter, &count);

    printf("分割字符串: %s\n", str);
    count_lines(str);  // 调用行统计函数
    printf("分割结果（共 %d 部分）:\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i+1, parts[i]);
    }

    free_split(parts, count);
    return 0;
}
