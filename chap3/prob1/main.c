#include<stdio.h>
#include<string.h>
#include "copy.h"

char line[MAXLINE];
char longest[MAXLINE];

void copy(char from[], char to[]);
int main(void) {
    int len;
    int max = 0;

    while(fgets(line, MAXLINE, stdin) != NULL) {
        len = strlen(line);

        if(len > max) {
            max = len;
            copy(longest, line);
         }
    }
    if(max > 0)
        printf("%s \n", longest);

    return 0;
}
