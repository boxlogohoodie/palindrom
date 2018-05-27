#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "palindrom.h"

int main() {
	FILE* f = fopen("Text.txt", "r");
	unsigned int N = 10, delta = 10, i = 0;
	wchar_t* buf = (wchar_t*)malloc(sizeof(wchar_t)*N);
	fseek(f, 0, SEEK_END);
	long size = ftell(f);
	while ((buf[i] = fgetc(f)) != EOF) {
		if (++i >= N) {
			N += delta;
			buf = (wchar_t*)realloc(buf, sizeof(wchar_t)*N); // неправильная работа
		}
	}
	fclose(f);
	buf[i] = '\0';
	puts(buf);
	menu();
	int m = 1;
	while (m != 0) {
		scanf_s("%d", &m);
		switch (m)
		{
		case 1:
			palindrom_task1(buf);
			break;
		case 2:
			palindrom_task2(buf);
			break;
		case 3:
			palindrom_task3(buf);
			break;
		case 9:
			menu();
			break;
		case 0:
			return 0;
		default:
			printf("Incorrect input, try again");
			break;
		}
	}
	return 0;
}