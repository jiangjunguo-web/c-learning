#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	char* arr;
	int size;
	int capacity;
}stack;

void Init(stack* s) {
	s->capacity = 20;
	s->size = 0;
	s->arr = (char*)malloc(sizeof(char)*s->capacity);
}

char StackPop(stack* s) {
	if (s->size == 0) {
		return 0;
	}
	else {
		s->size--;
		return s->arr[s->size];
	}
}

void stackPush(stack* s, char c) {
	if (s->size == s->capacity) {
		s->capacity = s->capacity * 2;
		s->arr = (char*)realloc(s->arr, sizeof(char)* s->capacity);
	}
	s->arr[s->size++] = c;
}

int  isValid(char* s){
	stack* st = (stack*)malloc(sizeof(stack));
	Init(st);
	int i = 0;
	while (s[i]) {
		if ((s[i] - 0x30) == -8 || (s[i] - 0x30) == 43 || (s[i] - 0x30) == 75) {
			stackPush(st, s[i]);
		}
		else {
			if (s[i] == ')') {
				if (StackPop(st) != '(')
					return 0;
			}
			else if (s[i] == ']') {
				if (StackPop(st) != '[')
					return 0;
			}
			else if (s[i] == '}') {
				if (StackPop(st) != '{')
					return 0;
			}
		}
		i++;
	}
	if (StackPop(st) != 0) {
		return 0;
	}
	return 1;
}

int main() {
	char s[] = "()";
	printf("%d", isValid(s));
	system("pause");
	return 0;
}