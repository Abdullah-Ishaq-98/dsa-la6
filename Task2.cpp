#include <iostream>
using namespace std;

class QueueUsingStacks {
private:
	int stack1[100], stack2[100];
	int top1, top2;

public:
	QueueUsingStacks() {
		top1 = -1;
		top2 = -1;
	}

	void enqueue(int x) {
		stack1[++top1] = x;
	}

	int dequeue() {
		if (top2 == -1) {
			while (top1 != -1) {
				stack2[++top2] = stack1[top1--];
			}
		}
		if (top2 == -1) {
			cout << "Queue is empty!" << endl;
			return -1;
		}
		return stack2[top2--];
	}

	int front() {
		if (top2 == -1) {
			while (top1 != -1) {
				stack2[++top2] = stack1[top1--];
			}
		}
		if (top2 == -1) {
			cout << "Queue is empty!" << endl;
			return -1;
		}
		return stack2[top2];
	}

	void display() {
		if (top2 != -1) {
			for (int i = top2; i >= 0; i--) {
				cout << stack2[i] << " ";
			}
		}
		for (int i = 0; i <= top1; i++) {
			cout << stack1[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	QueueUsingStacks q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	q.display();
	cout << "Front element: " << q.front() << endl;
	cout << "Dequeued: " << q.dequeue() << endl;
	q.display();
	system("pause");
	return 0;
}
