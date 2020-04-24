#include <stdio.h>
double atof(char s[]);

int main() {
	char s[] = "-14.123124e-8";
	printf("%e\n",atof(s));	
	return 0;
}

double atof(char s[]) {
	double val, power;
	int cnt , flag;
	int sign;
	int i = 0;
	for(; isspace(s[i]); i++);
	sign = (s[i] == '-') ? -1 : 1;
	if(s[i] == '-' || s[i] == '+')
		i++;
	for(val = 0.0; isdigit(s[i]); i++)
		val = val * 10 + (s[i] - '0');
	if(s[i] == '.')
		i++;
	for(power = 1.0; isdigit(s[i]); i++) {
		val = val * 10 + (s[i] - '0');
		power *= 10;
	}
	val = val / power;
	if(s[i] == 'e' || s[i] == 'E') {
		i++;
		flag = (s[i] == '-') ? -1 : 1;
		if(s[i] == '-' || s[i] == '+') {
			i++;
			for(cnt= 0; isdigit(s[i]); i++)
				cnt= cnt * 10 + (s[i] - '0');
			for(; cnt > 0; cnt--) 
				val = (flag == 1) ? val*10 : val*0.1;
		}
	}
		
	return sign * val;
}

