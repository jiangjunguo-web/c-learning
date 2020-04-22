#include <stdio.h>
#include <string.h>

char* expand(char* to, char* from) {
        char lower[] = "abcdefghijklmnopqrstuvwxyz";
        char upper[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        char digital[] = "0123456789";
        int i, j;
        i = j = 0;
        char *start, *p, *end;
        while(from[i]) {
                switch(from[i]) {
                        case '-' : {
                                if(i == 0 || from[i + 1] == '\0' ) {
                                        to[j++] = '-';
                                        i++;
                                        break;
                                }
                                else {
                                        if((start = strchr(lower, from[i-1])) && (end = strchr(lower, from[i+1])));
                                        else if((start = strchr(upper, from[i-1])) && (end = strchr(upper, from[i+1])));
                                        else if((start = strchr(digital, from[i-1])) && (end = strchr(digital, from[i+1])));
                                        else {
                                                to[j++] = from[i-1];
                                                to[j++] = from[i];
                                                i++;
                                                break;
                                        }
                                        p = start;
                                        while(p != end) {
                                                if(*start > *end) {
                                                        to[j++] = *p;
                                                        p--;
                                                }
                                                else {
                                                        to[j++] = *p;
                                                        p++;
                                                }
                                        }
                                        i++;
                                }
                        }
                        break;
                        default: {
                                if(from[i+1] == '-' && from[i+2] != '\0') {
                                        i++;
                                }
                                else {
                                        to[j++] = from[i];
                                        i++;
                                }
                        }
                        break;
                }
        }
        to[j] = from[i];
        return to;
}

int main() {
        char s[] = "-gash-df1-9-askf-";
        char t[100];
        char* str = expand(t,s);
        puts(str);
        return 0;
}
