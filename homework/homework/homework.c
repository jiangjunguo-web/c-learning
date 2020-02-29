#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define str1len  5
#define str2len  5
#define namelen  3
#define str_len  8

//接收字符串将小写转大写
void ToLoseCase(char str[]) {
	for (int i = 0; str[i]; i++) {
		if (str[i] >= 'A'&&str[i] <= 'Z') {
			str[i] += 32;
		}
	}
}

//给定一个数组将数组的元素向右移动K位
void MoveElement(char str[], int n) {
	char temp[10] = {0};
	for (int i = 0; i < 10; i++) {
		temp[i] = str[i];
	}
	for (int j = 0; j < n; j++) {
		str[j] = '0';
	}
	for (int k = n; k < 10; k++) {
		str[k] = temp[k - n];
	}	
}

void DeleArray(int str[], int val) {
	int n = 0;
	for (int i = 0; i < 10; i++) {
		if (str[i] == val) {
			n++;
			for (int j = i; j < 9; j++) {
				str[j] = str[j+1];
			}
			i--;
		}
	}
	for (; n>0; n--) {
		str[9 - n] = '\0';
	}

}

//数组查找
void ArrayFind(int str[], int val) {
	int flag = 0;
	for (int i = 0; i < 8; i++) {
		if (str[i] == val) {
			printf("待查找元素的下标为%d\n",i);
			break;
		}
		if (i == 7) {
			flag = 1;
		}
	}
	if (flag == 1) {
		if (val>str[7]) {
			str[8] = val;
		}
		else {
			for (int i = 0; i < 8; i++) {
				if (str[i]>val) {
					for (int j = 8; j > i; j--) {
						str[j] = str[j - 1];
					}
					str[i] = val;
					break;
				}
			}
		}
	}
}

//赎金信（理解：字符串包含字符串）
int canConstruct(char str[], char arr[]) {
	int flag = 0;
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 3; j++) {
			if (str[j] != arr[i]) {
				i = i - j;
				break;
			}
			i++;
			if (j == 2) {
				flag = 1;
			}
		}
	}
	return flag;
}

//回文数
int IsPalindromic(int num) {
	int flag = 0;
	int temp;
	int str[100];
	int i;
	for (i= 0; num > 0; num=num / 10,i++) {
		temp = num % 10;
		str[i] = temp;
	}
	int right = i - 1;
	int left = 0;
	while (left<right) {
		if (str[right] == str[left]) {
			right--;
			left++;
		}
		else {
			break;
		}
	}
	if (left >= right) {
		flag = 1;
	}
	return flag;
}

//最后一个单词的长度
int LengthOfLastWord(char str[]) {
	int count = 0;
	int flag = 0;
	for (int i = 0; str[i]; i++) {
		if (flag == 1) {
			count++;
		}
		if (str[i] == ' ') {
			flag = 1;
			count = 0;
		}
	}
	return count;
}

//将两个有序数组合并产生一个有序数组
//解法一：
void merge1(int str1[], int str2[]) {
	for (int k = 0; k < str1len; k++) {
		str1[str1len + k] = str2[k];
	}
	int temp;
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10 - 1; j++) {
			if (str1[j]>str1[j + 1]) {
				temp = str1[j + 1];
				str1[j + 1] = str1[j];
				str1[j] = temp;
			}
		}
	}
	for (int x = 0; x < 10; x++) {
		printf("%d", str1[x]);
	}
}
//解法二：
void merge2(int str1[], int str2[]) {
	int i = 0;
	int j = 0;
	for (; i < str2len; i++) {
		if (str2[i]>str1[str1len + i - 1]) {
			str1[str1len + i] = str2[i];
		}
		else{
			for (; j < str1len + str2len; j++) {
				if (str1[j]>=str2[i]) {
					for (int k = str1len + str2len; k > j; k--) {
						str1[k] = str1[k - 1];
					}
					str1[j] = str2[i];
					break;
				}
			}
		}
	}
	for (int x = 0; x < str1len + str2len; x++) {
		printf("%d", str1[x]);
	}
}

