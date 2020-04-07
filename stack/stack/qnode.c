#include <stdio.h>
#include <stdlib.h> 

typedef struct Qnode {
	struct Qnode* next;
	int data;
}Qnode;

typedef struct list {
	Qnode* head;
	Qnode* tail;
}list;

void queueInit(list* s) {
	s->head = s->tail = NULL;
}

Qnode* CreatNode(int x) {
	Qnode* node = (Qnode*)malloc(sizeof(Qnode));
	node->data = x;
	node->next = NULL;
	return node;
}

//���
void QueuePush(list* s, int x) {
	Qnode* newnode = CreatNode(x);
	if (s->head == NULL) {
		s->head = s->tail = newnode;
	}
	else {
		s->tail->next = newnode;
		s->tail = newnode;
	}
}



//����
void QueuePop(list* s) {
	if (s->head == NULL) {
		return;
	}
	else {
		Qnode* cur = s->head;
		s->head = s->head->next;
		free(cur);
		cur = NULL;
		if (s->head == NULL) {
			s->tail = NULL;
		}
	}
}

//��ȡ��ͷԪ��
int QueueHead(list* s) {
	if (s->head == NULL) {
		return ;
	}
	else {
		return s->head->data;
	}
}

//��ȡ��βԪ��
int QueueTail(list* s) {
	if (s->tail == NULL) {
		return ;
	}
	else {
		return s->tail->data;
	}
}

//��ն���
void QueueDel(list* s) {
	if (s->head == NULL) {
		return;
	}
	else {
		Qnode* cur = s->head;
		while (s->head) {
			cur = s->head;
			s->head = s->head->next;
			free(cur);
			cur = NULL;
		}
		s->tail = NULL;
	}
}

int main() {
	list s;
	queueInit(&s);
	QueuePush(&s,1);
	printQueue(&s);
	QueuePush(&s, 2);
	printQueue(&s);
	QueuePush(&s, 3);
	printQueue(&s);
	QueuePush(&s, 4);
	printQueue(&s);
	QueuePush(&s, 5);
	printQueue(&s);
	printf("%d\n", QueueHead(&s));
	printf("%d\n", QueueTail(&s));
	QueueDel(&s);
	printQueue(&s);


	system("pause");
	return 0;
}