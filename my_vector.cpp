#include<iostream>
#include<vector>
#include<string>
using namespace std;

class myvector {
private:
	int vsize;
	int maxsize;
	int* array;
	void alloc_new();
public:
	myvector();
	myvector(int);  //int max size
	myvector(const myvector&); //copy constructor
	~myvector(); //deallocate memory
	void push_back(int); //push an element to the end
	int size();
	int operator[](int); //pass int in () and return an int when using [] operator
	myvector& operator=(const myvector& v);
	myvector& operator+=(int);
	int at(int);
	//int operator[](int i);
};
//------
myvector::myvector()
{
	maxsize = 20;
	array = new int[maxsize];
	vsize = 0;
}
myvector::myvector(int i)
{
	maxsize = i;
	array = new int[maxsize];
	vsize = 0;
}
//copy constructor
myvector::myvector(const myvector& v)
{
	maxsize = v.maxsize;
	vsize = v.vsize;
	array = new int[maxsize];
	for (int i = 0; i < v.vsize; i++)
	{
		array[i] = v.array[i];
	}
}

//Destructor
myvector::~myvector()
{
	delete[] array;
}

void myvector::push_back(int i)
{
	if (vsize + 1 > maxsize)
		alloc_new();
	array[vsize] = i;
	vsize++;
}
int myvector::operator[](int i)
{
	return array[i];
}
int myvector::at(int i)
{
	if (i < vsize)
		return array[i];
	throw 10;
}
void myvector::alloc_new()
{
	maxsize = vsize * 2; //new size
	int* tmp = new int[maxsize]; // pointer the the newly created array
	for (int i = 0; i < vsize; i++)
	{
		tmp[i] = array[i]; //copy array elements to tmp
		delete[] array; //delete array old
		array = tmp; //temp gets the same address
	}
}
int myvector::size()
{
	return vsize;
}

myvector& myvector::operator+=(int i)
{
	this->push_back(i); //this->push_back(i);
	return *this;
}

myvector& myvector::operator=(const myvector& v)
{
	if (this != &v)
	{	vsize = v.vsize;
		maxsize = v.maxsize;
		delete[] array; //delete array= delete v.array
		array = new int[maxsize];
		for (int i = 0; i < v.vsize; i++)
			array[i] = v.array[i];
	}
	return *this;
}

int main(int argc, char** argv) {
	myvector vec;
	myvector vec3;
	int tmp;
	cout << endl << "Enter a number to INSERT or -1 to  QUIT !" << endl << endl;
	while (1)
	{
		cin >> tmp;
		if (tmp == -1)
			break;
		vec.push_back(tmp);
	}

	vec += 99;
	myvector vec2 = vec;
	for (int i = 0; i < vec2.size(); i++)
	{
		cout << vec2[i] << " ";
	}
	
	cout << endl << endl << endl << "The container holds (" << vec.size() << " ) elements" << endl << endl;
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
	vec3 = vec;
	for (int i = 0; i < vec3.size(); i++)
	{
		cout << vec3[i] << " ";
	}
}