//选择题
int func1(int a) {
	int b;
	switch (a) {
	case 1:b = 30;
	case 2:b = 20;
	case 3:b = 16;
	default:b = 0;
	}
	return b;
}

//判断一个整数数组中是否有重复的数字
int ContainsDuplicates(int str[],int len) {
	int count = 0;
	int flag = 0;
	for (int i = 0; i < len; i++) {
		for (int j = 1; j < len; j++) {
			if (str[i] == str[j]) {
				count++;
			}
		}
		if (count >= 1) {
			flag = 1;
			break;
		}
	}
	return flag;
}

int IsLongPressName(char name[], char str[]) {
	int j = 1;
	int flag = 0;
	char tem[10] ;
	for (int i = 0; i < str_len - 1; i++) {
			tem[0] = str[0];
			if (str[i] != str[i + 1]) {
				tem[j] = str[i+1];
				j++;
			}
		}
		int k = 0;
		for (; k < namelen; k++) {
			if (tem[k] != name[k]) {
				break;
			}
		}
		if (k ==namelen) {
			flag = 1;
		}
		return flag;
}

//给数组的平方排序
void SortedSqares(int str[],int len) {
	int temp;
	for (int i = 0; i < len; i++) {
		str[i] = str[i] * str[i];
	}
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - 1; j++) {
			if (str[j]>=str[j + 1]) {
				temp = str[j + 1];
				str[j + 1] = str[j];
				str[j] = temp;
			}
		}
	}
}

//反转一个字符串中的所有字母
void ReverseOnlyLetters(char str[], int len) {
	char temp[10] ;
	int temp1[10];
	int j = 0;
	for (int i = 0; i < len; i++) {
		if (str[i]) {
			if (str[i]<'A' || str[i]>'z' || (str[i]>'Z'&&str[i] < 'a')) {
				temp[j] = str[i];
				temp1[j] = i+j;
				j++;
				for (int k = i; k<len; k++) {
					str[k] = str[k + 1];
				}
			}
		}
	}
	int left = 0;
	int right = len - j - 1;
	char tem;
	while (left < right) {
		tem = str[left];
		str[left] = str[right];
		str[right] = tem;
		left++;
		right--;
	}

	for (int i = 0; i < j; i++) {
		for (int k = 0; k < len; k++) {
			if (temp1[i] == k) {
				for (int q = len; q>=k; q--) {
					str[q] = str[q - 1];
				}
				str[k] = temp[i];
			}
		}
	}
}

float func2(float a, int b)
{
	float m = 1, n = 1;
	int i;
	for (i = 1; i < b; i++)
	{
		m *= a / i;
		n += m;
	}
	return n;
}

//将数组元素，奇数在前偶数在后进行排序
void SortArray(int str[],int len) {
	int arr[10];
	int j = 0;
	for (int i = 0; i < len-j; i++) {
		if (str[i] % 2 == 0) {
			arr[j] = str[i];
			j++;
			for (int k = i; k < len - j ; k++) {
				str[k] = str[k + 1];
			}
			i--;
		}
	}
	
	for (int k=0,i=len-j; k < j; k++,i++) {
		str[i] = arr[k];
	}
}

//数组中心索引查找
int PivotIndex(int str[],int len) {

	for (int i = 1; i < len-1; i++) {
		int leftsum = 0;
		int rightsum = 0;
		for (int j = 0; j < i; j++) {
			leftsum += str[j];
		}
		for (int k = i + 1; k < len; k++) {
			rightsum += str[k];
		}
		if (rightsum == leftsum) {
			return str[i];
			break;
		}

	}
	return -1;
}

