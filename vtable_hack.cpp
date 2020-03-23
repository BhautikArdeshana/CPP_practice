#include<iostream>
using namespace std;

class A {
public:
	virtual void fun() {
		cout << "A fun" << endl;
	}
	virtual void fun1() {
		cout << "A fun1" << endl;
	}
};
class B :public A {
	virtual void fun() {
		cout << "B fun" << endl;
	}
	virtual void fun1() {
		cout << "B fun1" << endl;
	}
};

int main() {
	B obj;
	typedef void (*fnptr)();
	fnptr fn1, fn2;
	long* ptr = (long *)&obj;
	long* vptr = ptr;
	long* vtable = (long *)*vptr;
	fn1 = (fnptr) * vtable;
	fn1();
	vtable++;
	fn2 = (fnptr)*vtable;
	fn2();
	getchar();
}