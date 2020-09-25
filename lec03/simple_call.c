#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

long F2(long a1)
{
	return a1 & 0x3;
}

void F1(short a1, long a2, char *a3)
{
	int a;
	char buf[16];
	long l;

	a = a1 + a2;

	l = F2(a);

	sprintf(buf, "%s: %d/%ld\n", a3, a, l);
}


int main(int argc, char **argv)
{

	F1(0xff, UINT_MAX, argv[0]);
	return 0;
}
