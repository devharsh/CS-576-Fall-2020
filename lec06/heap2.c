#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFSZ 512


struct heap_ptrs {
	long *lnum;
	long cnum;
};

char *echo_buf;
struct heap_ptrs *ptrs;
long last_num = 0;


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
	int i;

	for (i = 6; *str != '\n'; i++) {
		echo_buf[i] = *str++;
	}
	echo_buf[i] = '\0';

	puts(echo_buf);

	*ptrs->lnum = ptrs->cnum;
}

int main(int argc, char **argv)
{
	char buf[BUFSZ];
	int r;

	echo_buf = malloc(128);
	if (!echo_buf)
		goto nomem;
	strcpy(echo_buf, "echo: ");

	ptrs = malloc(sizeof(*ptrs));
	if (!ptrs)
		goto nomem;

	ptrs->lnum = &last_num;
	ptrs->cnum = rand();

	while (1) {
		r = read(STDIN_FILENO, buf, BUFSZ);
		if (r <= 0)
			break;
		do_echo(buf);
	}

	return EXIT_SUCCESS;

nomem:
	perror("malloc");
	return EXIT_FAILURE;
}
