#include <stdio.h>
#include <stdlib.h>

int spare_func1(void) 
{               
        int r;
        
        r = rand();
        printf("rand = %d\n", r);

        return r & 1;
}


void test_fmts(void)
{
	char fmt[32];

	printf(fgets(fmt, sizeof(fmt), stdin));
}

int main(int argc, char **argv)
{
	test_fmts();
	return 0;
}
