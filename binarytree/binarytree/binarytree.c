#include <stdio.h>
#include <stdlib.h>
typedef char BTDataType;

typedef struct BinaryTreeNode {
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

BTNode* BinaryTreeCreat(BTDataType* a, int* pi) {
	if (a[*pi] != '#') {
		BTNode* root = (BTNode*)malloc(sizeof(BTNode));
		root->_data = a[*pi];
		(*pi)++;
		root->_left = BinaryTreeCreat(a, pi);
		(*pi)++;
		root->_right = BinaryTreeCreat(a, pi);
		return root;
	}
	else {
		return NULL;
	}
}

void BTinoder(BTNode* root) {
	if (root) {
		BTinoder(root->_left);
		printf("%c ", root->_data);
		BTinoder(root->_right);
	}
}

int main() {
	char* a = "BD##E#H##CF##G##";
	int len = 0;
	BTNode* root = BinaryTreeCreat(a, &len);
	BTinoder(root);
	system("pause");
	return 0;
}