#define _CRT_SECURE_NO_WARNINGS
#include  <stdio.h>
#include <stdlib.h>
#include <time.h>


//��������Ϸ
void Meau() {
	printf("==========================\n");
	printf("��ӭ������������Ϸ����ѡ��:\n");
	printf("1����ʼ��Ϸ\n");
	printf("2���˳���Ϸ\n");
	printf("3������\n");
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
	printf("��ϲ��¶��ˣ���%dA%dB\n",countA,countB);
	return 1;
	}
	else {
		printf("�𰸴��󣡣�%dA%dB\n", countA, countB);
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
			printf("��������µô𰸣�\n");
			for (j = 1; j <= 6; j++) {
				printf("��%d�Σ�\n", j);
				for (int i = 0; i < 4; i++)
				{
					scanf("%d", &yourAnswer[i]);

				}
				if (JudgeAnswer(answer, yourAnswer)) {
					break;
				}
			}
			if (j>6) {
			printf("���Ѿ������6�Σ���ȷ��Ϊ��\n");
			for (int i = 0; i < 4; i++) {
				printf("%d ", answer[i]);
			}
			printf("\n");
			}
			
			break;
		}
		else if (choice == 2) {
			printf("С����������ѽ��\n");
			break;
		}
		else if (choice == 3){
			printf("���Ϊ0A2B�������е���������\n");
			printf("��λ�þ�����\n");
			printf("���Ϊ2A0B�������е���������\n");
			printf("λ�ú����־���ȷ\n"); 
			printf("����Ŷ��\n");
		}
		else{
			printf("�������������ԣ�\n");
		}
	}
    system ("pause");
    return 0;
}