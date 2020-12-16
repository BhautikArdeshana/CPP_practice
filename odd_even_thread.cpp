#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <map>




using namespace std;
std::mutex mu;
std::condition_variable cond;
int count1=1;

void print_odd(){
	for (; count1 < 100;) {
		unique_lock<mutex>locker(mu);
		cond.wait(locker, []() {return (count1 % 2 == 1); });
		cout << "from odd count = " << count1++ << endl;
		locker.unlock();
		cond.notify_one();
	}
}

void print_even() {
	for (; count1 <= 100;) {
		unique_lock<mutex>locker(mu);
		cond.wait(locker, []() {return (count1 % 2 == 0); });
		cout << "from even count = " << count1++ << endl;
		locker.unlock();
		cond.notify_one();
	}
}
int main()
{
	std::thread t1(print_odd);
	std::thread t2(print_even);
	t1.join();
	t2.join();
	return 0;
	map<int, int>m;
	m.insert(pair<int, int>(1, 40));
	m.insert(pair<int, int>(2, 50));
	m.insert(pair<int, int>(3, 60));
	m.insert(pair<int, int>(4, 70));
}