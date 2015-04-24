#include "leetcode.h"

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

bool is_odd(int i) { return i & 1; }
bool is_odd_pair(pair<int, int> i) { return i.first & 1; }

int main4(void){
	vector<int> v = { 1, 99999, 2, 3, 4, 99999, 99999, 5, 6, 99999, 7, 8, 9, 99999, 10 };
	cout << v.size() << endl;
	for (int x : v)
		cout << x << ", ";
	cout << endl;
	
	//v.erase(remove_if(v.begin(), v.end(), is_odd), v.end());
	v.erase(remove_if(v.begin(), v.end(), [](int i){ return i & 1; }), v.end());
	/*for (vector<int>::iterator iter = v.begin(); iter != v.end();){
		if (*iter & 1){
			iter = v.erase(iter);
		}
		else  iter++;
	}
	*/

	for (int x : v)
		cout << x << ", ";
	cout << endl;

	set<int> s = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 99999 };
	for (int x : s)
		cout << x << ", ";
	cout << endl;

	//s.erase(remove_if(s.begin(), s.end(), is_odd), s.end());
	for (set<int>::iterator iter = s.begin(); iter != s.end();){
		if (*iter & 1){
			cout << *iter << "--";
			iter = s.erase(iter);
			cout << *iter << "**";
		}
		else  iter++;
	}

	for (int x : s)
		cout << x << ", ";
	cout << endl;

	
	int keys[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 99999 };
	int values[] = { 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 199999 };
	map<int, int> dic;
	for (int i = 0; i < 12; i++){
		dic.insert(make_pair(keys[i], values[i]));
	}
	for (pair<int, int> x : dic)
		cout << x.first << "," << x.second << "; ";
	cout << endl;

	//dic.erase(remove_if(dic.begin(), dic.end(), is_odd_pair), dic.end());
	for (map<int, int>::iterator iter = dic.begin(); iter != dic.end();){
		if (iter->first & 1){
			iter = dic.erase(iter);
		}
		else  iter++;
	}

	for (pair<int, int> x : dic)
		cout << x.first << "," << x.second << "; ";
	cout << endl;
}

int main3(void)
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

void ff(char **p)
{
	*p += 2;
}

int main__p()
{
	char *a[] = { "123", "abc", "456" }, **p;
	p = a;
	ff(p);
	cout << **p << endl;
	printf("%c\r\n", **p);
	return 0;
}

char* getMem(void)
{
	char *p = "helloAworld";
	p[5] = 66;
	cout << p[5] << endl;
	return p;
}

int main_memt()
{
	char *s = 0x0;
	s = getMem();
	cout << s << endl;
	printf(s);

	char *p = "helloAworld";
	p[5] = 66;
	cout << p[5] << endl;
	cout << "" << endl;
	return 0;
}

class CC
{
public:
	static int sss;
	int kkk;
	static void SA()
	{
		sss = 0;
	}

	void BB()
	{
		SA();
	}

	int foo(int x)
	{
		return x&-x;
	}
};

int main121121121121121(){
	CC c;
	int kk = (1 << 31) - 3;
	cout << kk <<","<< c.foo(kk) << endl;
	return 0;
}

int main_555555(){
	int i = 3;
	printf("%d, %d", ++i, ++i);
	return 0;
}

int main_swappppppppp()
{
	TreeNode *a = new TreeNode(1);
	TreeNode *b = new TreeNode(2);
	swap(a->val, b->val);
	cout << a->val << b->val << endl;
	return 0;
}