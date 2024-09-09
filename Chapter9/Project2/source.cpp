//특정 시간 동안 프로그램 멈추기
#include<iostream>
#include<chrono>
#include<thread>

using namespace std;
using namespace chrono_literals;

int main()
{
	cout << "Going to sleep for 5 seconds"
		" and 300 milli seconds." << endl;
	this_thread::sleep_for(5s + 300ms);
	cout << "Going to sleep for another 3 seconds" << endl;
	this_thread::sleep_until(
		chrono::high_resolution_clock::now() + 3s);
	cout << "That's it." << endl;
}