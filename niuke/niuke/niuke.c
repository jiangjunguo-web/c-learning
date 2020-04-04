#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
	int val;
	struct ListNode* next;
}ListNode;

typedef struct List{
	struct ListNode* head;
} List;

void InitList(List* s) {
	s->head = NULL;

}
//创建节点
ListNode* CreatNode(int x) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->val = x;
	node->next = NULL;
	return node;
}

//头插
void ListPopFront(List* s,int x){
	ListNode* node = CreatNode(x);
	ListNode* next = s->head;
	s->head = node;
	node->next = next;
}

void PrintList(List* s) {
	ListNode* cur = s->head;
	while (cur != NULL) {
		printf("%d  ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

ListNode* partition(ListNode* pHead, int x) {
	if (pHead == NULL){
		return NULL;
	}
	struct ListNode* lh = (struct ListNode*) malloc(sizeof(struct ListNode));
	struct ListNode* hh = (struct ListNode*) malloc(sizeof(struct ListNode));
	struct ListNode* fh1, *fh2;
	fh1 = lh;
	fh2 = hh;

	while (pHead) {
		if (pHead->val <= x) {
			fh1->next = pHead;
			fh1 = fh1->next;
			pHead = pHead->next;
		}
		else {
			fh2->next = pHead;
			fh2 = fh2->next;
			pHead = pHead->next;
		}
	}
	fh2->next = NULL;
	fh1->next = hh->next;
	return lh->next;
}

int main() {
	List s;
	List* a = &s;
	InitList(&s);
	ListPopFront(&s, 6);
	ListPopFront(&s, 3);
	ListPopFront(&s, 10);

	partition(a->head,4);
	PrintList(&s);
	system("pause");
	return 0;

}