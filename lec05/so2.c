#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFSZ 512


int spare_func1(void)
{
	int buf[4];
	int r;

	r = rand();
	buf[r % 4] = r;
	printf("rand: %d\n", buf[0]);

	return r & 1;
}

int spare_func2(int n, const char *str)
{
	int i, nc = 0;

	for (i = 0; i < n; i++) {
		nc += printf("%d: %s\n", i, str);
	}
	return nc;
}

int spare_func3(int n, const char *s1)
{
	char buf[128];
	int i;

	strcpy(buf, s1);
	for (i = 1; i < n; i++) {
		strcat(buf, s1);
	}

	puts(buf);

	return strlen(buf);
}


void do_echo(const char *str)
{
	char echo[128] = "echo: ";
	int i;

	for (i = 6; *str != '\n'; i++) {
		echo[i] = *str++;
	}
	echo[i] = '\0';

	puts(echo);
}

int main(int argc, char **argv)
{
	char buf[BUFSZ];
	int r;

	while (1) {
		r = read(STDIN_FILENO, buf, BUFSZ);
		if (r <= 0)
			break;
		do_echo(buf);
	}

	return 0;
}
