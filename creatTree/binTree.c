#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
	int val;
	struct Node* left;
	struct Node* right;
}Node;

//creat a tree
Node* creatNode(char* arr,int* idx) {
	if(arr == NULL)
		return NULL;
	if(arr[*idx] != '#') {
	Node* root = (Node*)malloc(sizeof(Node));
	root->val = arr[*idx];
	(*idx)++;
	root->left = creatNode(arr,idx);
	(*idx)++;
	root->right = creatNode(arr,idx);
	return root;
	}
	return NULL;
}

void inOdd(Node* root) {
	if(root == NULL)
		return ;
	inOdd(root->left);
	printf("%c ",root->val);
	inOdd(root->right);
}


int main() {
	char arr[100] = "abc##de#g##f###";
	int idx = 0;
	Node* root;
	root = creatNode(arr,&idx);
	inOdd(root);
	return 0;
}
