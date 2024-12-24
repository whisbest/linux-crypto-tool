#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crypto.h"

int main(int argc, char *argv[]) {
    char input_file[MAX_FILENAME];
    char output_file[MAX_FILENAME];
    int key, mode;

    // 检查参数
    if (argc != 5) {
        fprintf(stderr, "使用方法: %s <mode> <input_file> <output_file> <key>\n", argv[0]);
        fprintf(stderr, "mode: 1 (加密), 2 (解密)\n");
        return 1;
    }

    // 解析参数
    mode = atoi(argv[1]);
    strncpy(input_file, argv[2], MAX_FILENAME - 1);
    strncpy(output_file, argv[3], MAX_FILENAME - 1);
    key = atoi(argv[4]);

    // 执行加密或解密
    switch (mode) {
        case 1:
            if (encrypt_file(input_file, output_file, key) == 0) {
                printf("文件加密成功\n");
            }
            break;
        case 2:
            if (decrypt_file(input_file, output_file, key) == 0) {
                printf("文件解密成功\n");
            }
            break;
        default:
            fprintf(stderr, "无效的模式。使用 1 (加密) 或 2 (解密)\n");
            return 1;
    }

    return 0;
}