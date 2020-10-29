#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

struct A {
	long a;
	long b;
	long c;
	void (*fptr)();
	char *string;
};

struct B {
	char b[32];
	long n;
};


void never_call_me()
{
	puts("You shouldn't be here!");
}

void welcome()
{
	puts("Thank you for visiting!");
}


void echo()
{
	char buf[32];

	read(STDIN_FILENO, buf, sizeof(buf));

	puts(buf);
}

void icall(int argc)
{
	struct A *sa;
	struct B *sb;

	sa = (struct A *)malloc(sizeof(struct A));

	sa->fptr = welcome;

	if (argc > 1) {
		/* free sa */
		free(sa);

		/* new malloc */
		sb = (struct B *)malloc(sizeof(struct B));

		read(STDIN_FILENO, sb->b, sizeof(sb->b));

		puts(sb->b);
	}

	sa->fptr();
}


int main(int argc, char **argv)
{
	icall(argc);

	return 0;
}
