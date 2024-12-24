#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypto.h"

int encrypt_file(const char* input_file, const char* output_file, int key) {
    FILE *in, *out;
    unsigned char buffer[BUFFER_SIZE];
    size_t bytes_read;

    // 打开输入文件
    in = fopen(input_file, "rb");
    if (!in) {
        print_error("无法打开输入文件");
        return -1;
    }

    // 打开输出文件
    out = fopen(output_file, "wb");
    if (!out) {
        print_error("无法创建输出文件");
        fclose(in);
        return -1;
    }

    // 简单的异或加密
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, in)) > 0) {
        for (size_t i = 0; i < bytes_read; i++) {
            buffer[i] ^= key;
        }
        fwrite(buffer, 1, bytes_read, out);
    }

    fclose(in);
    fclose(out);
    return 0;
}

int decrypt_file(const char* input_file, const char* output_file, int key) {
    // 解密与加密使用相同的异或算法
    return encrypt_file(input_file, output_file, key);
}

void print_error(const char* message) {
    fprintf(stderr, "错误: %s\n", message);
}