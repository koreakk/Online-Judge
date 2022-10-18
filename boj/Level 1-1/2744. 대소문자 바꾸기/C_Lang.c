#include <stdio.h>
#define MAXLEN  100

char ConvCase(char ch) {
	int diff = 'a' - 'A';
	if (ch >= 'A' && ch <= 'Z')
		ch += diff;
	else if (ch >= 'a' && ch <= 'z')
		ch -= diff;

	return ch;
}

void solution(const char* string) {
	for (int i = 0; string[i] != '\0'; i++)
		printf("%c", ConvCase(string[i]));
}

int main(void) {
	char string[MAXLEN];
	gets(string);

	solution(string);
	return 0;
}