#include<iostream>
#include<functional>
using namespace std;

class Array {
public:	
	Array() = default;
	Array(int* p=nullptr, int s=0){
		size = s;
		ptr = nullptr;
		if (s != 0) {
			ptr = new int[size];
			for (int i = 0; i < s; i++) {
				ptr[i] = p[i];
			}
		}
	}
	int& operator [](int i) {
		if (i > size) {
			cout << "Array index out of bound" << endl;
		}
		return ptr[i];
	}
	void print() {
		for (int i = 0; i < size; i++) {
			cout << "val["<<i<<"] = " << ptr[i] << endl;
		}
	}
private:
	int* ptr;
	int size;
};

int main()
{
	int array[] = {1,2,3,4};
	Array a(array,(sizeof(array)/sizeof(int)));
	a[3] = 10;
	a.print();
}

