#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void IsRotation(char str1[],int k) {
	int len = strlen(str1);
	int temp1;
	int flag = 0;
	//ÒÆ¶¯Î»Êý
	for (int i = 1; i <= len-k; i++) {
	//×Ö·û´®´¦Àí
		temp1 = str1[len - 1];
		for (int j = len-1; j>0; j--) {
			str1[j] = str1[j-1];
		}
		str1[0] = temp1; 
	}
	for (int m = 0; m < len; m++) {
		printf("%c", str1[m]);
	}
}

void Search(int arr[][3], int *px, int *py, int num)
{
	int j = *py - 1;
	int i = 0;
	while (i < *px && j >= 0)
	{
		if (num > arr[i][j])
		{
			i++;
		}
		else if (num < arr[i][j])
		{
			j--;
		}
		else
		{
			*px = i;
			*py = j;
			return;
		}
	}
	*px = -1;
	*py = -1;
}

typedef int(*Cmp) (int, int);
//Ã°ÅÝÅÅÐò
void BubbleSort(int str[], int len,Cmp cmp) {
	int temp;
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < len - 1 - i; j++) {
			if (cmp(str[j],str[j + 1])==1) {
				temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}	
		}
	}
}

int Less(int x, int y) {
	return x > y ? 1 : 0;
}
int int_cmp(const void* p1, const void* p2) {
	return(*(int *)p1 > *(int *)p2);

}
int char_cmp(const void* p1, const void* p2) {
	return(*(char *)p1 > *(char *)p2);

}
int main()
{
	char a = 'a';
	char b = 'b';
	char* p = &a; 
	char* q = &b;
	printf("%d", char_cmp(p, q));
	system("pause");
	return 0;
}
