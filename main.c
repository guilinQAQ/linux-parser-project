#include "parser.h"
#include <stdio.h>

int main() {
    char str[] = "Linux;Shell;Git;GCC;Makefile";
    const char delimiter[] = ";";
    int count = 0;
    char** parts = str_split(str, delimiter, &count);

    printf("分割字符串: %s\n", str);
    printf("分割结果（共 %d 部分）:\n", count);
    for (int i = 0; i < count; i++) {
        printf("%d: %s\n", i+1, parts[i]);
    }

    free_split(parts, count);
    return 0;
}
