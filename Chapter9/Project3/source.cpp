//스레드의 시작과 중단
#include<iostream>
#include<thread>

using namespace std;
using namespace chrono_literals;

static void thread_with_param(int i)
{
	this_thread::sleep_for(1ms * i);
	cout << "Hello from thread " << i << endl;
	this_thread::sleep_for(1s * i);
	cout << "Bye from thread " << i << endl;
}

int main()
{
	cout << thread::hardware_concurrency()
		<< " concurrent threads are supported." << endl;

	thread t1{ thread_with_param, 1 };
	thread t2{ thread_with_param, 2 };
	thread t3{ thread_with_param, 3 };

	t1.join();
	t2.join();
	t3.detach();
	cout << "Threads joined." << endl;
}