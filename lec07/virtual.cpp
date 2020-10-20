#include <cstdio>

class ClassA {
public:
	virtual void vfunc1() { this->a += 1; }
	void func1() { this->a = 1; }

	void print() { printf("%d\n", this->a); }
protected:
	int a;
};


class ClassB : public ClassA {
public:
	virtual void vfunc1() { this->a += 2; }
	virtual void vfunc2() { this->a += 4; }
	void func2() { this->a = 2; }
};



int main()
{
	ClassA *a;
        ClassB *b;

        b = new ClassB();

        a = b;
        a->vfunc1();
        b->vfunc1();

	a->print();
	b->print();

	return 0;
}
