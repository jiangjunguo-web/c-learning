#include <stdio.h>
#include <stdlib.h>
#define and &&
#define  or ||

int main() {
	int a, b, c, d, e;
	for (a = 1; a <= 5; a++) {
		for (b = 1; b <= 5; b++) {
			for (c = 1; c <= 5; c++) {
				for (d = 1; d <= 5; d++) {
					for (e = 1; e <= 5; e++) {
						if (a*b*c*d*e == 120 and
							(b == 2) ^ (a == 3) and
							(b == 2) ^ (e == 3) and
							(c == 1) ^ (d == 2) and
							(c == 5) ^ (d == 3) and
							(e == 4) ^ (a == 1)) {
							printf("a=%d  b=%d  c=%d  d=%d  e=%d\n",a,b,c,d,e);
						}
					}
				}
			}
		}
	}

	system("pause");
	return 0;
}