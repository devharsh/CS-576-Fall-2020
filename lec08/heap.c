#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int *a;

	a = malloc(sizeof(int) * 128);

	printf("Heap at %16p\n", a);

	return 0;
}
