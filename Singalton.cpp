// Singalton.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class singalton {
private:
	singalton() {};
	singalton(singalton& rhs) {};
	~singalton() {};
	static singalton* instance;
public:

	static singalton* getInstace() {
		if (!instance) {
			instance = new singalton;
			cout << "first instance" << endl;
			return instance;
		}
		else {
			cout << "second instance" << endl;
			return instance;
		}
	}
};

singalton* singalton::instance = 0;

int main()
{
    std::cout << "Hello World!\n";

	singalton *s= singalton::getInstace();
	singalton* s1 = singalton::getInstace();


}
