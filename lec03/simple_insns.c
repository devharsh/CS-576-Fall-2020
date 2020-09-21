
struct mystruct {
    int i[20];
    long l[10];
    char c;
};

struct mystruct ms[1000];


struct mystruct *getitem(int item)
{
    return &ms[item];
}

int getitem_i(int item, int i)
{
    return ms[item].i[i];
}

long getitem_l(int item, int l)
{
    return ms[item].l[l];
}

long getitem_cc(int item, int i)
{
    if (ms[item].c)
        return ms[item].i[i+2];
    else
        return ms[item].l[i];
}

long getitem_c(int item)
{
    return ms[item].c;
}

long sum(long a, long b)
{
    return a + b;
}

unsigned long mul(unsigned long a, unsigned long b)
{
    return a * b;
}

int main()
{
	return 0;
}
