#include <iostream>
using namespace std;

class PrintQueue {
private:
	static const int MAX_SIZE = 100;
	char queue[MAX_SIZE][50]; // Array to hold document names
	int frontIndex;
	int rearIndex;

public:
	PrintQueue()
	{
		frontIndex = 0;
		rearIndex = 0;
	}

	void enqueue(const char document_name[])
	{
		if (rearIndex < MAX_SIZE) {
			strcpy_s(queue[rearIndex], sizeof(queue),document_name);
			rearIndex++;
		}
		else {
			cout << "Queue is full!" << endl;
		}
	}

	void dequeue() {
		if (frontIndex < rearIndex) {
			cout << "Printing: " << queue[frontIndex] << endl;
			frontIndex++;
		}
		else {
			cout << "Queue is empty!" << endl;
		}
	}

	void front() {
		if (frontIndex < rearIndex) {
			cout << "Next document to print: " << queue[frontIndex] << endl;
		}
		else {
			cout << "Queue is empty!" << endl;
		}
	}

	void display() {
		if (frontIndex < rearIndex) {
			cout << "Remaining print jobs in the queue:" << endl;
			for (int i = frontIndex; i < rearIndex; i++) {
				cout << queue[i] << endl;
			}
		}
		else {
			cout << "Queue is empty!" << endl;
		}
	}
};

int main() {
	PrintQueue pq;
	pq.enqueue("Document1");
	pq.enqueue("Document2");
	pq.enqueue("Document3");

	pq.front();
	pq.display();
	pq.dequeue();
	pq.display();

	return 0;
}
