#include <iostream>
#include <thread>
#include <future>
#include <mutex>
#include <string>
#include <fstream>
#include <deque>

using namespace std;

deque<int> q;
mutex mu;

void fountion1() {
	int count = 10;
	while (count > 0) {
		unique_lock<mutex> locker(mu);
	}
}


int main()
{

	thread t1(fountion1);
	thread t2(fountion2);

	t1.join();
	t2.join();

	return 0;
}
