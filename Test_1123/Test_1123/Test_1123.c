#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_ROW 3
#define MAX_COL 3

void Meau() {
	printf("======================\n");
	printf("��ӭ������������Ϸ����ѡ��\n");
	printf("1����ʼ��Ϸ\n");
	printf("2���˳���Ϸ\n");
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
		printf("��������������row,col��\n");
		scanf("%d %d", &row, &col);
		if (row < 0 || col < 0 || row > 2 || col > 2)
		{
			printf("�������������!\n");
		}
		else if (chessSite[row][col]!=' '){
			printf("��ǰλ�����¹�,���������ӣ�\n");
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

//���Ƿ�������
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
	//Ѱ����һ��
	for (int row = 0; row < MAX_ROW; row++) {
		if (chessSite[row][0] == chessSite[row][1] && chessSite[row][0] == chessSite[row][2] && chessSite[row][0] != ' ') {
			return chessSite[row][0];
		}
	}

	//Ѱ����һ��
	for (int col = 0; col < MAX_COL; col++) {
		if (chessSite[0][col] == chessSite[1][col] && chessSite[0][col] == chessSite[2][col] && chessSite[0][col] != ' ') {
			return chessSite[0][col];
		}
	}
	//Ѱ�ҶԽ���һ��
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
		printf("������!\n");
		return 1;
	}
	else if (result == 'x') {
		printf("��Ӯ��!\n");
		return 1;
	}
	else if (result == 'q'){
		printf("ƽ����!\n");
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
	
	//��ʼ������
 	InitBoard(chessSite);
	//��ӡ����
	PrintChessBoard(chessSite);
	while (1) {
	//�������
	PlayerUse(chessSite);
	//��ӡ����
	printf("��ǰ���Ϊ��\n");
	PrintChessBoard(chessSite);
	//�ж���Ϸ�Ƿ����
	result = CheckAnswer(chessSite);
	winner = Winner(result);
	if (winner == 1) {
		PrintChessBoard(chessSite);
		break;
	}
	
	//��������
	ComputerUse(chessSite);
	printf("��ǰ���Ϊ��\n");
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
		printf("С���ѣ��ټ���\n");
	}
    system ("pause");
    return 0;
}