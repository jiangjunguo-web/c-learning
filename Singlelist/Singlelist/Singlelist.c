#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>

typedef int Type;
//节点结构体
typedef struct Node {
	Type data;
	struct Node* next;
}Node;
//链表结构体：存放节点元素
typedef struct Slist {
	Node* _head;
}Slist;
//创建节点元素
Node* BuySListNode(Type x) {
	Node* sl = (Node*)malloc(sizeof(Node)) ;
	sl->data = x;
	sl->next = NULL;
	return sl;
}

//初始化
void SListInit(Slist* plist) {
	plist->_head = NULL;
}
// 单链表打印
void SListPrint(Slist* plist){
	Node* s = plist->_head;
	while (s) {
		printf("%d  ", s->data);
		s = s->next;
	}
	printf("\n");
}
// 单链表尾插
void SListPushBack(Slist* pplist, Type x) {
	//创建节点元素
	Node* node = BuySListNode(x);
	//如果是空表
	if (pplist->_head == NULL) {
		pplist->_head = node;
		node->next = NULL;
	}
	//表里有元素
	else {
		Node* cur = pplist->_head;
		while (cur->next) {
			cur = cur->next;
		}
		cur->next = node;
		node->next = NULL;
	}	
}
// 单链表的头插
void SListPushFront(Slist* pplist, Type x) {
	Node* node = BuySListNode(x);
	//空表插入
	if (pplist->_head == NULL) {
		pplist->_head = node;
	}
	//有元素状况
	else {
		node->next = pplist->_head;
		pplist->_head = node;
	}
}

// 单链表的尾删
void SListPopBack(Slist* pplist) {
	Node* pre = NULL;
	Node* tail = pplist->_head;
	//1、空或者只有一个节点
	//2、两个及以上各节点
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
// 单链表头删
void SListPopFront(Slist* pplist) {
	//没有元素则不操作，否则依次删
	if (pplist->_head) {
		Node* cur = pplist->_head;
		pplist->_head = pplist->_head->next;
		free(cur);
		cur = NULL;
	}
}

// 单链表查找
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

// 单链表在pos位置之后插入x
void SListInsertAfter(Node* pos, Type x){
	assert(pos);
	Node* next = pos->next;
	Node* newNode = BuySListNode(x);
	pos->next = newNode;
	newNode->next = next;
}
// 单链表删除pos位置之后的值
void SListEraseAfter(Node* pos) {
	//必须有两个及以上的节点元素
	assert(pos && pos->next);
	Node* next = pos->next;
		pos->next = next->next;
		free(next);
		next = NULL;
}

// 单链表的销毁
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