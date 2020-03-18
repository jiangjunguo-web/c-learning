#include <stdio.h>
#include <stdlib.h>

int isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
	//判断点在内的情况
	if (
		(
		((rec2[0]>rec1[0] && rec2[0] < rec1[2])
		|| (rec2[2] > rec1[0] && rec2[2]<rec1[2]))
		&&
		((rec2[1] > rec1[1] && rec2[1]<rec1[3])
		|| (rec2[3]>rec1[1] && rec2[3] < rec1[3]))
		)
		||
		(
		((rec1[0] > rec2[0] && rec1[0]<rec2[2])
		|| (rec1[2]>rec2[0] && rec1[2] < rec2[2]))
		&&
		((rec1[1] > rec2[1] && rec1[1]<rec2[3])
		|| (rec1[3]>rec2[1] && rec1[3] < rec2[3]))
		)
		||
		(((rec1[0] >= rec2[0] && rec1[2] <= rec2[2])
		&& (rec1[1] <= rec2[1] && rec1[3] >= rec2[3]))
		||
		((rec2[0] >= rec1[0] && rec2[2] <= rec1[2]
		&& (rec2[1] <= rec1[1] && rec2[3] >= rec1[3])))
		)) {
		return 1;
	}
	return 0;
}
int main() {
	int tr1[4] = { 4, 0, 6, 6};
	int str[4] = { -5, -3, 4, 2 };
	printf("%p\n", &str);
	printf("%d", isRectangleOverlap(tr1, 4, str, 4));
	system("pause");
	return 0;
}