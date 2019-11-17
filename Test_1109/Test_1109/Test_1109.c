#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
#include <stdlib.h>
#include <time.h>

int  meau(void) {
	printf("===========================\n");
	printf("=======1.开始游戏==========\n");
	printf("=======2.退出游戏==========\n");
	printf("===========================\n");
	int flag;
	scanf("%d", &flag);
	return flag;
}
void game() {
	int num; 
	int pronum = rand() % 100 + 1;
	while (1) {
		printf("请输入你的数据:\n");
		scanf("%d", &num);
		if (num < pronum) {
			printf("低了!\n");
		}
		else if (num>pronum) {
			printf("高了!\n");
		}
		else {
			printf("恭喜你,猜中了!\n");
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
			printf("再见!\n");
			break;
		}
		else {
			printf("输入值有误!\n");
			break;
		}
	}
    system ("pause");
    return 0;
}