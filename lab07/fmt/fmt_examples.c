#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FMT_STR_PART "%0124d%n\n"

int spare_func1(void) 
{               
        int r;
        
        r = rand();
        printf("rand = %d\n", r);

        return r & 1;
}

void test_fmts(void)
{
	long i, n;
	char buf[32], *s;

	for (i = 0, s = buf; i < sizeof(buf); i++)
		s[i] = 'A' + i;

	printf("%p %p %p %p %p %p %p %p\n");

	printf("4th %4$p, 8th %8$p\n");

	n = 0;
	printf("# n=%d\n", n);

	printf("i=%d%n\n", i, &n);
	printf("# n=%d\n", n);

	printf("%0128d%n\n", i, &n);
	printf("# n=%d\n", n);

	printf("%0*d%n\n", 19, i, &n);
	printf("# n=%d\n", n);

	*(long *)buf = (long)&n;
	strcpy(buf + sizeof(long), "%0220x%x%x%x%x%x%n\n");
	printf(buf);
	printf("# n=%d\n", n);
}


int main(int argc, char **argv)
{
	printf("Example: %d %hu %p %s %d %u %d\n", 1, 2, 3, "test", 5, 6, 7);
	test_fmts();
	return 0;
}
