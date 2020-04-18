#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef int HeapData;

typedef  struct Heap {
	HeapData* _array;
	int size;
	int capacity;
}Heap;

void Swap(HeapData* arr,int change1,int change2) {
	*(arr + change1) ^= *(arr + change2) ;
	*(arr + change2) ^= *(arr + change1) ;
	*(arr + change1) ^= *(arr + change2) ;
}

void shiftDown(HeapData* arr ,int size,int parent) {
	int child = parent * 2 + 1;
	while (child < size) {
		if(child + 1 < size && arr[child + 1] < arr[child] ) {
			++child;
		}
		if(arr[child] < arr[parent]) {
			Swap(arr,child,parent);
			parent = child;	
			child = 2 * parent + 1;
		}
		else 
			break;
	}

}

void shiftUp(HeapData* arr,int child) {
	int parent = (child - 1) / 2;
	while(parent >= 0) {
		if(arr[parent] > arr[child]) {
			Swap(arr,parent,child);
			child = parent;
			parent = (child - 1) / 2;
		}
		else 
			break;
	}
}

void heapCreat(Heap* h,HeapData* arr,int size) {
	h->_array = (HeapData*) malloc (sizeof(HeapData) * size);
	h->size = size;
	h->capacity = size;
	memmove(h->_array,arr,size * sizeof(HeapData));
	int parent = (size - 2) / 2;
	while(parent >= 0) {
		shiftDown(h->_array,size,parent); 
		parent--;
	}
}

void heapPop(Heap* h,HeapData x) {
	h->_array = (HeapData*) realloc (h->_array,sizeof(HeapData)*(h->size + 1));
	h->size = h->size + 1;
	h->capacity++;
	h->_array[h->size - 1] = x;
	shiftUp(h->_array,h->size-1) ;
} 

void heapPush(Heap* h) {
	if(h == NULL) {
		return ;
	}
	Swap(h->_array,0,h->size - 1);
	h->size--;
	shiftDown(h->_array,h->size,0);
}


void printHeap(Heap* h) {
	int i = 0 ;
	while(h->size > i) {
 		printf("%d " , h->_array[i]);
		i++;
	}
	printf("\n");
}

int main() {
	Heap h;
	HeapData arr[] = {2,3,1,40,23,10,41,45};	
	int len = sizeof(arr) / sizeof(arr[0]) ;
	heapCreat(&h,arr,len) ;
	printHeap(&h);
	heapPop(&h,1);
	printHeap(&h);
	heapPush(&h);
	printHeap(&h);
	heapPush(&h);
	printHeap(&h);
	heapPush(&h);
	printHeap(&h);
	return 0;
}
