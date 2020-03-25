#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 1000 
#define ROM_LEN 816

typedef struct people {
	char name[200];
	char sex[10];
	int age;
	char number[100];
	char address[500];
}information;

typedef struct mindan {
	int num ;
	information* everyone;
	int size;
	
}mindan;

//������д���ļ�
void WriteFile(mindan* book) {
	FILE* fp = fopen("test.txt", "w");
	if (fp == NULL) {
		perror("�ļ���ʧ��!\n");
		return;
	}
	for (int i = 0; i < book->size; i++) {
		fwrite(&(book->everyone[i]),sizeof(information),1,fp);
	}
	fclose(fp);
}

void LoadFile(mindan* book) {
	FILE* fp = fopen("test.txt", "r");
	if (fp == NULL) {
		perror("�ļ���ʧ��!\n");
		return;
	}
	information temp = { 0 };
	int n;
	while (1) {
		n = fread(&temp, sizeof(information), 1, fp);
		if (n < 1) {
			break;
		}
		book->everyone[book->size] = temp;
		book->size++;
		if (book->size > book->num) {
			book->num += 20;
			information* newper = (information*)malloc(book->num*sizeof(information));
			memcpy(newper, book->everyone, book->size*sizeof(information));
			free(book->everyone);
		}
	}
		
}

//��ʼ��
void Init(mindan* book) {
	book->size = 0;
	book->num = 20;
	book->everyone = (information*)malloc(book->num*sizeof(information));
	for (int i = 0; i < book->num; i++) {
		strcpy(book->everyone[i].name," ");
		strcpy(book->everyone[i].sex, " ");
		strcpy(book->everyone[i].number, " ");
		strcpy(book->everyone[i].address, " ");
		book->everyone[i].age = 0;
	}
	
}

//��������
int meau() {
	printf("*********tͨѶ¼**********\n");
	printf("0���˳�����\n");
	printf("1�������ϵ����Ϣ\n");
	printf("2��ɾ��ָ����ϵ����Ϣ\n");
	printf("3������ָ����ϵ����Ϣ\n");
	printf("4���޸�ָ����ϵ����Ϣ\n");
	printf("5����ʾ������ϵ����Ϣ\n");
	printf("6�����������ϵ����Ϣ\n");
	printf("7������������������ϵ��\n");
	int chioce;
	scanf("%d",&chioce);
	return chioce;
}

//�����ϵ��
void AddInformation(mindan* book) {
	if (book->size >= MAX_LEN) {
		book->num += 20;
		information* newper = (information*)malloc(book->num*sizeof(information));
		memcpy(newper, book->everyone, book->size*sizeof(information));
		free(book->everyone);
	}
	printf("��������ϵ��������\n");
	information* p_num =&( book->everyone[book->size]);
	scanf("%s", p_num->name);
	printf("��������ϵ���Ա�\n");
	scanf("%s", p_num->sex);
	printf("��������ϵ�˵�ַ��\n");
	scanf("%s", p_num->address);
	printf("��������ϵ�˺��룺\n");
	scanf("%s", p_num->number);
	printf("��������ϵ�����䣺\n");
	scanf("%d",&p_num->age);
	printf("�����ϵ�˳ɹ���\n");
	book->size++;
	
}

//ɾ����ϵ��
void DelInformation(mindan* book) {
	if (book->size == 0) {
		printf("����ϵ�ˣ�\n");
		return;
	}
	printf("��Ҫɾ�������Ϊ");
	int i;
	scanf("%d", &i);
	information* delper = &book->everyone[i];
	if (i >= book->size) {
		printf("����ϵ�ˣ�\n");
		return;
	}
	else {
		strcpy(delper->name, book->everyone[book->size - 1].name);
		strcpy(delper->address, book->everyone[book->size - 1].address);
		strcpy(delper->number, book->everyone[book->size - 1].number);
		strcpy(delper->sex, book->everyone[book->size - 1].sex);
		delper->age = book->everyone[book->size - 1].age;
		book->size--;
		printf("ɾ���ɹ���\n");

	}
}

//������ϵ��
void FindInformation(mindan* book) {
	if (book->size == 0) {
		printf("����ϵ�ˣ�\n");
		return;
	}
	printf("��Ҫ���ҵ���ϵ���ǣ�");
	information per_info;
	int flag = 0;
	scanf("%s", &per_info.name);
	int i;
	for (i = 0; i < book->size; i++) {
		if (strcmp(per_info.name, book->everyone[i].name)==0) {
			printf("-------�Ѳ��ҵ�----------\n");
			printf("������%s\n", book->everyone[i].name);
			printf("�Ա�%s\n", book->everyone[i].sex);
			printf("���䣺%d\n", book->everyone[i].age);
			printf("���룺%s\n", book->everyone[i].number);
			printf("��ַ��%s\n", book->everyone[i].address);
			flag = 1;
		}
		else {
			continue;
		}
	}
	if (flag == 0 && i == book->size) {
		printf("���޴���\n");
	}
}

