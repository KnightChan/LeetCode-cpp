#include <iostream>

class Outer
{
public:
	static int m_Out;
	class Inner
	{
	public:
		static int m_In;
		void Display();
	};
};

int Outer::m_Out = 10;
int Outer::Inner::m_In = 25;

void Outer::Inner::Display() { std::cout << m_Out << std::endl; }

class TestPrint
{
public:
	void Print()
	{
		std::cout << "TestPrint" << std::endl;
	}
	void Print() const{
		std::cout << "const TestPrint" << std::endl;
	}

	void Print() volatile{
		std::cout << "volatile TestPrint" << std::endl;
	}

	void Print() const volatile{
		std::cout << "const volatile TestPrint" << std::endl;
	}
};

class base {
public:
	base() : i('B'){}
	char i;
};

class derived : public base{
public:
	int i;
};

int main(void)
{
	derived d;
	d.i = 65;
	std::cout << d.i;
}

int main2(void){
	TestPrint normal_test;
	normal_test.Print();

	const TestPrint const_test;
	const_test.Print();

	volatile TestPrint vt;
	vt.Print();

	const volatile TestPrint cvt;
	cvt.Print();
}

int main1(void)
{
	Outer objOut;
	Outer::Inner objIn;
	objIn.Display();
	//objOut.Inner::m_In;
	objOut.m_Out;
	Outer::Inner::m_In;
	//objIn.Outer::m_Out;
}