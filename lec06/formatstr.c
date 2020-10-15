#include <stdio.h>
#include <stdlib.h>

int spare_func1(void) 
{               
        int r;
        
        r = rand();
        printf("rand = %d\n", r);

        return r & 1;
}


int main(int argc, char **argv)
{
	int i, n;
	char buf[26], *s;

	for (i = 0, s = buf; i < 26; i++)
		s[i] = 'A' + i;

	printf("%0128d%n\n", i, &n);

	printf("n=%d\n", n);

	printf("%2$08d %1$08d\n", i, n);

	printf("%0*d\n", n, i);

	if (argc > 1)
		printf(argv[1]);

	return 0;
}
