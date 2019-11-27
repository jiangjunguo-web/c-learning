#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
#include <stdlib.h>
#include <time.h>


//猜数字游戏
void Meau() {
	printf("==========================\n");
	printf("欢迎来到猜数字游戏，请选择:\n");
	printf("1、开始游戏\n");
	printf("2、退出游戏\n");
	printf("3、帮助\n");
	printf("==========================\n");
}

void Answer(int answer[]) {
	int poor[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int s; 
	for (int i = 0; i < 4; i++) {
		s= rand() % 10;
		while (poor[s] == -1) {
			s++;	
			if (s == 10) {
				s = 0;
			}
		
		}
		answer[i] = poor[s];
		poor[s] = -1;
	}
}

int JudgeAnswer(int answer[4], int yourAnswer[4]) {
	int i, j;
	int countA = 0;
	int countB = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++) {
			if (answer[i] == yourAnswer[j]) {
				countB++;
				if (i == j) {
					countA++;
					countB--;
				}
				break;
			}

		}
	}

	if (countA == 4) {
	printf("恭喜你猜对了！：%dA%dB\n",countA,countB);
	return 1;
	}
	else {
		printf("答案错误！：%dA%dB\n", countA, countB);
		return 0;
	}

}


int main() {
	while (1){
		Meau();
		int choice ;
		scanf("%d", &choice);
		if (choice == 1){
			srand((unsigned int)time(NULL));
			int answer[4];
			int yourAnswer[4];
			int j;
			Answer(answer);
			printf("请输入你猜得答案：\n");
			for (j = 1; j <= 6; j++) {
				printf("第%d次：\n", j);
				for (int i = 0; i < 4; i++)
				{
					scanf("%d", &yourAnswer[i]);

				}
				if (JudgeAnswer(answer, yourAnswer)) {
					break;
				}
			}
			if (j>6) {
			printf("你已经输错了6次！正确答案为：\n");
			for (int i = 0; i < 4; i++) {
				printf("%d ", answer[i]);
			}
			printf("\n");
			}
			
			break;
		}
		else if (choice == 2) {
			printf("小朋友再来玩呀！\n");
			break;
		}
		else if (choice == 3){
			printf("结果为0A2B则代表猜中的两个数字\n");
			printf("但位置均不对\n");
			printf("结果为2A0B则代表猜中的两个数字\n");
			printf("位置和数字均正确\n"); 
			printf("加油哦！\n");
		}
		else{
			printf("输入有误请重试！\n");
		}
	}
    system ("pause");
    return 0;
}