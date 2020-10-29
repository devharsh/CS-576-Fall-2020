#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void never_call_me()
{
	puts("I told you to never call me!");
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
	void (*fptr)();

	if (argc <= 1)
		fptr = welcome;
	else {
		/* Missing */
	}

	fptr();

}


int main(int argc, char **argv)
{
	echo();

	icall(argc);

	return 0;
}
