#ifndef PARSER_H
#define PARSER_H

// 功能：将字符串按分隔符分割，返回分割后的字符串数组
char** str_split(char* str, const char* delimiter, int* count);

// 功能：释放字符串数组内存
void free_split(char** arr, int count);

#endif
