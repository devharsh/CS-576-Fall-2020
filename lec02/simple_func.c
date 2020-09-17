
static int total;
static int total_over_threshold = 0;
static int arbitrary_theshold = 16700;

int simple_function(int a, int b, int x)
{
	int y;

	y = a*x*x + b*x;

	if (y > arbitrary_theshold)
		total_over_threshold++;

	total++;

	return y;
}


int main(int argc, char **argv)
{

	simple_function(2, 7, 10);
	simple_function(101, 77, 36);

	return 0;
}
