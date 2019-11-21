#include  <stdio.h>
#include <stdlib.h>

void  reverse_string(char * string) {
	if (*string != '\0') {
		reverse_string(string + 1);
		printf("%c", *(string));
	}
}

int main() {
	char* string = "abcd1234";
	reverse_string(string);
    system ("pause");
    return 0;
}