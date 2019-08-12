#include <iostream>
#include <string>
using namespace std;

class Person {
public : 
	Person():name(""),age(0) {
		cout << "Default constructor" << endl;
	}
	Person(string name, int age) :name(name), age(age) {
		cout << "parameterized constructor" << endl;
	}
	Person(Person &rhs) {
		this->age = rhs.age;
		this->name = rhs.name;
		cout << "copy constructor" << endl;
	}
	Person operator = (const Person &rhs) {
		cout << "in asignment operator" << endl;
		if (this != &rhs) {
			name = rhs.name;
			age = rhs.age;
		}
		return *this;
	}
	 virtual ~Person() {
		cout << "in destructor" << endl;
	}
private:
	int age;
	string name;
};
class teacher:public Person {
public:
	teacher():val(0){
		cout << "in teacher costructor" << endl;
	}
	~teacher() {
		cout << "teacher destructor"<<endl;
	}
private:
	int val;
};


int main()
{
	cout << "In Main" << endl;
	Person p;
	Person p1("Bhautik", 26);
	Person p2 = p1;
	p = p2;
	Person* t = new teacher();
	delete t;
}
