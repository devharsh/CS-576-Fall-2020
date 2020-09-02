#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("I am gonna snooze");
	int i = 1;

	while (i < 60) {
		i++;
		sleep(1);
	}
	printf("I am awake\n");
	return 0;
}
