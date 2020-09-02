#include <stdio.h>

void accept() {
	printf("Access granted.\n");
}

void deny() {
	printf("Access denied.\n");
}

int main() {
	int a = 0;

	if (a == 12345) {
		accept();
	} else {
		deny();
	}

	return 0;
}
