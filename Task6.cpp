#include <iostream>
using namespace std;
class Package {
public:
	char packageID[20];
	char deliveryAddress[100];
	int startTime;
	int endTime;

	Package(const char* id, const char* address, int start, int end) {
		strcpy_s(packageID, sizeof(packageID), id );
		strcpy_s(deliveryAddress, sizeof(deliveryAddress), address );
		startTime = start;
		endTime = end;
	}
};

class Queue {
private:
	Package* packages[100];
	int front;
	int rear;

public:
	Queue() : front(0), rear(0) {}

	void enqueue(const char* id, const char* address, int start, int end)
	{
		if (rear < 100) 
		{
			packages[rear++] = new Package(id, address, start, end);
		}
	}

	void dequeue()
	{
		if (front < rear)
		{
			delete packages[front++];
		}
	}

	Package* frontPackage()
	{
		if (front < rear) 
		{
			return packages[front];
		}
		return nullptr;
	}

	void display()
	{
		for (int i = front; i < rear; i++) 
		{
		cout << "Package ID: " << packages[i]->packageID<< ", Address: " << packages[i]->deliveryAddress<< ", Time Window: [" << packages[i]->startTime<< ", " << packages[i]->endTime << "]" << endl;
		}
	}

	bool timeToDeliver()
	{
		if (front < rear)
		{
			int currentTime = 0; // Assume current time is 0 for this example
			if (packages[front]->endTime < currentTime) 
			{
				return false; // Package expired
			}
		}
		return true; // Package can still be delivered
	}
};

int main()
{
	Queue deliveryQueue;
	deliveryQueue.enqueue("PKG001", "123 Main St", 1, 5);
	deliveryQueue.enqueue("PKG002", "456 Elm St", 2, 6);
	deliveryQueue.display();

	if (!deliveryQueue.timeToDeliver())
	{
		deliveryQueue.dequeue();
	}

	deliveryQueue.display();
	system("pause");
	return 0;
}