//数组加一
void PlusOne(int str[], int len) {
	int temp = 0; //进位计数
	int i = len - 1;
	for (; i > 0; i--) {
		if (str[i] != 9&&i==len-1) {
			str[len - 1] += 1;
			break;
		}
		else{
			if (str[i] == 9){
				str[i] = 0;
				temp = 1;
				if (str[i - 1] != 9) {
					temp = 0;
					str[i - 1] += 1;
					break;
				}
			}
		}	
	}
	if (i == 0) {
		if (str[0] == 9&&temp == 1) {
			int tem[7];
			str[0] = 0;
			for (int j = len; j > 0; j--) {
				tem[j] = str[j - 1];
			}
			tem[0] = 1;
			for (int k = 0; k <= len; k++) {
				printf("%d", tem[k]);
			}
		}	
	}
	else {
		for (int k = 0; k < len; k++) {
			printf("%d", str[k]);
		}
	}
	
}

//找数组中第三大的数
int ThirdMax(int str[],int len) {
	int temp;
	int count = 0;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - i-1 ; j++) {
			if (str[j] < str[j + 1]) {
				temp = str[j+1];
				str[j + 1] = str[j];
				str[j] = temp;
			}
		}
	}
	for (int i = 0; i < len-count; i++) {
		if (str[i] == str[i + 1]) {
			for (int j = i; j < len-1; j++) {
				str[j] = str[j + 1];
			}
			count++;
			i--;
			str[len - 1] = 0;
		}
	}
	if (str[2]==0) {
		return str[0];
	}
	else {
		return str[2];
	}
}

int f(int n)
{
	if (n) return f(n - 1) + n;
	else return n;
}

//找和为目标数的两个元素的下标
void TwoSum(int str[], int sum, int len) {
	int numarray[100];
	int k = 0;
	int count = 0;
	for (int i = 0; i < len; i++) {
		for (int j = i+1; j < len; j++) {
			if (str[i] + str[j] == sum) {
				numarray[k] = i;
				k++;
				numarray[k] = j;
				k++;
			}
		}
	}
	for (int i = 0; i < len; i++) {
		count++;
		if (numarray[i] < len&&numarray[i] >= 0){
			printf("%d ", numarray[i]);
			if (count % 2 == 0) { 
				printf("\n");
			}
		}
	}
}

//输入两个二进制数求和为二进制输出
void AddBinary(char str1[], char str2[]) {
	int temp = 0;
	char sum[10]={0};
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len = (len1 < len2) ? len1 : len2;
	for (int i = 0; i < len; i++) {
		if (str1[i] + str2[i] - 0x60 + temp >= 2) {
			sum[i] = (str1[i] + str2[i] - 0x60 + temp) % 2;
			temp = 1;
		}
		else {
			sum[i] = (str1[i] + str2[i] - 0x60 + temp);
			temp = 0;
		}
	}
	if (len == len1) {
		for (int i = len1; i < len2; i++) {
			if (str2[i] - 0x30 + temp >= 2) {
				sum[i] = (str2[i] - 0x30 + temp) % 2;
				temp = 1;
			}
			else {
				sum[i] = (str2[i] - 0x30 + temp);
				temp = 0;
			}
		}
		if (temp == 1) {
			sum[len2] = 1;
			temp = 0;
		}

	}
	else {
		for (int i = len2; i < len1; i++) {
			if (str1[i] - 0x30 + temp >= 2) {
				sum[i] = (str1[i] - 0x30 + temp) % 2;
				temp = 1;
			}
			else {
				sum[i] = (str1[i] - 0x30 + temp);
				temp = 0;
			}
		}
		if (temp == 1) {
			sum[len1] = 1;
			temp = 0;
		}
	}
	for (int j = 0; j < 10; j++) {
		printf("%d",sum[j]);
	}
}

//字符串转换整数
int myAtoi(char* str) {

	int len = strlen(str);
	if (len == 0){
		return 0;
	}
	int i = 0;
	while (str[i] == ' '){
		i++;
	}

	if (str[i] != '+'&&str[i] != '-'&&str[i]<'0'&&str[i]>'9'){
		return 0;
	}

	double *a = (double *)malloc(sizeof(double)*(len));
	double sum = 0;
	int flag = 1;
	if (str[i] == '+'){//正数
		i++;
	}
	else if (str[i] == '-'){//负数
		i++;
		flag = -1;
	}

	int k = 0;
	while (str[i] >= '0'&&str[i] <= '9'){
		*a = str[i] - '0';
		sum = sum * 10 + (*a);
		a++;
		i++;
	}

	if (flag == -1){
		sum = sum*(-1);
	}

	if (sum<INT_MIN){
		return INT_MIN;
	}
	else if (sum>INT_MAX){
		return INT_MAX;
	}
	else{
		return (int)sum;
	}

}

