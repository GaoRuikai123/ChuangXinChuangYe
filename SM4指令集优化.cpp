#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<iostream>
using namespace std;
LARGE_INTEGER t1, t2, tc;
#include "sm4_aesni_x4.h"
void time_begin()
{
	QueryPerformanceFrequency(&tc);
	QueryPerformanceCounter(&t1);
}
float time_end()
{
	QueryPerformanceCounter(&t2);
	return ((t2.QuadPart - t1.QuadPart) * 1.0 / tc.QuadPart) * 1000;
}
int main() {
	unsigned char key[16 * 8] = { 0x01, 0x23, 0x45, 0x67, 0x89, 0xab,
	0xcd, 0xef, 0xfe, 0xdc, 0xba, 0x98,
	0x76, 0x54, 0x32, 0x10 };
	unsigned char in[16 * 4] = { 0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef,
	0xfe, 0xdc, 0xba, 0x98, 0x76, 0x54, 0x32, 0x10 };
	SM4_Key sm4_key;
	time_begin();
	SM4_KeyInit(key, &sm4_key);
	SM4_AESNI_Encrypt_x4(in, in, &sm4_key);
	printf("C:\n");
	for (int j = 0; j < 4; j++) {
		printf("\t");
		for (int i = 0; i < 16; i++) {
			printf("%02x ", in[i + 16 * j]);
		}
		printf("\n");
	}
	printf("P:\n");
	cout << "加密所用时间: " << time_end() << "ms" << endl;
	time_begin();
	SM4_AESNI_Decrypt_x4(in, in, &sm4_key);
	for (int j = 0; j < 4; j++) {
		printf("\t");
		for (int i = 0; i < 16; i++) {
			printf("%02x ", in[i + 16 * j]);
		}
		printf("\n");
	}
	cout << "解密所用时间: " << time_end() << "ms" << endl;
	return 0;
}