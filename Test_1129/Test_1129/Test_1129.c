#include <stdio.h>
#include <stdlib.h>


int main() {
	printf("1\n");
	printf("11\n");
	
	for (int i = 1; i < 8; i++) {
       printf("1");
		for (int j = 0; j <i; j++) {
		printf("%d",i+2);
		}
		
		printf("1\n");
	}
	system("pause");
	return 0;
}