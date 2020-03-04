#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

int main() {
	int a[3][4] = { 0 };
	//printf("%d",sizeof(a));		//48   12个int类型的元素
	//printf("%d", sizeof(a[0][0]));		//4   为int类型
	//printf("%d",sizeof(a[0]));		//16   为int[4]类型
	//printf("%d", sizeof(a[0]+1));		//4    为int*类型
	//printf("%d", sizeof(*(a[0]+1)));			//4    为int类型
	//printf("%d", sizeof(a+1));			//4   为int(*)[4]类型
	//printf("%d", sizeof(*(a+1)));		//16   为int[4]类型
	//printf("%d", sizeof(&a[0]+1));		//4   为int(*)[4]类型
	//printf("%d", sizeof(*(&a[0]+1)));		//16   为int[4]类型
	//printf("%d", sizeof(*a));		//16   a隐式转为int(*)[4]类型，再解引用为int[4]类型
	//printf("%d", sizeof(a[3]));		//16   在编译时sizeof已经完成int[4]类型的运算，
										//不是下标越界的未定义行为，只有在运行时才会有字符下标越界。
	system("pause");
	return 0;
}