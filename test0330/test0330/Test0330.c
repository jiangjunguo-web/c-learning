#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

int main() {
	int a[3][4] = { 0 };
	//printf("%d",sizeof(a));		//48   12��int���͵�Ԫ��
	//printf("%d", sizeof(a[0][0]));		//4   Ϊint����
	//printf("%d",sizeof(a[0]));		//16   Ϊint[4]����
	//printf("%d", sizeof(a[0]+1));		//4    Ϊint*����
	//printf("%d", sizeof(*(a[0]+1)));			//4    Ϊint����
	//printf("%d", sizeof(a+1));			//4   Ϊint(*)[4]����
	//printf("%d", sizeof(*(a+1)));		//16   Ϊint[4]����
	//printf("%d", sizeof(&a[0]+1));		//4   Ϊint(*)[4]����
	//printf("%d", sizeof(*(&a[0]+1)));		//16   Ϊint[4]����
	//printf("%d", sizeof(*a));		//16   a��ʽתΪint(*)[4]���ͣ��ٽ�����Ϊint[4]����
	//printf("%d", sizeof(a[3]));		//16   �ڱ���ʱsizeof�Ѿ����int[4]���͵����㣬
										//�����±�Խ���δ������Ϊ��ֻ��������ʱ�Ż����ַ��±�Խ�硣
	system("pause");
	return 0;
}