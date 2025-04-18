#include <iostream>
using namespace std;
class Node {
public:
	int ticket_id;
	Node* next;

	Node(int id) : ticket_id(id), next(nullptr) {}
};

class Queue
{
private:
	Node* front;
	Node* rear;

public:
	Queue() : front(nullptr), rear(nullptr) {}

	void enqueue(int ticket_id) {
		Node* newNode = new Node(ticket_id);
		if (rear) {
			rear->next = newNode;
		}
		else {
			front = newNode;
		}
		rear = newNode;
	}

	void dequeue() {
		if (front) {
			Node* temp = front;
			front = front->next;
			if (!front) {
				rear = nullptr;
			}
			delete temp;
		}
	}

	int frontTicket() {
		if (front) {
			return front->ticket_id;
		}
		return -1; // Indicating empty queue
	}

	void display() {
		Node* current = front;
		while (current)
		{
		   cout << current->ticket_id << " ";
			current = current->next;
		}
		cout << endl;
	}

	~Queue() 
	{
		while (front)
		{
			dequeue();
		}
	}
};

int main() 
{
	Queue ticketQueue;
	ticketQueue.enqueue(1001);
	ticketQueue.enqueue(1002);
	ticketQueue.enqueue(1003);

	cout << "Next ticket to resolve: " << ticketQueue.frontTicket() << endl;
	ticketQueue.display();

	ticketQueue.dequeue();
	cout << "After resolving a ticket:" << endl;
	ticketQueue.display();
	system("pause");
	return 0;
}
