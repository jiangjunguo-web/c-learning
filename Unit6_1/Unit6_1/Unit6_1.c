#include <stdio.h>
#include <stdlib.h>
#include <math.h>


//·µ»ØµþÊý£º
int DataBack(a, n) {
	int sum = 0;
	int b;
	for (int i = 0; i < n; i++) {
		b =(int)pow(10, i);
		sum += a*b;
	}
	return sum;
}

int main(){
	int n = 5;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += DataBack(2,i);
	}
	printf("%d\n",sum);
	system("pause");
	return 0;
}