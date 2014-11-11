#include <SimpleDelegate/SimpleDelegate.hpp>
#include <memory>
SimpleDelegate::SimpleDelegate<int, int, int> Delegate;

void GlobalPrint(int a, int b, int c)
{
	printf("Global: A: %d; B: %d; C: %d\n", a, b, c);
};

class A
{
public:
	void Print(int a, int b, int c)
	{
		printf("Class: A: %d; B: %d; C: %d\n", a, b, c);
	};
};

class B : public A
{
public:
	int realA, realB, realC;

	B() : realA(0), realB(5), realC(10) {};
	~B()
	{
		//Remove the entire object here too
		//Delegate.DisconnectObject(this);
		Delegate.Disconnect<B, &B::Print>(this);
	};

	void Print(int a, int b, int c)
	{
		printf("DerivedClass: A: %d; B: %d; C: %d\n", realA, realB, realC);
	};
};

int main(int argc, char **argv)
{
	A AInstance;
	std::shared_ptr<B> BInstance(new B());

	Delegate.Connect<A, &A::Print>(&AInstance);
	Delegate.Connect<B, &B::Print>(BInstance.get());
	Delegate.Connect(&GlobalPrint);

	BInstance.reset();

	Delegate(1, 2, 3);
	Delegate(3, 2, 1);

	return 0;
};
