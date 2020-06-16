#include<iostream>
#include<thread>
#include<windows.h>
#include <future>
using namespace std;
void fun(std::promise<int>* promise_obj) {
	cout << "in Fun " << endl <<"Creaating merge conflict";
	promise_obj->set_value(15);
}

//void initiazer(std::promise<int>* promObj)
//{
//	std::cout << "Inside Thread" << std::endl;
//	promObj->set_value(35);
//}
int main()
{
	promise<int> promise_obj;
	future<int>future_obj = promise_obj.get_future();
	thread th(fun, &promise_obj);
	cout << "future val :-" << future_obj.get() << endl;
	th.join();
	/*std::promise<int> promiseObj;
	std::future<int> futureObj = promiseObj.get_future();
	std::thread th(initiazer, &promiseObj);
	std::cout << futureObj.get() << std::endl;
	th.join();*/
	return 0;
}
