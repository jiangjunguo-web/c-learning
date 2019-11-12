#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int i,count=0;
	int div = 0;
	for (i = 1; i <= 100; i++) {
		div = i / 10;
		if (div == 9) {
			count++;
		}
		else if (i % 10 == 9) {
			count++;
		}
	}
	printf("%d\n", count);
    system ("pause");
}