#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFSZ 512


int spare_func1(void)
{
	int r;

	r = rand();
	printf("rand = %d\n", r);

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

void do_echo(const char *str)
{
	char echo[128] = "echo: ";
	int i;

	strcat(echo, str);

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
