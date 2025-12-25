# 编译器
CC = gcc
# 编译选项
CFLAGS = -Wall -Wextra -g

# 目标文件
TARGET = parser_app
# 源文件
SRCS = main.c parser.c
# 目标文件
OBJS = $(SRCS:.c=.o)

# 默认目标：编译可执行文件
all: $(TARGET)

# 链接生成可执行文件
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# 编译 .c 文件为 .o 文件
%.o: %.c parser.h
	$(CC) $(CFLAGS) -c $< -o $@

# 清理编译产物
clean:
	rm -f $(OBJS) $(TARGET) libparser.a libparser.so core

# 编译静态库（libparser.a）
static_lib: parser.o
	ar rs libparser.a parser.o

# 编译动态库（libparser.so）
shared_lib: parser.c parser.h
	$(CC) $(CFLAGS) -fPIC -shared -o libparser.so parser.c
