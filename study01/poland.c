#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'
#define BUFFSIZE 100

#define MAXVAL 100

char buff[BUFFSIZE];
int bufp;

int getch() {
	return (bufp > 0) ? buff[--bufp] : getchar();
}

void ungetch(int c) {
	if(bufp < BUFFSIZE)
		buff[bufp++] = c;
}

int getop(char s[]) {
	int i, c;
	while((s[0]= c = getch()) == ' ' || c == '\t');
	s[1] = '\0';
	if(!isdigit(c) && c != '.')
		return c;
	i = 0;
	if(isdigit(c)) {
		while(isdigit((s[++i] = c = getch())));
	}
	if(c == '.')
		while(isdigit((s[++i] = c = getch())));
	s[i] = '\0';
	if(c != 's')
		ungetch(c);
	return NUMBER;
}

int sp = 0;
double val[MAXVAL];

void push(double f) {
	if(sp < MAXVAL)
		val[sp++] = f;
}

double pop(void) {
	double s;
	if(sp > 0)
		s = val[--sp];
	return s;
}

int main() {
	int type;
	double op2;
	char s[MAXOP];
	while((type = getop(s)) != 's') {
		switch(type) {
			case NUMBER : {
				push(atof(s));
			}
			break;
			case '+' : push(pop() + pop()); break;
			case '*' : push(pop() * pop()); break;
			case '-' : {
				   double temp = pop();
			       	   push(pop() - temp);
			}
			break;
			case '/' : {
				   double temp = pop();
				   if(temp != 0)
			       	       push(pop() / temp);
			}
			break;
			case '\n' : printf("answer = %.8g\n",pop()); break;
			default : break;
		}

	}
	return 0;
}

























