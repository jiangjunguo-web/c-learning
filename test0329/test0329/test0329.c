#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int SLDateType;
typedef struct SeqList
{
	SLDateType* a;
	size_t size;
	size_t capacity; // unsigned int
}SeqList;


// �����ݵĹ���:��ɾ��� 
void SeqListInit(SeqList* ps) {
	ps->size = 0;
	ps->capacity = 4;
	ps->a = (SLDateType*)malloc(sizeof(SLDateType)*ps->capacity);
}


void SeqListDestory(SeqList* ps) {
	ps->size = 0;
	ps->capacity = 0;
	//memset(ps->a, 0, ps->capacity);
	free(ps->a);
}

void SeqListPrint(SeqList* ps) { 
	for (size_t i = 0; i < ps->size; i++){
		printf("%d ", ps->a[i]);
	}
	printf("\n");
};


void SeqListPushBack(SeqList* ps, SLDateType x) {
	ps->a[ps->size] = x;
	ps->size++;
};

void SeqListPushFront(SeqList* ps, SLDateType x) {
	size_t end = ps->size;
	while (end > 0) {
		ps->a[end] = ps->a[end - 1];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
};

void SeqListPopFront(SeqList* ps) {
	for (size_t i = 1; i < ps->size; i++) {
		ps->a[i - 1] = ps->a[i];
	}
	ps->size--;
};
void SeqListPopBack(SeqList* ps) {
	if (ps->size) {
		ps->size--;
	}
};

// ˳������
int SeqListFind(SeqList* ps, SLDateType x) {
	for (size_t i = 0; i < ps->size; i++) {
		if (ps->a[i] == x) {
			return i;
		}
	}
	return - 1;
};
// ˳�����posλ�ò���x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x) {
	if (ps->size == ps->capacity){
		ps->capacity += 20;
		SLDateType* b = (SLDateType*)realloc(ps->a, (ps->capacity)*sizeof(SLDateType));
		memcpy(b, ps->a, sizeof(SLDateType)*ps->capacity);
		ps->a = b;
	}
	size_t end = ps->size;
	while (end > pos) {
		ps->a[end] = ps->a[end - 1];
		end--;
	}
	ps->a[pos] = x;
	ps->size++;
};
// ˳���ɾ��posλ�õ�ֵ
void SeqListErase(SeqList* ps, size_t pos) {
	if (ps->size == 0) {
		return;
	}
	for (size_t i = pos+1; i < ps->size; i++) {
		ps->a[i - 1] = ps->a[i];
	}
	ps->size--;
};

void test() {
	SeqList a;
	SeqListInit(&a);
	SeqListPushBack(&a, 1);
	SeqListPrint(&a);
	/*printf("%d\n", SeqListFind(&a, 1));
	SeqListPushFront(&a, 2);
	SeqListPrint(&a);*/
	for (int i = 0; i < 100; i++) {
		SeqListInsert(&a, 0, i);
	}
	
	SeqListPrint(&a);
	for (int i = 0; i < 1000; i++) {
		SeqListErase(&a, 0);
	}
	
	SeqListPrint(&a);
	/*SeqListPushBack(&a, 3);
	SeqListPrint(&a);
	SeqListPopFront(&a);
	SeqListPrint(&a);
	SeqListPopBack(&a);
	SeqListPrint(&a);
	SeqListDestory(&a);
	SeqListPrint(&a);*/
}

int main(){

	test();
	system("pause");
	return 0;
}