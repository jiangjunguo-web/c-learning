#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
#include <stdlib.h>
#include <time.h>

int  meau(void) {
	printf("===========================\n");
	printf("=======1.��ʼ��Ϸ==========\n");
	printf("=======2.�˳���Ϸ==========\n");
	printf("===========================\n");
	int flag;
	scanf("%d", &flag);
	return flag;
}
void game() {
	int num; 
	int pronum = rand() % 100 + 1;
	while (1) {
		printf("�������������:\n");
		scanf("%d", &num);
		if (num < pronum) {
			printf("����!\n");
		}
		else if (num>pronum) {
			printf("����!\n");
		}
		else {
			printf("��ϲ��,������!\n");
			break;
		}
	}	
}
int main() {
	srand((unsigned int)time(0));
	while (1) {
		int chioce = meau();
		if (chioce == 1) {
			game();
		}
		else if(chioce==2) {
			printf("�ټ�!\n");
			break;
		}
		else {
			printf("����ֵ����!\n");
			break;
		}
	}
    system ("pause");
    return 0;
}