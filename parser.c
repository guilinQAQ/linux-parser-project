#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char** str_split(char* str, const char* delimiter, int* count) {
    char** result = NULL;
    char* token = strtok(str, delimiter);
    *count = 0;

    // 第一次分割，计数并分配内存
    while (token != NULL) {
        result = realloc(result, sizeof(char*) * (*count + 1));
        result[*count] = strdup(token);
        (*count)++;
        token = strtok(NULL, delimiter);
    }
    // 添加 NULL 结束符
    result = realloc(result, sizeof(char*) * (*count + 1));
    result[*count] = NULL;

    return result;
}

void free_split(char** arr, int count) {
    for (int i = 0; i < count; i++) {
        free(arr[i]);
    }
    free(arr);
}
