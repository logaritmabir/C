#include <iostream>
#include "Person.h"
#include <ctime>
#include <vector>
#include <thread>

using namespace std;
vector<thread*> threads;

void startTransaction();

int main()
{
	time_t createdAt = time(NULL);
	char* converTime = ctime(&createdAt);

	for (int i = 0; i < 1000; i++) {
		startTransaction();
	}
}
void startTransaction() {
	threads.push_back(new thread([]() {
		Person person;
		continueTransaction(person);
		}));
}
void continueTransaction(Person& person) {
	threads.push_back(new thread([]() {

		}));
}




