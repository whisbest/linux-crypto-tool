#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h> // 用于获取错误代码
#include "crypto.h" // 确保BUFFER_SIZE在此文件中定义

// 改进的错误处理函数
void print_error(const char* message, int errnum) {
    fprintf(stderr, "错误: %s (错误代码: %d)\n", message, errnum);
}

int encrypt_file(const char* input_file, const char* output_file, int key) {
    FILE *in, *out;
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;
    int err;

    // 打开输入文件
    in = fopen(input_file, "rb");
    if (!in) {
        print_error("无法打开输入文件", errno);
        return -1;
    }

    // 打开输出文件
    out = fopen(output_file, "wb");
    if (!out) {
        print_error("无法创建输出文件", errno);
        fclose(in);
        return -1;
    }

    // 简单的异或加密
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, in)) > 0) {
        if (ferror(in)) {
            print_error("读取输入文件时发生错误", errno);
            fclose(in);
            fclose(out);
            return -1;
        }
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key;
        }
        if (fwrite(buffer, 1, bytes_read, out) != bytes_read) {
            print_error("写入输出文件时发生错误", errno);
            fclose(in);
            fclose(out);
            return -1;
        }
    }

    if (feof(in)) {
        // 文件正常结束，无需处理
    } else {
        // 非正常结束，打印错误信息
        print_error("文件读取异常", errno);
    }

    fclose(in);
    fclose(out);
    return 0;
}
