#include <stdio.h>
#include <string.h>
#include <stdlib.h>


char buf[16] = "EMPTY";
char prepend_str[] = "CENSORED:";

static void censor_print(char *dst, const char *src)
{
	char forbidden[2] = { 'c', 'z' };

        strcpy(dst, src);

	for (char *bp = dst; *bp != '\0'; bp++) {
		for (int i = 0; i < 2; i++) {
			if (*bp == forbidden[i])
				*bp = '-';
		}
	}
	printf("%s %s\n", prepend_str, dst);
}

static void censor_test(char how, const char *str)
{
	char localbuf[24];
	char *b1, *b2;

	switch (how) {
	case 'g':
		censor_print(buf, str);
		break;
	case 'h':
		b1 = calloc(16, 1);
		b2 = calloc(16, 1);
		censor_print(b1, str);
		break;
	case 's':
		censor_print(localbuf, str);
		break;
	default:
		printf("Unknown type of buffer to use for censoring: '%c'\n", how);
		return;
	}
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
