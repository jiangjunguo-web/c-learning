#include <stdio.h>
#include <stdlib.h>

void sort1(int* str, int n) {
	if (str == NULL || n <= 1)
		return;
	int* te;
	int key;
	while (n-- > 1) {
		int* temp = str;
		te = ++str;
		key = *te;
		while (key < *temp) {
			*te = *temp;
			temp--;
			te--;
		}
		*te = key;
	}
}

void sort2(int* str, int n) {
	if (str == NULL || n <= 1)
		return;
	int skip = n;
	int* begin;
	int* end;
	int key;
	while (skip > 1) {
		skip = (skip + 1) / 2;
		begin = str;
		int i = 0;
		while (i++ < n - skip) {
			end = begin + skip;
			key = *end;
			if (key < *begin) {
				*end = *begin;
				*begin = key;
			}
			begin++;
		}
	}
}

void Swap(int* change1, int* change2) {
	*change1 ^= *change2;
	*change2 ^= *change1;
	*change1 ^= *change2;
}


void sort3(int* str, int n) {
	if (str == NULL || n <= 1)
		return;
	int *begin, *end, *temp;
	temp = str;
	end = str + n - 1;
	while (n--) {
		for (begin = str; begin < end; begin++)  {
			if (*begin > *temp) {
				temp = begin;
			}
		}
		if (*temp > *end)
			Swap(temp, end);
		temp = str;
		end--;
	}
}

void sort4(int* str, int n) {
	if (str == NULL || n <= 1)
		return;
	int *begin, *end, *max, *min, *temp;
	min = str;
	max = str + n - 1;
	while (min < max) {
		for (end = temp = begin = min; begin <= max; begin++) {
			if (*begin >= *temp) {
				temp = begin;
			}
			if (*begin < *end) {
				end = begin;
			}
		}
		if (*min > *end)
			Swap(min, end);
		if (*max < *temp)
			Swap(max, temp);
		end = ++min;
		temp = --max;
	}

}


void print(int* str, int m) {
	int i;
	for (i = 0; i < m; i++)
		printf("%d ", *str++);
}

int main() {
	int str[] = { 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int len = sizeof(str) / sizeof(str[0]);
	sort4(str, len);
	print(str, len);
	system("pause");
}
