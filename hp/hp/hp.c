#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hp.h"

void shiftDown(int* str, int size, int parent) {
	if (str == NULL || size <= 0 || parent < 0)
		return;
	int child = 2 * parent + 1;
	while (child < size) {
		if (child + 1 < size && str[child + 1] < str[child])
			child++;
		if (str[parent] > str[child])
			Swap(str, child, parent);
		parent = child;
		child = 2 * parent + 1;
	}

}

void Swap(int* str, int op1, int op2) {
	str[op1] ^= str[op2];
	str[op2] ^= str[op1];
	str[op1] ^= str[op2];
}

void creatHeap(Heap* h, int* str, int size) {
	if (str == NULL || size <= 0)
		return;
	h->capacity = size;
	h->str = (int*)malloc(h->capacity* sizeof(int));
	memcpy(h->str, str, sizeof(int) * size);
	h->size = size;
	int parent = (size - 2) / 2;
	while (parent > 0) {
		shiftDown(h->str, h->size, parent);
		parent--;
	}
}

void shiftUp(int* str, int size, int child) {
	if (child <= 0 || str == NULL || size <= 0)
		return;
	int parent = (child - 1) / 2;
	while (parent >= 0) {
		if (str[child] < str[parent])
			Swap(str, child, parent);
		child = parent;
		parent = (child - 1) / 2;
	}
}

int main() {
	Heap h;
	int str[] = { 2, 3, 5, 72, 1, 4, 6, 8 };
	int size = sizeof(str) / sizeof(str[0]);
	creatHeap(&h, str, size);
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", h.str[i]);
	printf("\n");
	system("pause");
}
