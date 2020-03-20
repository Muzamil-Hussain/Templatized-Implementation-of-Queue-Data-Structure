template<class T>
class Queue {
private:
	QNode<T> *Front;
	QNode<T> *Rear;
	int noOfItems;
public:
	Queue() {
		Front = NULL;
		Rear = NULL;
		noOfItems = 0;
	}
	bool isEmpty() {
		if (noOfItems == 0)
			return true;
		return false;
	}
	void enqueue(T nValue) {
		QNode<T> *newNode = new QNode<T>;
		newNode->value = nValue;
		newNode->Next = NULL;
		if (isEmpty()) {
			Rear = newNode;
			Front = newNode;
		} else {
			newNode->Next = Rear->Next;
			Rear->Next = newNode;
			Rear = newNode;
		}
		noOfItems += 1;
	}
	bool dequeue(T &nValue) {
		if (isEmpty())
			return false;
		else {
			QNode<T> *temp;
			nValue = Front->value;
			temp = Front->Next;
			delete[] Front;
			Front = temp;
			noOfItems--;
			return true;
		}
	}
	QNode<T> * getRear() const {
		return Rear;
	}
	QNode<T> *getFront() const {
		return Front;
	}
	void displayQueue() {
		if (!isEmpty()) {
			QNode<T> *currentQueue = Front;
			while (currentQueue != NULL) {
				cout << currentQueue->value << " ";
				currentQueue = currentQueue->Next;
			}
		} else
			cout << "Queue is Empty" << endl;
	}
	void makeNull() {
		T value;
		while (!isEmpty())
			dequeue(value);
	}
	~Queue() {
		makeNull();
	}
};
