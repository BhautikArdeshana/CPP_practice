#include<iostream>
using namespace std;

class A
{
public:
	A() {
		cout << "default const" << endl;
		num = new int;
	}

	A(const A &tmp) {
		//A();
		cout << "copy const" << endl;
		num = new int;
		*num = tmp.num;
	}
	~A() {
		cout << "destructor" << endl;
	}
	void setnum(int a) {
		*num = a;
	}
	int getnum() {
		return *num;
	}
private:
	int *num;
};
int main()
{
	cout << "in Main" << endl;
	A tmp;
	tmp.setnum(20);
	A tmp1 = tmp;
	cout << "tmp1 num = "<<tmp1.getnum() << endl;
	cout << "tmp num = " << tmp.getnum() << endl;
	tmp1.setnum(30);
	cout << "tmp1 num = " << tmp1.getnum() << endl;
	cout << "tmp num = " << tmp.getnum() << endl;
}

