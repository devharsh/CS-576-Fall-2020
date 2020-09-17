#include <stdio.h>

void simple_call(int ar) {
	int bi = 10;

	bi = bi + ar;	

	printf("%d\n", bi);

	return;
}

int main()
{
	int ia = 56824;
	float fa = 5698.25;
	char testArray[] = "0123456789ABCDEF";

	simple_call(ia);

	return 0;
}