//数组寻找目标值 
void SearchRange(int str[], int len,int num) {
	int left = -1;
	int right = -1;
	int flag = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == num&&flag==0) {
			left = i;
			flag = 1;
		}
		if (str[i] != num&&flag == 1) {
			right = i - 1;
			flag = 0;
			break;
		}
	}
	printf("[%d,%d]",left,right);
}

//回文串判断
int Ishuiwen(char str[], int len) {
	int left = 0;
	int right = len-1;
	while (right > left) {
		if (str[left] == str[right] || str[left] == str[right] + 32 || str[left] == str[right] - 32) {
			left++;
			right--;
		}
		else {
			break;
		}
	}
	if (right <= left) {
		return 1;
	}
	else {
		return 0;
	}
}

//原地压缩
int Compress(char str[],int len) {
	int count = 1;
	char comstr[10];
	int j = 0;
	int i = 1;
	comstr[j] = str[0];
	for (; i < len; i++) {
		if (str[i] == str[i - 1]) {
			count++;
		}
		else {
			if (count == 1) {
				j++;
				comstr[j] = str[i];
			}
			else {
				j++;
				comstr[j] = count+0X30;
				count = 1;
				j++;
				comstr[j] = str[i];
			}
		}
	}
	if (i == len) {
		j++;
		comstr[j] = count + 0X30;
		count = 1;
		j++;
		comstr[j] = str[i];
	}	
	for (int k = 0; k < j; k++) {
		printf("%c", comstr[k]);
	}
	return j;
}

int func12(int i, int j)
{
	if (i <= 0 || j <= 0)
		return 1;
	return 2 * func12(i - 3, j / 2);
}

int FindUnsortSubarray(int str[],int len) {
	int count = 0;
	int left = 0;
	int right = 0;
	for (int i = 0; i < len-1; i++) {
		int j = i + 1;
		for (; j < len; j++) {
			if (str[i] <= str[j]) {
				continue;
			}
			else {
				left = i;
				break;
			}
		}
		if (j != len) {
			break;
		}
	}
	for (int i = len - 1; i > 0; i--) {
		int k = i - 1;
		for (; k >= 0; k--) {
			if (str[i] >= str[k]) {
				continue;
			}
			else {
				right = i;
				break;
			}
		}
		if (k >= 0) {
			break;
		}
	}
	count = right - left + 1;
	return count;
}

int EvalRPN(char str[], int len) {
	int endnum = 0;
	int count = 0;
	for (int i = 0; i < len; i++) {
		if (str[i]>'0'&&str[i] < '9') {
			continue;
		}
		if (str[i] == '+') {
			endnum = str[i - 1] + str[i - 2] - 96;
			str[i - 2] = endnum+0x30;
			for (int k = 0; k <= i-2; k++) {
				str[k+2] = str[k];
			}
		}
		if (str[i] == '-') {
			endnum = str[i - 2] - str[i - 1] - 96;
			str[i - 2] = endnum + 0x30;
			for (int k = 0; k <= i - 2; k++) {
				str[k + 2] = str[k];
			}
		}
		if (str[i] == '*') {
			endnum = (str[i - 1] - 0x30) * (str[i - 2]-0x30);
			str[i - 2] = endnum + 0x30;
			for (int k = 0; k <= i - 2; k++) {
				str[k + 2] = str[k];
			}
		}
		if (str[i] == '/') {
			endnum = (str[i - 2] - 0x30) / (str[i - 1] - 0x30);
			str[i - 2] = endnum + 0x30;
			for (int k = 0; k <= i - 2; k++) {
				str[k + 2] = str[k];
			}
		}
	}
	return endnum;
}

