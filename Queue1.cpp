#include<iostream>
using namespace std;
class Queue
{
	int* wait;
	int MaxQueueLength;
	int QueueLength;
public:
	Queue(int m);
	Queue& Add(int numbeer); // enqueu
	int Extract(); //dequeue
	bool IsFull();
	bool IsEmpty();
	void Clear();
	friend ostream& operator<<(ostream& os, const Queue& queue);
	Queue& operator<<(int n);

	~Queue();

private:

};

Queue::Queue(int m)
{
	MaxQueueLength = m;
	QueueLength = 0;
	wait = new int[m];
}

Queue& Queue::Add(int number)
{
	if (!IsFull()) {
		wait[QueueLength++] = number;
	}
	else {
		cout << "Queue Full! come another time.\n";
	}

	return *this;
}

int Queue::Extract()
{
	if (!IsEmpty()) {
		int ret = wait[0];
		for (int i = 1; i < QueueLength; i++) {
			wait[i - 1] = wait[i];
		}
		QueueLength--;
		Add(ret);
		return ret;
	}
	else { cout << "Queue is Empty.\n"; }

	return 0;
}

bool Queue::IsFull()
{
	return QueueLength == MaxQueueLength;
}

bool Queue::IsEmpty()
{
	return QueueLength == 0;
}

void Queue::Clear()
{
	QueueLength = 0;
}

Queue& Queue::operator<<(int n)
{
	return Add(n);
}

Queue::~Queue()
{
	delete[] wait;
}

ostream& operator<<(ostream& os, const Queue& queue)
{
	for (int i = queue.MaxQueueLength-1; i >= 0; i--) {
		os.width(3);
		if (i >= queue.QueueLength) { os << " "; }
		else { os << queue.wait[i]; }
	}
	os << endl;
	return os;
}

//int main() {
//	Queue queue(20);
//	cout << "Queue is Empty: " << queue.IsEmpty() << endl;
//	cout << "Queue is Full: " << queue.IsFull() << endl;
//	queue.Add(8)
//		.Add(5)
//		.Add(7)
//		.Add(3);
////	queue << 5 << 3 << 4 << 7;
//	cout << queue;
//	int i = 10;
//	while (i > 0) {
//		cout << "Extracted: " << queue.Extract() << endl;
//		cout << queue;
//		i--;
//	}
//
//	return 0;
//}
