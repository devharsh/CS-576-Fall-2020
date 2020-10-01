#include <stdio.h>
#include <string.h>

static char mybuf[4096];

void no_access() {
	printf("Wrong.\n");
}

void display() {
	printf("Good job.\n");
}

void copy(char *str)
{
	char buf1[16];
	char buf2[16];
	int i;

	i = 0;

	strcpy(buf1, str);

	for (i = 0; i < 5; i++)
		puts(buf1);
}

void f1(char *str)
{
	char buf1[16];

	copy(str);
}

int main(int argc, char **argv)
{
	if (fread(mybuf, sizeof(mybuf), 1, stdin) < 0) {
                perror("error reading input");
		return 1;
        }
	f1(mybuf);
	return 0;
}
