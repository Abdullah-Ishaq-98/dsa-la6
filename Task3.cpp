#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int val) : data(val), next(nullptr) {}
};

class Queue {
private:
	Node* frontNode;
	Node* rearNode;
	int size;

public:
	Queue() : frontNode(nullptr), rearNode(nullptr), size(0) {}

	void enqueue(int val) {
		Node* newNode = new Node(val);
		if (isEmpty()) {
			frontNode = rearNode = newNode;
		}
		else {
			rearNode->next = newNode;
			rearNode = newNode;
		}
		size++;
	}

	void dequeue() {
		if (isEmpty()) return;
		Node* temp = frontNode;
		frontNode = frontNode->next;
		delete temp;
		size--;
		if (isEmpty()) rearNode = nullptr;
	}

	int front() {
		if (!isEmpty()) return frontNode->data;
		return -1; // or throw an exception
	}

	bool isEmpty() {
		return size == 0;
	}

	int getSize() {
		return size;
	}

	void reverseFirstK(int K) {
		if (K <= 1 || K > size) return;

		Node* current = frontNode;
		Node* prev = nullptr;
		Node* next = nullptr;
		int count = 0;

		while (count < K && current != nullptr) {
			next = current->next;
			current->next = prev;
			prev = current;
			current = next;
			count++;
		}

		if (frontNode != nullptr) {
			frontNode->next = current;
		}
		frontNode = prev;
	}

	void display() {
		Node* temp = frontNode;
		while (temp != nullptr) {
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}
};

int main() {
	Queue q;
	int n, val, K;

	cout << "Enter the number of elements in the queue: ";
	cin >> n;
	cout << "Enter the elements: ";
	for (int i = 0; i < n; i++) {
		cin >> val;
		q.enqueue(val);
	}

	cout << "Enter K: ";
	cin >> K;

	cout << "Queue: ";
	q.display();

	q.reverseFirstK(K);

	cout << "Output: ";
	q.display();
	system("pause"); 
	return 0;
}
