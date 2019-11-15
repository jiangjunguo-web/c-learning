#include  <stdio.h>
#include <stdlib.h>
int mult(int a, int b) {
	int temp=1;
	for (int i = 0; i < b; i++) {
		temp = a*temp;
	}
	return temp;
}
int sum(int n) {
	int sum1 = 0;
	int sum2 = 0;

	for (int i = 0; i < 5; i++) {
		sum1 += mult(10,i)*n;
		sum2 += sum1;
	}
	return sum2;
}
int main() {

	printf("%d", sum(2));
    system ("pause");
    return 0;
}