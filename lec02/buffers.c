#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char buf[16] = "EMPTY";
char prepend_str[] = "CENSORED:";

static void censor(char *dst, const char *src)
{
	char forbidden[2] = { 'c', 'z' };

        strcpy(dst, src);

	for (char *bp = dst; *bp != '\0'; bp++) {
		for (int i = 0; i < 2; i++) {
			if (*bp == forbidden[i])
				*bp = '-';
		}
	}
}

static void censor_test(char how, const char *str)
{
	char localbuf[24];
	char *b1, *b2, *dst;

	switch (how) {
	case 'g':
		dst = buf;
		break;
	case 'h':
		b1 = calloc(16, 1);
		b2 = calloc(16, 1);
		dst = b1;
		break;
	case 's':
		dst = localbuf;
		break;
	default:
		printf("Unknown type of buffer to use for censoring: '%c'\n", how);
		return;
	}

	censor(dst, str);
	printf("%s %s\n", prepend_str, dst);
}

/*
 * run s|g|h string
 */
int main(int argc, char **argv)
{
	if (argc < 3)
		return -1;

	censor_test(argv[1][0], argv[2]);

	return 0;
}
