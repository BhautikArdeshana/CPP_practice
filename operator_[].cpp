#include<iostream>
#include<thread>
using namespace std;
void fun() {
	cout << "in fun from thread t1" << endl;
}
void fun1() {
	cout << "in fun1 from thread t2" << endl;
}
int main()
{
	cout << "in main" << endl;
	thread t1(fun);
	thread t2(fun1);
	cout << "exting main" << endl;
}