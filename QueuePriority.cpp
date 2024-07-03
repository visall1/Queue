#include<iostream>
#include<time.h>
using namespace std;
class QueuePriority
{
	int* wait;
	int* pri;
	int MaxQueueLength;
	int QueueLength;
public:
	QueuePriority(int m);
	~QueuePriority();
	void Add(int c, int p);
	int Extract();
	bool IsEmpty();
	void Clear();
	bool IsFull();
	void Show();


private:

};

QueuePriority::QueuePriority(int m)
{
	QueueLength = 0;
	MaxQueueLength = m;
	wait = new int[MaxQueueLength];
	//pri = new int[MaxQueueLength];
}

QueuePriority::~QueuePriority()
{
	delete[] wait;
	delete[] pri;
}

void QueuePriority::Add(int c, int p)
{
	if (!IsFull()) {
		wait[QueueLength++] = c;
		pri[QueueLength++] = p;
		QueueLength++;
	}
}

int QueuePriority::Extract()
{
	if (!IsEmpty()) {
		int max_pri = pri[0];
		int pos_max_pri = 0;
		for (int i = 1; i < QueueLength; i++) {
			if (max_pri < pri[i]) {
				max_pri = pri[i];
				pos_max_pri = i;
			}
		}
		int temp1 = wait[pos_max_pri];
		int temp2 = pri[pos_max_pri];
		for (int i = pos_max_pri; i < QueueLength - 1; i++) {
			wait[i] = wait[i - 1];
			pri[i] = pri[i - 1];
		}
		QueueLength--;
		return temp1;

	}
	else return -1;
}

bool QueuePriority::IsEmpty()
{
	return QueueLength == 0;
}

void QueuePriority::Clear()
{
	QueueLength = 0;
}

bool QueuePriority::IsFull()
{
	return QueueLength == MaxQueueLength;
}
void QueuePriority::Show()
{
	for (int i = 0; i < QueueLength; i++) {
		cout << wait[i] << " - " << pri[i] << endl;
	}
}
int main() {
	srand(time(0));

	QueuePriority QUP(10);
	QUP.Add(4, 5);
	QUP.Show();
	return 0;
	
}