//数组子集
int count(int num, int k) {
	int i = 0, count = 0;
	for (i = 0; i < k; i++) {
		if (num & 1)
			count++;
		num >>= 1;
	}
	return count;
}
//int** subsets(int* nums, int numsSize, int** columnSizes, int* returnSize) {
//	int size = 1, i = 0, j = 0, k = 0;
//	int t = pow(2, numsSize);
//	*returnSize = t;
//	int** result = (int**)malloc(t * sizeof(int*));
//	columnSizes[0] = (int*)malloc(t * sizeof(int));
//	for (i = 0; i <= t; i++) {
//		columnSizes[0][i] = count(i, numsSize);
//		result[i] = (int*)malloc(columnSizes[0][i] * sizeof(int));
//		k = i;
//		size = 0;
//		for (j = 0; j < numsSize; j++) {
//			if (k & 1)
//				result[i][size++] = nums[j];
//			k >>= 1;
//		}
//	}
//
//	return result;
//}

//排序函数
int paixu(int a, int b, int c, int d, int e) {
	int temp[5] = { a, b, c, d, e };
	int x = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5 - i-1; j++) {
			if (temp[j] >= temp[j + 1]) {
				x = temp[j];
				temp[j] = temp[j + 1];
				temp[j + 1] = x;
			}
		}
	}
	int k = 0;
	for (; k < 5; k++) {
		if (temp[k] <= a) {
			continue;
		}
		else {
			return temp[k];	
		}
	}
	if (k == 5) {
		return -1;
	}
}

