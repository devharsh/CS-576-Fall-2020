#include <stdlib.h>
//#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/personality.h>


static inline int time_travel()
{
	int pmask = personality(-1);
	if (pmask == -1) {
		perror("personality reading failed");
		return -1;
	}
	/* printf("Current personality 0x%x\n", pmask); */

	pmask |= ADDR_NO_RANDOMIZE | READ_IMPLIES_EXEC;
	if (-1 == personality(pmask)) {
		perror("personality writing failed");
		return -1;
	}
	/* printf("New personality 0x%x\n", pmask); */
	return 0;
}

static inline void exec_target(int argc, char * const argv[])
{
	execvp(argv[1], argv + 1);
	perror("executing target failed");
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Requires at least one argument\n");
		return EXIT_FAILURE;
	}

	if (time_travel() != 0)
		return EXIT_FAILURE;

	exec_target(argc, argv); /* Never returns */

	return EXIT_FAILURE;
}
