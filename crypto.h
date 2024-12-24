#ifndef CRYPTO_H
#define CRYPTO_H

#define MAX_FILENAME 256
#define BUFFER_SIZE 1024

// 加密函数
int encrypt_file(const char* input_file, const char* output_file, int key);

// 解密函数
int decrypt_file(const char* input_file, const char* output_file, int key);

// 打印错误信息
void print_error(const char* message);

#endif