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

//将数据写入文件
void WriteFile(mindan* book) {
	FILE* fp = fopen("test.txt", "w");
	if (fp == NULL) {
		perror("文件打开失败!\n");
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
		perror("文件打开失败!\n");
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

//初始化
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

//界面设置
int meau() {
	printf("*********t通讯录**********\n");
	printf("0、退出设置\n");
	printf("1、添加联系人信息\n");
	printf("2、删除指定联系人信息\n");
	printf("3、查找指定联系人信息\n");
	printf("4、修改指定联系人信息\n");
	printf("5、显示所有联系人信息\n");
	printf("6、清空所有联系人信息\n");
	printf("7、以名字排序所有联系人\n");
	int chioce;
	scanf("%d",&chioce);
	return chioce;
}

//添加联系人
void AddInformation(mindan* book) {
	if (book->size >= MAX_LEN) {
		book->num += 20;
		information* newper = (information*)malloc(book->num*sizeof(information));
		memcpy(newper, book->everyone, book->size*sizeof(information));
		free(book->everyone);
	}
	printf("请输入联系人姓名：\n");
	information* p_num =&( book->everyone[book->size]);
	scanf("%s", p_num->name);
	printf("请输入联系人性别：\n");
	scanf("%s", p_num->sex);
	printf("请输入联系人地址：\n");
	scanf("%s", p_num->address);
	printf("请输入联系人号码：\n");
	scanf("%s", p_num->number);
	printf("请输入联系人年龄：\n");
	scanf("%d",&p_num->age);
	printf("添加联系人成功！\n");
	book->size++;
	
}

//删除联系人
void DelInformation(mindan* book) {
	if (book->size == 0) {
		printf("无联系人！\n");
		return;
	}
	printf("你要删除的序号为");
	int i;
	scanf("%d", &i);
	information* delper = &book->everyone[i];
	if (i >= book->size) {
		printf("无联系人！\n");
		return;
	}
	else {
		strcpy(delper->name, book->everyone[book->size - 1].name);
		strcpy(delper->address, book->everyone[book->size - 1].address);
		strcpy(delper->number, book->everyone[book->size - 1].number);
		strcpy(delper->sex, book->everyone[book->size - 1].sex);
		delper->age = book->everyone[book->size - 1].age;
		book->size--;
		printf("删除成功！\n");

	}
}

//查找联系人
void FindInformation(mindan* book) {
	if (book->size == 0) {
		printf("无联系人！\n");
		return;
	}
	printf("你要查找到联系人是：");
	information per_info;
	int flag = 0;
	scanf("%s", &per_info.name);
	int i;
	for (i = 0; i < book->size; i++) {
		if (strcmp(per_info.name, book->everyone[i].name)==0) {
			printf("-------已查找到----------\n");
			printf("姓名：%s\n", book->everyone[i].name);
			printf("性别：%s\n", book->everyone[i].sex);
			printf("年龄：%d\n", book->everyone[i].age);
			printf("号码：%s\n", book->everyone[i].number);
			printf("地址：%s\n", book->everyone[i].address);
			flag = 1;
		}
		else {
			continue;
		}
	}
	if (flag == 0 && i == book->size) {
		printf("查无此人\n");
	}
}

//修改信息
void ReInformation(mindan* book) {
	if (book->size == 0) {
		printf("无联系人！\n");
		return;
	}
	printf("你要修改的联系人序号是：\n");
	int i ;
	scanf("%d", &i);
	information* per_info = &book->everyone[i];
	information pe_info;
	printf("你要修改姓名为（*为不修改）：\n");
	scanf("%s", &pe_info.name);
	if (strcmp(pe_info.name, "*") != 0) {
		strcpy(per_info->name, pe_info.name);
	}

	printf("你要修改性别为（*为不修改）：\n");
	scanf("%s", &pe_info.sex);
	if (strcmp(pe_info.sex, "*") != 0) {
		strcpy(per_info->sex, pe_info.sex);
	}
	printf("你要修改号码为（*为不修改）：\n");
	scanf("%s",&pe_info.number);
	if (strcmp(pe_info.number, "*") != 0) {
		strcpy(per_info->number, pe_info.number);
	}
	printf("你要修改地址为（*为不修改）：\n");
	scanf("%s", &pe_info.address);
	if (strcmp(pe_info.address, "*") != 0) {
		strcpy(per_info->address, pe_info.address);
	}
	printf("你要修改年龄为（-1为不修改）：\n");
	scanf("%d", &pe_info.age);
	if (pe_info.age != -1) {
		per_info->age = pe_info.age;
	}
	printf("修改完成！\n");
}

//打印信息
void PrintInformation(mindan* book) {
	if (book->size == 0) {
		printf("无联系人！\n");
		return;
	}
	for (int i = 0; i < book->size; i++) {
		printf("------[%d]号联系人-------\n",i);
		printf("姓名：%s\n", book->everyone[i].name);
		printf("性别：%s\n", book->everyone[i].sex);
		printf("年龄：%d\n", book->everyone[i].age);
		printf("号码：%s\n", book->everyone[i].number);
		printf("地址：%s\n", book->everyone[i].address);
	}
}

//清空信息
void DisInformation(mindan* book) {
	if (book->size == 0) {
		printf("无联系人！\n");
		return;
	}
	char a[10];
	printf("确定是否清空:[Y/N]\n");
	scanf("%s", a);
	if ((strcmp(a, "y") == 0) || (strcmp(a, "Y") == 0)) {
		Init(book);
	}
	else {
		printf("清空失败！\n");
		return;
	}
}

//联系人排序
void SortInformation(mindan* book) {
	if (book->size == 0) {
		printf("无联系人！\n");
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
	printf("排序完成！\n");
}

int main() {
	mindan person_info;
	Init(&person_info);
	LoadFile(&person_info);
	//定义函数指针func 代表void(*) （mindan*）
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
			printf("输入无效，请重新输入\n");
			continue;
		}
		if (choose == 0) {
			printf("再见\n");
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