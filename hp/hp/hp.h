#include <stdio.h>
#ifndef __BT_H__
#define __BT_H__

typedef struct Heap {
	int* str;
	int size;
	int capacity;
}Heap;

void shiftDown(int* str, int size, int parent);

void Swap(int* str, int op1, int op2);

void creatHeap(Heap* h, int* str, int len);

void shiftUp(int* str, int size, int child);

void delHeap(Heap* h);

void heapSort(Heap* h);



#endif
