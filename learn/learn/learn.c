#include <stdio.h>
#include <stdlib.h>

int main() {
	int name;
	for (name = 'A'; name <= 'D'; name++) {
		if ((name != 'A') + (name == 'C') + (name == 'D') + (name != 'D') == 3) {
			printf("%c",name);
		}
	}
	system("pause");
	return 0;
}