//查找函数 
int FindPath(int* str,int row,int col,int rowlen,int collen) {
	int count = 1;
	int flag = 1;
	while (flag) {
		if (row == 0) {
			//[0][0]点
			if (col == 0) {
				int temp=paixu(*str+row*3+col,*str+row*3+col+1,*str+(row+1)*3+col,0,0);
				if (temp == *str+row*3+col+1) {
					count++;
					col = col + 1;
				}
				else if (temp == *str+(row+1)*3+col) {
					count++;
					row = row + 1;
				}
				else if (temp == -1) {
					flag = 0;
				}
			} 
			//[0][collen]
			else if (col == collen) {
				int temp = paixu(*str+row*3+col, *str+row*3+col-1, *str+(row+1)*3+col, 0, 0);
				if (temp == *str+row*3+col-1) {
					count++;
					col = col - 1;
				}
				else if (temp == *str + (row + 1) * 3 + col) {
					count++;
					row = row + 1;
				}
				else if (temp == -1) {
					flag = 0;
				}
			}
			//第一行其他点
			else {
				int temp = paixu(*str + row * 3 + col, *str + row * 3 + col - 1, *str + (row + 1) * 3 + col, *str + row * 3 + col + 1, 0);
				if (temp == *str + row * 3 + col - 1) {
					count++;
					col = col - 1;
				}
				else if (temp == *str + (row + 1) * 3 + col) {
					count++;
					row = row + 1;
				}
				else if (temp == *str + row * 3 + col + 1) {
					count++;
					col = col + 1;
				}
				else if (temp == -1) {
					flag = 0;
				}
			}
		}
		else if(col==0){
			//[rowlen][0]点
			if (row == rowlen) {
				int temp = paixu(*str + row * 3 + col, *str + row * 3 + col + 1, *str + (row-1) * 3 + col, 0, 0);
				if (temp == *str + row * 3 + col + 1) {
					count++;
					col = col + 1;
				}
				else if (temp == *str + (row - 1) * 3 + col) {
					count++;
					row = row - 1;
				}
				else if (temp == -1) {
					flag = 0;
				}
			}
			//第一列其他点
			else {
				int temp = paixu(*str + row * 3 + col, *str + row * 3 + col + 1, *str + (row - 1) * 3 + col, *str + (row + 1) * 3 + col, 0);
				if (temp == *str + row * 3 + col+1) {
					count++;
					col = col + 1;
				}
				else if (temp == *str + (row - 1) * 3 + col) {
					count++;
					row = row - 1;
				}
				else if (temp == *str + (row + 1) * 3 + col) {
					count++;
					row = row + 1;
				}
				else if (temp == -1) {
					flag = 0;
				}
			}
		}
		else if (row == rowlen) {
		//[rowlen][collen]点
			if (col == collen) {
				int temp = paixu(*str + row * 3 + col, *str + row * 3 + col - 1, *str + (row-1) * 3 + col, 0, 0);
				if (temp == *str + row * 3 + col - 1) {
					count++;
					col = col - 1;
				}
				else if (temp == *str + (row - 1) * 3 + col) {
					count++;
					row = row - 1;
				}
				else if (temp == -1) {
					flag = 0;
				}
			}
		//最后一行其他点
			else {
				int temp = paixu(*str + row * 3 + col, *str + row * 3 + col - 1, *str + (row - 1) * 3 + col, *str + row * 3 + col + 1, 0);
				if (temp == *str + row * 3 + col - 1) {
					count++;
					col = col - 1;
				}
				else if (temp == *str + (row - 1) * 3 + col) {
					count++;
					row = row - 1;
				}
				else if (temp == *str + row * 3 + col + 1) {
					count++;
					col = col + 1;
				}
				else if (temp == -1) {
					flag = 0;
				}
			}
		}
		else if (col == collen) {
		//最后一列的点
			int temp = paixu(*str + row * 3 + col, *str + (row + 1) * 3 + col, *str + (row - 1) * 3 + col, *str + row * 3 + col - 1, 0);
			if (temp == *str + (row + 1) * 3 + col) {
				count++;
				row = row + 1;
			}
			else if (temp == *str + (row - 1) * 3 + col) {
				count++;
				row = row - 1;
			}
			else if (temp == *str + row * 3 + col - 1) {
				count++;
				col = col - 1;
			}
			else if (temp == -1) {
				flag = 0;
			}
		}
		else {
		//不在边缘的点
			int temp = paixu(*str + row * 3 + col, *str + (row + 1) * 3 + col, *str + (row - 1) * 3 + col, *str + row * 3 + col - 1, *str + row * 3 + col + 1);
			if (temp == *str + (row + 1) * 3 + col) {
				count++;
				row = row + 1;
			}
			else if (temp == *str + (row - 1) * 3 + col) {
				count++;
				row = row - 1;
			}
			else if (temp == *str + row * 3 + col - 1) {
				count++;
				col = col - 1;
			}
			else if (temp == *str + row * 3 + col + 1) {
				count++;
				col = col + 1;
			}
			else if (temp == -1) {
				flag = 0;
			}
		}
	}
	return count;
}

//最大递增路径长度
int longestIncreasingPath(int* str,int rowlen,int collen) {
	int lentharr[9] = {0};
	int x = 0;
	int i = 0;
	for (int j = 0; j < 3; j++) {
		for (int k = 0; k < 3; k++) {
			printf("%d ", *str + i * 3 + k);
		}
	}
	//for (int row = 0; row < rowlen; row++) {
	//	for (int col = 0; col < collen; col++) {
	//		lentharr[i]=FindPath(str, row, col, rowlen, collen);
	//		i++;
	//	}
	//}
	//for (int k = 0; k < 8; k++) {
	//	if (lentharr[k]>=lentharr[k + 1]) {
	//		x = lentharr[k];
	//		lentharr[k] = lentharr[k + 1];
	//		lentharr[k + 1] = x;
	//	}
	//}
	//for (int i = 0; i < 9; i++) {
	//	printf("%d", lentharr[i]);
	//}
	//return lentharr[8];
}
int main() {
	int str[3][3] = { { 3, 4, 5 },
					  { 3, 2, 6 },
					  { 2, 2, 1 }
					};
	printf("%d", longestIncreasingPath(str,3,3));
	system("pause");
	return 0;
}