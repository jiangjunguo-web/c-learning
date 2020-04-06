#include <stdio.h>
#include <stdlib.h> 

typedef struct node {
	int val;
	struct node* prev;
	struct node* next;
}node;

typedef struct list{
	struct node* head;
}list;

struct node* Creatnode(int x){
	struct node* node = (struct node*) malloc(sizeof(struct node));
	node->next = NULL;
	node->prev = NULL;
	node->val = x;
	return node;
}

void InitList(list* s) {
	struct node* node = (struct node*) malloc(sizeof(struct node));
	s->head = node;
	node->next = node;
	node->prev = node;
}

//ͷ�����
void ListPushFront(list* s,int x) {
	struct node* cur = s->head;

	struct node* node = Creatnode(x);
	node->next = cur ->next;
	cur->next->prev = node;
	cur->next = node;
	node->prev = cur;
}

//β�����
void ListPushBack(list* s, int x) {
	struct node* cur = s->head;
	struct node* node = Creatnode(x);
	node->next = cur;
	node->prev = cur->prev;

	cur->prev->next = node;
	cur->prev = node;
}

//��ӡ����
void ListPrint(list* s) {
	struct node* cur = s->head;
	while (cur->next != s->head) {
		cur = cur->next;
		printf("%d   ", cur->val);
	}
	printf("\n");
}

//βɾ����
void ListPopBack(list* s) {
	
    //����ͷ�ڵ�
	if (s->head->next == s->head) {
		return;
	}
	else {
		struct node* cur = s->head->prev;
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		free(cur);
		cur = NULL;
	}
}

//ͷɾ����
void ListPopFront(list* s) {
	if (s->head->next == s->head) {
		return;
	}
	else {
		struct node* cur = s->head->next;
		cur->prev->next = cur->next;
		cur->next->prev = cur->prev;
		free(cur);
		cur = NULL;
	}
} 

//����λ�õ�ǰ�����
void ListInsert(node* pos, int x) {
	struct node* node = Creatnode(x);
	node->next = pos;
	node->prev = pos->prev;
	pos->prev->next = node;
	pos->prev = node;
}

//���Һ���
node* ListFind(list* s, int x) {
	if (s->head == s->head->next) {
		return NULL;
	}
	else {
		node* cur = s->head->next;
		while (cur != s->head){
			if (cur->val == x) {
				return cur;
			}
			else cur = cur->next;
		}
		return NULL;
	}
}

//����λ��ɾ������
void ListErase(node* pos) {
	if (pos->next == pos) {
		return;
	}
	else {
		pos->next->prev = pos->prev;
		pos->prev->next = pos->next;
		free(pos);
		
	}
}

//��ղ���
void Dele(list* s) {
	while (s->head != s->head->next)
	ListPopBack(s);

	free(s->head);
	s->head = NULL;
}

int main(){
	list s;
	list* s1 = &s;
	node* pos;
	InitList(&s);
	ListPushBack(&s, 1);
	ListPushBack(&s, 2);
	ListPushBack(&s, 3);
	ListPushBack(&s, 4);
	ListPushBack(&s, 5);
	ListPushBack(&s, 6);
	pos = ListFind(&s, 5);
	ListPrint(&s);
	ListInsert(s1->head, 7);
	ListPrint(&s);
	ListErase(pos);
	ListPrint(&s);
	ListErase(s1->head->next);
	ListPrint(&s);
	ListErase(s1->head->prev);
	ListPrint(&s);
	Dele(&s);
	ListPrint(&s);


	system("pause");
	return 0;
}