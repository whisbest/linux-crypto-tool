CC = gcc
CFLAGS = -Wall -Wextra -g

# 目标文件
TARGET = crypto

# 源文件
SRCS = main.c crypto.c

# 目标文件列表
OBJS = $(SRCS:.c=.o)

# 默认目标
all: $(TARGET)

# 链接可执行文件
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# 编译源文件为目标文件
%.o: %.c crypto.h
	$(CC) $(CFLAGS) -c $<

# 清理编译生成的文件
clean:
	rm -f $(OBJS) $(TARGET)

# 伪目标
.PHONY: all clean