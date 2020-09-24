#include <stdio.h>
#include <string.h>

void copy(const char *str)
{
	char buf1[16];
	char buf2[16];
	int i;

	i = 0;

	strcpy(buf1, str);

	for (i = 0; i < 5; i++)
		puts(buf1);
}

void f1(const char *str)
{
	char buf1[16];

	copy(str);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		return 1;
	f1(argv[1]);
	return 0;
}
