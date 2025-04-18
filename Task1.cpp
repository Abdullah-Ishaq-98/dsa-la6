#include <iostream>
using namespace std;

template <typename T>
class AbstractQueue {
public:
	virtual void enQueue(T value) = 0;
	virtual T deQueue() = 0;
	virtual T front() const = 0;
	virtual bool isEmpty() const = 0;
	virtual bool isFull() const = 0;
	virtual ~AbstractQueue() {}
};

template <typename T>
class myQueue : public AbstractQueue<T> {
private:
	T* arr;
	int frontIndex;
	int rearIndex;
	int maxSize;

public:
	myQueue(int size) : maxSize(size), frontIndex(0), rearIndex(0) {
		arr = new T[maxSize];
	}

	void enQueue(T value) override {
		if (!isFull()) {
			arr[rearIndex] = value;
			rearIndex = (rearIndex + 1) % maxSize;
		}
	}

	T deQueue() override {
		if (!isEmpty()) {
			T value = arr[frontIndex];
			frontIndex = (frontIndex + 1) % maxSize;
			return value;
		}
		throw out_of_range("Queue is empty");
	}

	T front() const override {
		if (!isEmpty()) {
			return arr[frontIndex];
		}
		throw out_of_range("Queue is empty");
	}

	bool isEmpty() const override {
		return frontIndex == rearIndex;
	}

	bool isFull() const override {
		return (rearIndex + 1) % maxSize == frontIndex;
	}

	void display() const {
		for (int i = frontIndex; i != rearIndex; i = (i + 1) % maxSize) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	~myQueue() {
		delete[] arr;
	}
};

int main() {
	myQueue<int> queue(5);
	int choice, value;

	do {
		cout << "1. Enqueue\n2. Dequeue\n3. Front\n4. Display\n5. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "Enter value to enqueue: ";
			cin >> value;
			queue.enQueue(value);
			break;
		case 2:
			try {
				cout << "Dequeued: " << queue.deQueue() << endl;
			}
			catch (const out_of_range& e) {
				cout << e.what() << endl;
			}
			break;
		case 3:
			try {
				cout << "Front: " << queue.front() << endl;
			}
			catch (const out_of_range& e) {
				cout << e.what() << endl;
			}
			break;
		case 4:
			queue.display();
			break;
		case 5:
			cout << "Exiting..." << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 5);
	system("pause");
	return 0;
}
