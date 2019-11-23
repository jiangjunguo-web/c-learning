#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ROW 3
#define MAX_COL 3

void Meau() {
	printf("======================\n");
	printf("欢迎来到三子棋游戏，请选择：\n");
	printf("1、开始游戏\n");
	printf("2、退出游戏\n");
	printf("======================\n");

}

void PrintChessBoard(int chessSite[MAX_ROW][MAX_COL]) {
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++) {
		printf("|");
		for (int col = 0; col < MAX_COL; col++) {
		printf(" %c |", chessSite[row][col]);
		}
		printf("\n");
		printf("+---+---+---+\n");
	}
	printf("\n");
}

void InitBoard(int chessSite[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			chessSite[row][col] = ' ';
		}
	}
}

void PlayerUse(int chessSite[MAX_ROW][MAX_COL]) {
	int row = 0;
	int col = 0;
	while(1) {
		printf("请输入您的坐标row,col：\n");
		scanf("%d %d", &row, &col);
		if (row < 0 || col < 0 || row > 2 || col > 2)
		{
			printf("输入错误，请重试!\n");
		}
		else if (chessSite[row][col]!=' '){
			printf("当前位置已下过,请重新落子！\n");
		}
		else {
			break;
		}
	}
	chessSite[row][col] = 'x';
}

void ComputerUse(int chessSite[MAX_ROW][MAX_COL]) {
	
	while (1) {
		int row = rand() % 3;
		int col = rand() % 3;
		if (chessSite[row][col] != ' '){
			continue;
		}
		else {
			chessSite[row][col] = 'o';
			break;
		}

	}


}

//看是否棋盘满
int IsFull(int chessSite[MAX_ROW][MAX_COL]) {
	int row; int col;
	for (row = 0; row < MAX_ROW; row++) {
		for (col = 0; col < MAX_COL; col++) {
			if (chessSite[row][col] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

char CheckAnswer(int chessSite[MAX_ROW][MAX_COL]) {
	//寻找行一致
	for (int row = 0; row < MAX_ROW; row++) {
		if (chessSite[row][0] == chessSite[row][1] && chessSite[row][0] == chessSite[row][2] && chessSite[row][0] != ' ') {
			return chessSite[row][0];
		}
	}

	//寻找列一致
	for (int col = 0; col < MAX_COL; col++) {
		if (chessSite[0][col] == chessSite[1][col] && chessSite[0][col] == chessSite[2][col] && chessSite[0][col] != ' ') {
			return chessSite[0][col];
		}
	}
	//寻找对角线一致
	if ((chessSite[0][0] == chessSite[1][1] && chessSite[0][0] == chessSite[2][2] && chessSite[0][0] != ' ')
		|| (chessSite[2][0] == chessSite[1][1] && chessSite[0][2] == chessSite[1][1] && chessSite[1][1] != ' ')) {
		return chessSite[1][1];
	}
	if (IsFull(chessSite)) {
		return 'q';
	}
	
	return ' ';
	
}

int Winner(char  result) {
	if (result == 'o') {
		printf("你输了!\n");
		return 1;
	}
	else if (result == 'x') {
		printf("你赢了!\n");
		return 1;
	}
	else if (result == 'q'){
		printf("平局了!\n");
		return 1;
	}
	else {
		return 2;
	}
}

void  Game() {
	int chessSite[MAX_ROW][MAX_COL];
	char  result =' ';
	int winner = 0;
	
	//初始化棋盘
 	InitBoard(chessSite);
	//打印棋盘
	PrintChessBoard(chessSite);
	while (1) {
	//玩家落子
	PlayerUse(chessSite);
	//打印棋盘
	printf("当前棋局为：\n");
	PrintChessBoard(chessSite);
	//判断游戏是否结束
	result = CheckAnswer(chessSite);
	winner = Winner(result);
	if (winner == 1) {
		PrintChessBoard(chessSite);
		break;
	}
	
	//电脑落子
	ComputerUse(chessSite);
	printf("当前棋局为：\n");
	PrintChessBoard(chessSite);
	result = CheckAnswer(chessSite);
	winner = Winner(result);
	if (winner == 1) {
	PrintChessBoard(chessSite);
	break;
	}
	}
	
}


int main() {
	srand((unsigned int)time(0));
	Meau();
	int chioce;
	scanf("%d",&chioce);
	if (chioce == 1) {
		Game();
	}
	else {
		printf("小朋友，再见！\n");
	}
    system ("pause");
    return 0;
}