//�޸���Ϣ
void ReInformation(mindan* book) {
	if (book->size == 0) {
		printf("����ϵ�ˣ�\n");
		return;
	}
	printf("��Ҫ�޸ĵ���ϵ������ǣ�\n");
	int i ;
	scanf("%d", &i);
	information* per_info = &book->everyone[i];
	information pe_info;
	printf("��Ҫ�޸�����Ϊ��*Ϊ���޸ģ���\n");
	scanf("%s", &pe_info.name);
	if (strcmp(pe_info.name, "*") != 0) {
		strcpy(per_info->name, pe_info.name);
	}

	printf("��Ҫ�޸��Ա�Ϊ��*Ϊ���޸ģ���\n");
	scanf("%s", &pe_info.sex);
	if (strcmp(pe_info.sex, "*") != 0) {
		strcpy(per_info->sex, pe_info.sex);
	}
	printf("��Ҫ�޸ĺ���Ϊ��*Ϊ���޸ģ���\n");
	scanf("%s",&pe_info.number);
	if (strcmp(pe_info.number, "*") != 0) {
		strcpy(per_info->number, pe_info.number);
	}
	printf("��Ҫ�޸ĵ�ַΪ��*Ϊ���޸ģ���\n");
	scanf("%s", &pe_info.address);
	if (strcmp(pe_info.address, "*") != 0) {
		strcpy(per_info->address, pe_info.address);
	}
	printf("��Ҫ�޸�����Ϊ��-1Ϊ���޸ģ���\n");
	scanf("%d", &pe_info.age);
	if (pe_info.age != -1) {
		per_info->age = pe_info.age;
	}
	printf("�޸���ɣ�\n");
}

//��ӡ��Ϣ
void PrintInformation(mindan* book) {
	if (book->size == 0) {
		printf("����ϵ�ˣ�\n");
		return;
	}
	for (int i = 0; i < book->size; i++) {
		printf("------[%d]����ϵ��-------\n",i);
		printf("������%s\n", book->everyone[i].name);
		printf("�Ա�%s\n", book->everyone[i].sex);
		printf("���䣺%d\n", book->everyone[i].age);
		printf("���룺%s\n", book->everyone[i].number);
		printf("��ַ��%s\n", book->everyone[i].address);
	}
}

//�����Ϣ
void DisInformation(mindan* book) {
	if (book->size == 0) {
		printf("����ϵ�ˣ�\n");
		return;
	}
	char a[10];
	printf("ȷ���Ƿ����:[Y/N]\n");
	scanf("%s", a);
	if ((strcmp(a, "y") == 0) || (strcmp(a, "Y") == 0)) {
		Init(book);
	}
	else {
		printf("���ʧ�ܣ�\n");
		return;
	}
}

//��ϵ������
void SortInformation(mindan* book) {
	if (book->size == 0) {
		printf("����ϵ�ˣ�\n");
		return;
	}
	information* per = &book->everyone[book->size];
	for (int i = 0; i < book->size; i++) {
		for (int j = 0; j < book->size - i - 1; j++) {
			if (strcmp(book->everyone[j].name, book->everyone[j + 1].name) >= 0) {
				memmove(per, &book->everyone[j + 1],ROM_LEN);
				memmove(&book->everyone[j + 1], &book->everyone[j], ROM_LEN);
				memmove(&book->everyone[j], per, ROM_LEN);
			}
		}
	}
	printf("������ɣ�\n");
}

int main() {
	mindan person_info;
	Init(&person_info);
	LoadFile(&person_info);
	//���庯��ָ��func ����void(*) ��mindan*��
	typedef void(*func)(mindan*);
	func fun_table[] = {
		NULL,
		AddInformation,
		DelInformation,
		FindInformation,
		ReInformation,
		PrintInformation,
		DisInformation,
		SortInformation
	};
	while (1) {
		int choose = meau();
		if (choose < 0||choose > sizeof(fun_table)/sizeof(fun_table[0])) {
			printf("������Ч������������\n");
			continue;
		}
		if (choose == 0) {
			printf("�ټ�\n");
			WriteFile(&person_info);
			break;
		}
		else {
			fun_table[choose](&person_info);
		}
	}
	system("pause");
	return 0;
}