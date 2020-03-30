#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>

typedef int Type;
//�ڵ�ṹ��
typedef struct Node {
	Type data;
	struct Node* next;
}Node;
//����ṹ�壺��Žڵ�Ԫ��
typedef struct Slist {
	Node* _head;
}Slist;
//�����ڵ�Ԫ��
Node* BuySListNode(Type x) {
	Node* sl = (Node*)malloc(sizeof(Node)) ;
	sl->data = x;
	sl->next = NULL;
	return sl;
}

//��ʼ��
void SListInit(Slist* plist) {
	plist->_head = NULL;
}
// �������ӡ
void SListPrint(Slist* plist){
	Node* s = plist->_head;
	while (s) {
		printf("%d  ", s->data);
		s = s->next;
	}
	printf("\n");
}
// ������β��
void SListPushBack(Slist* pplist, Type x) {
	//�����ڵ�Ԫ��
	Node* node = BuySListNode(x);
	//����ǿձ�
	if (pplist->_head == NULL) {
		pplist->_head = node;
		node->next = NULL;
	}
	//������Ԫ��
	else {
		Node* cur = pplist->_head;
		while (cur->next) {
			cur = cur->next;
		}
		cur->next = node;
		node->next = NULL;
	}	
}
// �������ͷ��
void SListPushFront(Slist* pplist, Type x) {
	Node* node = BuySListNode(x);
	//�ձ����
	if (pplist->_head == NULL) {
		pplist->_head = node;
	}
	//��Ԫ��״��
	else {
		node->next = pplist->_head;
		pplist->_head = node;
	}
}

// �������βɾ
void SListPopBack(Slist* pplist) {
	Node* pre = NULL;
	Node* tail = pplist->_head;
	//1���ջ���ֻ��һ���ڵ�
	//2�����������ϸ��ڵ�
	if (tail == NULL || tail->next == NULL) {
		free(tail);
		pplist->_head = NULL;
	}
	else {
		while (tail->next) {
			pre = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		pre->next = NULL;
	}
}
// ������ͷɾ
void SListPopFront(Slist* pplist) {
	//û��Ԫ���򲻲�������������ɾ
	if (pplist->_head) {
		Node* cur = pplist->_head;
		pplist->_head = pplist->_head->next;
		free(cur);
		cur = NULL;
	}
}

// ���������
Node* SListFind(Slist* plist, Type x) {
	Node* cur = plist->_head;
	while (cur) {
		if (cur->data == x) {
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}

// ��������posλ��֮�����x
void SListInsertAfter(Node* pos, Type x){
	assert(pos);
	Node* next = pos->next;
	Node* newNode = BuySListNode(x);
	pos->next = newNode;
	newNode->next = next;
}
// ������ɾ��posλ��֮���ֵ
void SListEraseAfter(Node* pos) {
	//���������������ϵĽڵ�Ԫ��
	assert(pos && pos->next);
	Node* next = pos->next;
		pos->next = next->next;
		free(next);
		next = NULL;
}

// �����������
void SListDestory(Slist* plist) {
	while(plist->_head) {
		Node* cur = plist->_head;
		plist->_head = plist->_head->next;
		free(cur);
		cur = NULL;
	}
}

int main(){
	Slist s;
	SListInit(&s);
	SListPushBack(&s, 1);
	SListPushBack(&s, 2);
	SListPushBack(&s, 3);
	Node* loca = SListFind(&s, 1);
	SListEraseAfter(loca);
	SListInsertAfter(loca, 5);
	SListPrint(&s);
	SListDestory(&s);
	SListPrint(&s);
	printf("%p", s._head);
	system("pause");
	return 0;
}