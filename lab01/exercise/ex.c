#include <stdio.h>

#define ADMIN 41414141

int cc;

void accept() {
	int loop;

	printf("Access granted\n");

	while (cc) {
		cc--;
	}
}

void deny() {
	printf("Access denied.\n");;
}

int main() {
	int cwid;
	int admin = 0;

	printf("Enter your CWID:");
	scanf("%d", &cwid);
	cc = cwid % 10;

	if (cwid == ADMIN) {
		admin == 1;
	}

	if (admin) {
		accept();
	} else {
		deny();
	}

	return 0;
}
